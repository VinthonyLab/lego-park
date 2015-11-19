#include <GL\glut.h>

#ifndef _DRAW_FUNCTIONS_
#define _DRAW_FUNCTIONS_
void drawXYZ(){
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0); //x_r
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(5,0.0,0.0);

		glColor3f(0.0,1.0,0.0); //y_g
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,5,0.0);

		glColor3f(0.0,0.0,1.0); //z_b
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,5);
	glEnd();
		glColor3f(1.0,1.0,1.0);
		glDisable(GL_COLOR_MATERIAL);
}
void draw_Groud()
{
	RGB lawn = { 0.012,0.51,0.17 };
	
	Lego ground1 = Lego(12.0, 0, 32.0);
	ground1.setColor(lawn);
	ground1.reflash();

	Lego ground2 = Lego(12.0, 0, 32.0);
	ground2.setColor(lawn);
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
	RGB water = { 0,0.75,1.00 };
	RGB fountain = { 0.41,0.41,0.41 };

	Lego pool = Lego(6.0,2, 6.0);
	pool.setColor(water);
	pool.move({ 23, 0, 22 });
	pool.reflash();

	Lego pool1 = Lego(8.0, 2, 1.0);
	pool1.setColor(fountain);
	pool1.move({ 22, 0, 21 });
	pool1.reflash();

	Lego pool2 = Lego(8.0, 2, 1.0);
	pool2.setColor(fountain);
	pool2.move({ 22, 0, 28 });
	pool2.reflash();

	Lego pool3 = Lego(1.0, 2, 6.0);
	pool3.setColor(fountain);
	pool3.move({ 22, 0, 22 });
	pool3.reflash();

	Lego pool4 = Lego(1.0, 2, 6.0);
	pool4.setColor(fountain);
	pool4.move({ 29, 0, 22 });
	pool4.reflash();

	Lego pool5 = Lego(2.0, 6, 2.0);
	pool5.setColor(fountain);
	pool5.move({ 25, 0, 24 });
	pool5.reflash();
}



void draw_UM()
{
	RGB M = { 0.8,0.6,0.00 };
	RGB U = { 0.8,0.2,0.00 };

	Lego U1 = Lego(2.0, 7, 2.0);
	U1.setColor(U);
	U1.move({ 2, 0, 0 });
	U1.reflash();

	Lego U2 = Lego(2.0, 7, 2.0);
	U2.setColor(U);
	U2.move({ 9, 0, 0 });
	U2.reflash();

	Lego U3 = Lego(6.0, 2.0, 2.0);
	U3.setColor(U);
	U3.move({ 3, 0, 0 });
	U3.reflash();


	Lego M1 = Lego(2.0, 7, 2.0);
	M1.setColor(M);
	M1.move({ 22, 0, 0 });
	M1.reflash();

	Lego M2 = Lego(2.0, 7, 2.0);
	M2.setColor(M);
	M2.move({ 28, 0, 0 });
	M2.reflash();

	Lego M3 = Lego(1.0, 3, 2.0);
	M3.setColor(M);
	M3.move({ 24, 4, 0 });
	M3.reflash();

	Lego M4 = Lego(1.0, 3, 2.0);
	M4.setColor(M);
	M4.move({ 27, 4, 0 });
	M4.reflash();

	Lego M5 = Lego(2.0, 2, 2.0);
	M5.setColor(M);
	M5.move({ 25, 3, 0 });
	M5.reflash();
}


void draw_Bench()
{
	//RGB part1 = { 0.00,0.00,0.8 };
	RGB part1 = { 0.796,0.25,0.26 };

	Lego Bench1 = Lego(1.0, 1, 1.0);
	Bench1.setColor(part1);
	Bench1.move({ 21, 0, 4 });
	Bench1.reflash();
	Lego Bench2 = Lego(1.0, 1, 1.0);
	Bench2.setColor(part1);
	Bench2.move({ 23, 0, 4 });
	Bench2.reflash();
	Lego Bench3 = Lego(1.0, 1, 1.0);
	Bench3.setColor(part1);
	Bench3.move({ 21, 0, 9 });
	Bench3.reflash();
	Lego Bench4 = Lego(1.0, 1, 1.0);
	Bench4.setColor(part1);
	Bench4.move({ 23, 0, 9 });
	Bench4.reflash();

	Lego Bench5 = Lego(3.0,1,6.0);
	Bench5.setColor(part1);
	Bench5.move({ 21, 1, 4 });
	Bench5.reflash();

	Lego Bench6 = Lego(1.0, 3, 6.0);
	Bench6.setColor(part1);
	Bench6.move({ 21, 1, 4 });
	Bench6.reflash();


}



void draw_Tree( float x, float z)
{
	RGB sakura = { 0.796,0.25,0.26 };
	RGB wood = { 0.88,0.65,0.48 };

	Lego tree1 = Lego(2.0, 4, 2.0);
	tree1.setColor(wood);
	tree1.move({ x, 0, z });
	tree1.reflash();

	Lego tree2 = Lego(6.0, 2, 6.0);
	//tree2.setColor({ 1.00,0.41,0.71 });
	tree2.setColor(sakura);
	tree2.move({ x-2, 4, z-2 });
	tree2.reflash();

	Lego tree3 = Lego(4.0, 2, 4.0);
	tree3.setColor(sakura);
	tree3.move({ x - 1, 6, z - 1 });
	tree3.reflash();

	Lego tree4 = Lego(2.0, 2, 2.0);
	tree4.setColor(sakura);
	tree4.move({ x, 8, z });
	tree4.reflash();

}

void draw_npc() {
	LegoMan npc1 = LegoMan(LEGO2);
	npc1.move({5,0,10});
	npc1.reflash();

	LegoMan npc2 = LegoMan(LEGO3);
	npc2.move({ 5,0,20 });
	npc2.reflash();
}

void drawSUN(int currentTime) {
	glPushMatrix();
	if (currentTime % 360 > 180 ) {
		//night
		glColor3f(0.855, 0.788, 0.651);
		glRotatef(currentTime+180, 0, 0, 1);
	}else{
		//day
		glColor3f(0.922, 0.478, 0.47);
		glRotatef(currentTime, 0, 0, 1);
	}
	glTranslatef(30, 0, -5);
	glutSolidSphere(2, 20, 20);
	glPopMatrix();
}

void draw_Park()
{
	draw_Groud();
	draw_Pool();
	draw_River();
	draw_UM();
	draw_Tree(4, 26);
	draw_Bench();
}

#endif