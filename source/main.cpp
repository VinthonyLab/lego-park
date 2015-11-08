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
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	GLfloat lightpos[] = {.5, 1., 1., 0.};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	for (size_t i = 0; i < shapes.size(); i++) {
		vector<int> m_id = shapes[i].mesh.material_ids;
		vector<char32_t> indices = shapes[i].mesh.indices;
		vector<float> positions = shapes[i].mesh.positions;
		vector<float> normals = shapes[i].mesh.normals;
		vector<float> texture = shapes[i].mesh.texcoords;
		string name = shapes[i].name;
		int imageWidth;
		int imageHeight;
		int pix;
		GLuint Tid;
		if(name != "legocharacter1") continue;
		glBegin(GL_TRIANGLES);
		for(size_t f = 0; f <indices.size()/3; f++){
			string Jname = BASE + materials[m_id[f]].diffuse_texname;
			unsigned char* data = stbi_load(Jname.c_str(),&imageWidth,&imageHeight,&pix,0);
			if(data){
				glGenTextures(1,&Tid);
				glBindTexture(GL_TEXTURE_2D,Tid);	
				glTexImage2D(GL_TEXTURE_2D,0,3,imageWidth,imageHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
			}
			for (size_t z = 0; z<3;z++){ // build a trangle
				int index = indices[3*f+z]*3; //get the current Index of the vertex
				glNormal3f(
					normals[index],
					normals[index+1],
					normals[index+2]
					);
				glVertex3f(
					positions[index],
					positions[index+1],
					positions[index+2]
				);
				glMaterialf(GL_FRONT,GL_AMBIENT,materials[m_id[f]].ambient[z]);
				glMaterialf(GL_FRONT,GL_DIFFUSE,materials[m_id[f]].diffuse[z]);
				glMaterialf(GL_FRONT,GL_EMISSION,materials[m_id[f]].emission[z]);
				glMaterialf(GL_FRONT,GL_SPECULAR,materials[m_id[f]].specular[z]);
				glMaterialf(GL_FRONT,GL_SHININESS,materials[m_id[f]].shininess);
				//glTexCoord2f(texture[2*f],texture[2*f+1]);
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
	glEnable(GL_TEXTURE_2D);
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
	glutMotionFunc(&mouseEventHandler);
	glutMainLoop();

	return 0;
}