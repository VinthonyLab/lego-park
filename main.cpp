
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>

#include "constant.h"
#include "camera.h"

using namespace std;

void showXYZ(){
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0); //x
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.5,0.0,0.0);

		glColor3f(0.0,1.0,0.0); //y
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);

		glColor3f(0.0,0.0,1.0); //z
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.5);
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

void idelHandler(){};

void init(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	setCamera();
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

	glutMainLoop();

	return 0;
}