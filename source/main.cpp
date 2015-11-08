#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "camera.h"
#include "loader.hpp"
#include "tiny_obj_loader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
using namespace std;

vec3 camera = {20,0,0};
vec3 center = {0,0,0};
vec3 up = {0,1,0};
GLfloat zNear = 0.1;
GLfloat zFar = 400;
int lastMouseX;
int lastMouseY;
string LEGO_MAN = "./lego_people_obj/lego_man.obj";
string BASE = "./lego_people_obj/";

vector<tinyobj::shape_t> shapes;
vector<tinyobj::material_t> materials;

bool objLoader(){
	string err = tinyobj::LoadObj(shapes,materials,LEGO_MAN.c_str(),BASE.c_str());	
	if(!err.empty()){
		cerr<< err << endl;
		//return false;
	}
	cout << "# of shapes	:" << shapes.size() << std::endl;
	cout << "# of materials :" << materials.size() << std::endl;
	
	return true;
}

void drawLegoMan(){
	map<int,unsigned char*> images;
	
	int imageWidth;
	int imageHeight;
	int pix;
	int lastTexture = -1;
	GLuint Tid[20];
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	GLfloat lightpos[] = {0.0, 1.0, 0.0, 0.0};
	GLfloat light_KA[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KD[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KS[] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_KA);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_KD);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_KS);
	glGenTextures(20,Tid);
	for(size_t x = 0; x < materials.size();x++){
			string Jname = BASE + materials[x].diffuse_texname; // filename
			unsigned char* data = stbi_load(Jname.c_str(),&imageWidth,&imageHeight,&pix,3);
			if(data!=nullptr){
				printf("load texure:(width:%d,height:%d,length:%d):%s\n",imageWidth,imageHeight,pix,Jname.c_str());
				 glBindTexture(GL_TEXTURE_2D,Tid[x]);	
				 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
				 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
				 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
				 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
				 glTexImage2D(GL_TEXTURE_2D,0,3,imageWidth,imageHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
			}
		}
	glEnable(GL_TEXTURE_2D);

	for (size_t i = 0; i < shapes.size(); i++) {
		vector<int> m_id = shapes[i].mesh.material_ids;
		vector<char32_t> indices = shapes[i].mesh.indices;
		vector<char32_t> normal_indices = shapes[i].mesh.normal_indices;
		vector<char32_t> texcoord_indices = shapes[i].mesh.texcoord_indices;
		vector<float> positions = shapes[i].mesh.positions;
		vector<float> normals = shapes[i].mesh.normals;
		vector<float> texture = shapes[i].mesh.texcoords;
		string name = shapes[i].name;
		//if(name != "legocharacter3") continue;
		
		for(size_t f = 0; f <indices.size()/3; f++){
			int mID = m_id[f];
			if(Tid[mID]){
				glBindTexture(GL_TEXTURE_2D,Tid[mID]);
				lastTexture = Tid[mID];
			}else{
				if(lastTexture != -1) 
					glBindTexture(GL_TEXTURE_2D,lastTexture);
			}
			glBegin(GL_TRIANGLES);
			for (size_t z = 0; z<3;z++){ // build a trangle
				int Vindex = indices[3*f+z]*3; //get the current Index of the vertex
				int Nindex = normal_indices[3*f+z]*3;
				int Tindex = texcoord_indices[3*f+z]*2;
				glNormal3f(
					normals[Vindex],
					normals[Vindex+1],
					normals[Vindex+2]
					);
				if(texture.size()/2 == indices.size()/3){
					glTexCoord2f(
							texture[Tindex],
							texture[Tindex+1]
							);
				}
				glVertex3f(
					positions[Nindex],
					positions[Nindex+1],
					positions[Nindex+2]
				);
				
				glMaterialf(GL_FRONT_AND_BACK,GL_AMBIENT,materials[mID].ambient[z]);
				glMaterialf(GL_FRONT_AND_BACK,GL_DIFFUSE,materials[mID].diffuse[z]);
				glMaterialf(GL_FRONT_AND_BACK,GL_EMISSION,materials[mID].emission[z]);
				glMaterialf(GL_FRONT_AND_BACK,GL_SPECULAR,materials[mID].specular[z]);
				glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,materials[mID].shininess);
				
				
			}
		}
		glEnd();
	}
	
}
void showXYZ(){
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0); //x
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(5,0.0,0.0);

		glColor3f(0.0,1.0,0.0); //y
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,5,0.0);

		glColor3f(0.0,0.0,1.0); //z
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,5);
	glEnd();
}

void displayHandler(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	
	showXYZ();
	drawLegoMan();
	glutSwapBuffers();
}
void keyboardEventHandler(unsigned char key,int x,int y){};
void mouseEventHandler(int x,int y){
		printf("current mouse position:%d,%d",x,y);
		if(x != lastMouseX){
			x < lastMouseX ? camera.x++ : camera.x--;
			lastMouseX = x;
		}
		if(y != lastMouseY){
			y < lastMouseY ? camera.y++ : camera.y--;
			lastMouseY = y;
		}
		setCamera(camera,center,up,zNear,zFar);
		glutPostRedisplay();
};

void reshapeHandler(int width,int height){

};
void idelHandler(){};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	setCamera(camera,center,up,zNear,zFar);
	objLoader();
}

int main(int argc,char * argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutCreateWindow("LEGO-PARK");
	
	init();

	glutDisplayFunc(&displayHandler);
	glutReshapeFunc(&reshapeHandler);
	glutKeyboardFunc(&keyboardEventHandler);
	glutIdleFunc(&idelHandler);
	//glutMotionFunc(&mouseEventHandler);
	glutMainLoop();

	return 0;
}