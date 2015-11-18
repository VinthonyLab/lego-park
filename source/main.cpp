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


void draw_Base()
{
	Lego ground = Lego(32.0, 0, 32.0);
	ground.setColor({ 0.50,0.50,0.50 });
	ground.reflash();

	Lego lawn = Lego(8.0, 1, 25.0);
	lawn.setColor({ 0.14,0.59,0.14 });
	lawn.move({ 2, 0, 5 });
	lawn.reflash();


	Lego pool = Lego(6.0, 2, 6.0);
	pool.setColor({ 0,0.75,1.00 });
	pool.move({ 23, 0, 22 });
	pool.reflash();

	Lego pool1 = Lego(8.0, 2, 1.0);
	pool1.setColor({ 0.41,0.41,0.41 });
	pool1.move({ 22, 0, 21 });
	pool1.reflash();

	Lego pool2 = Lego(8.0, 2, 1.0);
	pool2.setColor({ 0.41,0.41,0.41 });
	pool2.move({ 22, 0, 28 });
	pool2.reflash();

	Lego pool3 = Lego(1.0, 2, 6.0);
	pool3.setColor({ 0.41,0.41,0.41 });
	pool3.move({ 22, 0, 22 });
	pool3.reflash();

	Lego pool4 = Lego(1.0, 2, 6.0);
	pool4.setColor({ 0.41,0.41,0.41 });
	pool4.move({ 29, 0, 22 });
	pool4.reflash();

	Lego pool5 = Lego(2.0, 6, 2.0);
	pool5.setColor({ 0.41,0.41,0.41 });
	pool5.move({ 25, 0, 24 });
	pool5.reflash();

}



void draw_UM()
{
	Lego U1 = Lego(2.0, 7, 2.0);
	U1.setColor({ 0.8,0.6,0.00 });
	U1.move({ 2, 0, 0 });
	U1.reflash();

	Lego U2 = Lego(2.0, 7, 2.0);
	U2.setColor({ 0.8,0.6,0.00 });
	U2.move({ 9, 0, 0 });
	U2.reflash();

	Lego U3 = Lego(6.0, 2.0, 2.0);
	U3.setColor({ 0.8,0.6,0.00 });
	U3.move({ 3, 0, 0 });
	U3.reflash();


	Lego M1 = Lego(2.0, 7, 2.0);
	M1.setColor({ 0.8,0.2,0.00 });
	M1.move({ 22, 0, 0 });
	M1.reflash();

	Lego M2 = Lego(2.0, 7, 2.0);
	M2.setColor({ 0.8,0.2,0.00 });
	M2.move({ 28, 0, 0 });
	M2.reflash();

	Lego M3 = Lego(1.0, 3, 2.0);
	M3.setColor({ 0.8,0.2,0.00 });
	M3.move({ 24, 4, 0 });
	M3.reflash();

	Lego M4 = Lego(1.0, 3, 2.0);
	M4.setColor({ 0.8,0.2,0.00 });
	M4.move({ 27, 4, 0 });
	M4.reflash();

	Lego M5 = Lego(2.0, 2, 2.0);
	M5.setColor({ 0.8,0.2,0.00 });
	M5.move({ 25, 3, 0 });
	M5.reflash();
}




void displayHandler(){
	glClearColor(0.3f,0.3f,0.3f,0.2f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	drawXYZ();
	draw_Base();
	draw_UM();
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