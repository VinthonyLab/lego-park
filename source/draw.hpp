#include <GL\glut.h>

#ifndef _DRAW_FUNCTIONS_
#define _DRAW_FUNCTIONS_
void drawXYZ(){
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
	glColor3f(1.0,1.0,1.0);
}
#endif