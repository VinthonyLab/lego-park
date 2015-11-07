#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>

#include "camera.h"

using namespace std;

vec3 camera = {20,10,5};
vec3 center = {0,0,0};
vec3 up = {0,1,0};
GLfloat zNear = 0.1;
GLfloat zFar = 100;
int lastMouseX;
int lastMouseY;
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

	glutSwapBuffers();
}

void reshapeHandler(int width,int height){};

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
void idelHandler(){};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	
	setCamera(camera,center,up,zNear,zFar);
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