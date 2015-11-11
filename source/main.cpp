#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "constant.h"
#include "helpers.hpp"
#include "camera.h"
#include "draw.hpp"

using namespace std;
vec3 camera = {20,10,0};
vec3 center = {0,0,0};
vec3 up = {0,1,0};
GLfloat zNear = 0.1;
GLfloat zFar = 400;
int lastMouseX;
int lastMouseY;


vector<tinyobj::shape_t> LegoMan::shapes;
vector<tinyobj::material_t> LegoMan::materials;
GLuint LegoMan::Tid[30];


void displayHandler(){
	glClearColor(0.3f,0.3f,0.3f,0.2f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	drawXYZ();
	drawLMan(1);
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
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOV,(GLfloat)width/(GLfloat)height,zNear,zFar);
	//setCamera(camera,center,up,zNear,zFar);
	tinyLight();	
};
void idelHandler(){};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	setCamera(camera,center,up,zNear,zFar);
	objLoader(LegoMan::shapes,LegoMan::materials);
	getLegoManTexture(LegoMan::Tid);
	tinyLight();
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