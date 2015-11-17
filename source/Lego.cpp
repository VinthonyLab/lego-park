#include "Lego.h"

void quad(GLint n1,GLint n2,GLint n3,GLint n4,vertex3 *P)
{
	glBegin(GL_QUADS);
	 glVertex3iv(P[n1]);
	 glVertex3iv(P[n2]);
	 glVertex3iv(P[n3]);
	 glVertex3iv(P[n4]);
    glEnd();

}

Lego::Lego(int x,int y,int z)
{
	// using a stack to store all the movement we apply on the lego
	size_x = x;
	size_y = y;
	size_z = z;
   
    //reflash();
}


Lego* Lego::move(vec3){
    vec3_flag temp={0,0,0,0};
    temp.vector.x = vec3.x;
    temp.vector.y = vec3.y;
    temp.vector.z = vec3.z;
    temp.flag = 0;
    history.push(temp);
	return this;
}


Lego* Lego::rotate(int degree_flag){
	//rotate the cube
    vec3_flag temp={0,0,0,0};
    temp.vector.x = 0;
    temp.vector.y = 0;
    temp.vector.z = 0;
    temp.flag = degree_flag;
    history.push(temp);
	return this;
}


Lego* Lego::setColor(RGB c){
	//
	color = c;
	return this;
}
RGB Lego::getColor(){
	// get the color
	return color;
}


Lego* Lego::reflash(){
    vec3_flag temp={0,0,0,0};
    vec3 move={0,0,0};
    int rotate=0;

    //move&rotate with history stack
    if(history.isempty()==false)
    {
        history.pop(temp);
        switch(temp.flag):
        case 0:
            move.x = move.x + temp.vector.x;
            move.y = move.y + temp.vector.y;
            move.z = move.z + temp.vector.z;
            break;
        case 1:
            rotate = rotate + temp.flag;
            break;
        case 2:
            rotate = rotate + temp.flag;
            break;
        case 3:
            rotate = rotate + temp.flag;
            break;
        default:
            break;
    }

    //update position & rotate_flag
    position.x = position.x + move.x;
    position.y = position.x + move.y;
    position.z = position.x + move.z;
    rotate_flag = (rotate_flag + rotate) % 4;

    //draw cube & transformation
    glPushMatrix();
    glTranslatef (position);

    glTranslatef ( x/2, 0, x/2);
    glRotatef (rotate_flag * 90, 0.0, 1.0, 0.0);
    glTranslatef ( -x/2, 0, -z/2);
    draw();
    glPopMatrix();


	return this;
}
Lego* Lego::reset(){
    history.empty();
    position = {0,0,0};
	rotate_flag=0;
    return this;
}


Lego* Lego::draw(){

    //init cube coordinate  x*y*z
    typedef GLint vertex3[3];
    vertex3 points[8]={{ 0, 0, 0},{ 0, 0, z},{ x, 0, z},{ x, 0, 0},{ 0, y, 0},{ 0, y, z},{ x, y, z},{ x, y, 0}};

    //draw cube
    glColor3f(color);
	    quad(0,1,2,3,points);
	    quad(4,5,6,7,points);
        quad(1,5,6,2,points);
	    quad(0,4,7,3,points);
	    quad(0,1,5,4,points);
	    quad(3,2,6,7,points);
    
        
    /****************(unfinished)************/
    //draw small cylinder	GLUquadricObj* pipe = gluNewQuadric();
    //gluQuadricDrawStyle( pipe, GLU_FILL ); 
	//gluCylinder( pipe, 0.5, 0.5, 5, 15, 5 ); 
    /****************(unfinished)************/

    return this;
}

Lego::~Lego(){
	//deconstruct
}
