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


Lego* Lego::move(GLint x, GLint y, GLint z){
    vec3_flag temp={0,0,0,0};
    temp.x = x;
    temp.y = y;
    temp.z = z;
    temp.flag = 0;
    history.push(temp);
	return this;
}


Lego* Lego::rotate(int d){
	//rotate the cube
    vec3_flag temp={0,0,0,0};
    temp.x = 0;
    temp.y = 0;
    temp.z = 0;
    temp.flag = d;
    history.push(temp);
	return this;
}


Lego* Lego::setColor(RGB c){
	//
	color = c;
	return this;
}

Lego* Lego::reflash(){
    vec3_flag temp={0,0,0,0};
  

    //move&rotate with history stack
    glPushMatrix();
    if(history.isempty()==false)
    {
        history.pop(temp);
        
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        switch(temp.flag):
        case 0:
            glTranslatef (temp.x,temp.y,temp.z);
            break;
        case 1:
            glRotatef ((GLint)90, 0.0, 1.0, 0.0);
            break;
        case 2:
            glRotatef ((GLint)180, 0.0, 1.0, 0.0);
            break;
        case 3:
            glRotatef ((GLint)270, 0.0, 1.0, 0.0);
            break;
        default:
            break;
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    }
   draw();
   glPopMatrix();


	return this;
}
Lego* Lego::reset(){
    history.empty();
	return this;
}


Lego* Lego::draw(){

    //init cube coordinate  x*y*z
    typedef GLint vertex3[3];
    vertex3 points[8]={{0,0,0},{0,0,z},{x,0,z},{x,0,0},{0,y,0},{0,y,z},{x,y,z},{x,y,0}};

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
    gluQuadricDrawStyle( pipe, GLU_FILL ); 
	gluCylinder( pipe, 0.5, 0.5, 5, 15, 5 ); 
    /****************(unfinished)************/


    return this;
}

Lego::~Lego(){
	//deconstruct
}
