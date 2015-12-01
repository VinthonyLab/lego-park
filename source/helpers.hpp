#include <iostream>
#include <GL\glut.h>
#include <math.h>

using namespace std;

void tinyLight(int time){
	if (time % 360 > 180) time = time + 180;

	GLfloat lightpos[] = { 30.0, 0.0, -5.0, 0.0 };
	GLfloat light_KA[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_KD[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_KS[] = { 1.0,1.0,1.0,1.0 };
	double pi = acos(-1);
	float lpx = 30 * cosf( (time % 360)/ (float)360 * 2 * pi);
	float lpy = 30 * sinf( (time % 360) / (float)360 * 2 * pi);
	lightpos[0] = lpx;
	lightpos[1] = lpy;
	
	if (time % 360 > 180) {
		// night 
		light_KS[0] = 0.3;
		light_KS[1] = 0.3;
		light_KS[2] = 0.3;
		light_KS[3] = 0.3;
		light_KD[0] = 0.3;
		light_KD[1] = 0.3;
		light_KD[2] = 0.3;
		light_KD[3] = 0.3;
		light_KA[0] = 0.3;
		light_KA[1] = 0.3;
		light_KA[2] = 0.3;
		light_KA[3] = 0.3;
	}
	else {
		
	}
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_KA);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_KD);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_KS);
}
