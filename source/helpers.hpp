#include <iostream>
#include <GL\glut.h>
#include <math.h>
void tinyLight(int time){
	GLfloat lightpos[] = { 10.0, 10.0, 0.0, 1.0 };
	GLfloat light_KA[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_KD[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_KS[] = { 1.0,1.0,1.0,1.0 };

	//float lpx = 30 * abs(cosf(time));
	//float lpy = 30 * abs(sinf(time));
	//lightpos[0] = lpx;
	//lightpos[1] = lpy;
	/*
	if (time % 360 > 180) {
		// night 
		light_KS[0] = 0.0;
		light_KS[1] = 0.0;
		light_KS[2] = 0.0;
		light_KS[3] = 0.0;
	}
	else {
		
	}
	*/
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_KA);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_KD);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_KS);
}