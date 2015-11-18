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



void draw_Groud()
{
	Lego ground1 = Lego(12.0, 0, 32.0);
	ground1.setColor({ 0.00,0.40,0.00 });
	ground1.reflash();

	Lego ground2 = Lego(12.0, 0, 32.0);
	ground2.setColor({ 0.00,0.40,0.00 });
	ground2.move({ 20, 0, 0 });
	ground2.reflash();
}

void draw_River()
{
	

	Lego river = Lego(8.0, 0, 32.0);
	river.setColor({ 0,0.75,1.00 });
	river.move({ 12, 0, 0 });
	river.reflash();

	Lego bridge1 = Lego(1.0, 1, 6.0);
	bridge1.setColor({ 0.55,0.14,0.00 });
	bridge1.move({ 9, 0, 13 });
	bridge1.reflash();

	Lego bridge2 = Lego(1.0, 1, 6.0);
	bridge2.setColor({ 0.55,0.14,0.00 });
	bridge2.move({ 22, 0, 13 });
	bridge2.reflash();

	Lego bridge3 = Lego(1.0, 2, 6.0);
	bridge3.setColor({ 0.55,0.14,0.00 });
	bridge3.move({ 10, 0, 13 });
	bridge3.reflash();

	Lego bridge4 = Lego(1.0, 2, 6.0);
	bridge4.setColor({ 0.55,0.14,0.00 });
	bridge4.move({ 21, 0, 13 });
	bridge4.reflash();

	Lego bridge5 = Lego(1.0, 3, 6.0);
	bridge5.setColor({ 0.55,0.14,0.00 });
	bridge5.move({ 11, 0, 13 });
	bridge5.reflash();

	Lego bridge6 = Lego(1.0, 3, 6.0);
	bridge6.setColor({ 0.55,0.14,0.00 });
	bridge6.move({ 20, 0, 13 });
	bridge6.reflash();


	Lego bridge7 = Lego(8.0, 1, 6.0);
	bridge7.setColor({ 0.55,0.14,0.00 });
	bridge7.move({ 12, 3, 13 });
	bridge7.reflash();


}

void draw_Pool()
{
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


void draw_Rock(float x,float z)
{
	Lego rock = Lego(2.0, 2, 3.0);
	rock.setColor({ 0.21,0.21,0.21 });
	rock.move({ x, 0, z });
	rock.reflash();
}
void draw_Tree( float x, float z)
{
	Lego tree1 = Lego(2.0, 4, 2.0);
	tree1.setColor({ 0.4,0.3,0.00 });
	tree1.move({ x, 0, z });
	tree1.reflash();


	Lego tree2 = Lego(6.0, 2, 6.0);
	tree2.setColor({ 1.00,0.41,0.71 });
	tree2.move({ x-2, 4, z-2 });
	tree2.reflash();

	Lego tree3 = Lego(4.0, 2, 4.0);
	tree3.setColor({ 1.00,0.41,0.71 });
	tree3.move({ x - 1, 6, z - 1 });
	tree3.reflash();

	Lego tree4 = Lego(2.0, 2, 2.0);
	tree4.setColor({ 1.00,0.41,0.71 });
	tree4.move({ x, 8, z });
	tree4.reflash();

}


void draw_Park()
{
	draw_Groud();
	draw_Pool();
	draw_River();
	draw_UM();

	draw_Tree(8, 26);

}

#endif