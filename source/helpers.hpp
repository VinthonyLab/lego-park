#include <iostream>
#include <GL\glut.h>

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