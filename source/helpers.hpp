#include <iostream>
#include <string.h>
#include <GL\glut.h>

#include <vector>
#include "tiny_obj_loader.h"
#include "LegoMan.h"
string LEGO_MAN = "./lego_people_obj/lego_man.obj";
string BASE = "C:/Users/Nantu/Documents/GitHub/lego-park/lego_people_obj/";
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
using namespace std;

bool objLoader(vector<tinyobj::shape_t> &shapes,vector<tinyobj::material_t> &materials){
	string err = tinyobj::LoadObj(shapes,materials,LEGO_MAN.c_str(),BASE.c_str());	
	if(!err.empty()){
		cerr<< err << endl;
		return false;
	}
	return true;
}

void getLegoManTexture(GLuint Tid[]){
	int imageWidth;
	int imageHeight;
	int pix;
	glGenTextures(30,Tid);
	for(size_t x = 0; x < LegoMan::materials.size();x++){
		if(LegoMan::materials[x].diffuse_texname.empty()){
			Tid[x] = INT_MAX;
		}else{		
			string Jname = BASE + LegoMan::materials[x].diffuse_texname; // filename
			unsigned char* data = stbi_load(Jname.c_str(),&imageWidth,&imageHeight,&pix,3);
			glBindTexture(GL_TEXTURE_2D,Tid[x]);	
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
			glTexImage2D(GL_TEXTURE_2D,0,3,imageWidth,imageHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
		}
	}
}

void drawLMan(int character){
	LegoMan m(1);
	m.reflash();
}

void tinyLight(){
	GLfloat lightpos[] = {-10.0, 10.0, 0.0, 1.0};
	GLfloat light_KA[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KD[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KS[] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_KA);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_KD);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_KS);
}