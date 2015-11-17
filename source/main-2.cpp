#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "constant.h"
#include "camera.h"
#include "Lego.h"
#include "draw.h"

using namespace std;
vec3 camera = { 20,10,0 };
vec3 center = { 0,0,0 };
vec3 up = { 0,1,0 };
GLfloat zNear = 0.1;
GLfloat zFar = 400;
int lastMouseX;
int lastMouseY;


void displayHandler() {
	glClearColor(0.3f, 0.3f, 0.3f, 0.2f);
	
	
	Lego a = Lego(2, 1, 2);
	a.setColor({ 0.00,1.00,1.00 });
	a.move({ 1, 0, 4 });
	Lego b = Lego(2, 1, 2);
	b.setColor({ 1.00,0.00,1.00 });
	b.move({ 1,1,4 });
	
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	drawXYZ();
	a.reflash();
	b.reflash();

	glutSwapBuffers();
}


void mouseEventHandler(int x, int y) {
	printf("current mouse position:%d,%d", x, y);
	if (x != lastMouseX) {
		x < lastMouseX ? camera.x++ : camera.x--;
		lastMouseX = x;
	}
	if (y != lastMouseY) {
		y < lastMouseY ? camera.y++ : camera.y--;
		lastMouseY = y;
	}
	setCamera(camera, center, up, zNear, zFar);
	glutPostRedisplay();
};



void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	setCamera(camera, center, up, zNear, zFar);
	

}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("LEGO-PARK");

	init();
	glutDisplayFunc(&displayHandler);
	glutMotionFunc(&mouseEventHandler);
	glutMainLoop();

	int a;
	cin >> a;
	return 0;
}