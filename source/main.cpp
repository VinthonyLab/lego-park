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
float LegoManX=0;
float LegoManY=0;
float LegoManZ=0;
float npcZ = 5;
enum DIRECTIONS
{
	FRONT,
	LEFT, // rotate 90
	BACK, // rotate 180
	RIGHT// rotate 270
};
int direction = LEFT;
int LegoManRotate = -1;
int npcRotate = 3;
int sun_time = 1;

void displayHandler(){
	if (sun_time % 360 >180) {
		glClearColor(0.4f, 0.4f, 0.4f, 0.4f);
	}else{
		glClearColor(0.9f, 0.9f, 0.9f, 0.9f);
	}
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	drawXYZ();
	draw_Park();
	draw_npc();
	//draw ai
	LegoMan ai = LegoMan(LEGO1);
	ai.rotate(npcRotate);
	ai.move({ 30,0,npcZ});
	ai.reflash();

	drawSUN(sun_time);
	tinyLight(sun_time);
	glutSwapBuffers();
}
void keyboardEventHandler(unsigned char key,int x,int y){
	switch (key)
	{
	case 'w':
		switch (direction)
		{
		case FRONT:
			LegoManX++;
			direction = FRONT;
			break;
		case BACK:
			LegoManX--;
			direction = BACK;
			break;
		case LEFT:
			LegoManZ++;
			direction = LEFT;
			break;
		case RIGHT:
			LegoManZ--;
			direction = RIGHT;
			break;
		default:
			break;
		}
		break;
	case 's':
		switch (direction)
		{
		case FRONT:
			LegoManX--;
			direction = BACK;
			break;
		case BACK:
			LegoManRotate = 2;
			LegoManX++;
			direction = FRONT;
			break;
		case LEFT:
			LegoManRotate = 1;
			direction = RIGHT;
			LegoManZ--;
			break;
		case RIGHT:
			LegoManRotate = 3;
			direction = LEFT;
			LegoManZ++;
		default:
			break;
		}
		break;
	case 'a':
		switch (direction)
		{
		case FRONT:
			LegoManRotate = 1;
			LegoManZ--;
			direction = LEFT;
			break;
		case BACK:
			LegoManRotate = 3;
			direction = RIGHT;
			LegoManZ++;
			break;
		case LEFT:
			LegoManRotate = 2;
			direction = BACK;
			LegoManX--;
			break;
		case RIGHT:
			direction = FRONT;
			LegoManX++;
		default:
			break;
		}
		break;
	case 'd':
		switch (direction)
		{
		case FRONT:
			LegoManRotate = 3;
			LegoManZ++;
			direction = RIGHT;
			break;
		case BACK:
			LegoManRotate = 1;
			LegoManZ--;
			direction = LEFT;
			break;
		case LEFT:
			LegoManX++;
			direction = FRONT;
			break;
		case RIGHT:
			direction = BACK;
			LegoManRotate = 2;
			LegoManX--;
		default:
			break;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
};
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
};
void idelHandler(){
	sun_time++;
	if (npcZ < 20 && npcRotate == 3) {
		npcZ += 0.5;
	}
	else {
		npcRotate = 1;
	}
	if (npcZ > 5 && npcRotate == 1){
		npcZ -= 0.5;
	}
	else {
		npcRotate = 3;
	}
	glutPostRedisplay();
};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	camera.Init();
	LegoMan::Init();
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