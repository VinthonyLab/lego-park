#include <GL\glut.h>

#ifndef _DRAW_FUNCTIONS_
#define _DRAW_FUNCTIONS_
void drawXYZ(){
	glEnable(GL_COLOR_MATERIAL);
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
		glDisable(GL_COLOR_MATERIAL);
}



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


#endif