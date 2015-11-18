#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "constant.h"
#include "helpers.hpp"
#include "LegoMan.h"
#include "camera.h"
#include "draw.hpp"

using namespace std;
Camera camera;
vector<tinyobj::shape_t> LegoMan::shapes;
vector<tinyobj::material_t> LegoMan::materials;
GLuint LegoMan::Tid[30];
int lastMouseX;
int lastMouseY;






void displayHandler(){
	glClearColor(0.3f,0.3f,0.3f,0.2f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	drawXYZ();
	draw_Park();
	glutSwapBuffers();
}
void keyboardEventHandler(unsigned char key,int x,int y){};
void mouseEventHandler(int x,int y){
	 vec3 _c = camera.getCameraPosition();
		if(x != lastMouseX){
			x < lastMouseX ? _c.x++ : _c.x--;
			lastMouseX = x;
		}
		if(y != lastMouseY){
			y < lastMouseY ? _c.y++ : _c.y--;
			lastMouseY = y;
		}
		camera.setLookAtCamera(_c);
		glutPostRedisplay();
};

void reshapeHandler(int width,int height){
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	camera.setPerspectiveAspect(width / (GLdouble)height);
	tinyLight();	
};
void idelHandler(){};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	camera.Init();
	LegoMan::Init();
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
	glutMotionFunc(&mouseEventHandler);
	glutMainLoop();

	return 0;
}