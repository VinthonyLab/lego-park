#include "Lego.h"
#include "gl/glut.h"

typedef GLint vertex3[3];
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


Lego* Lego::move(vec3 v){
    vec3_flag temp={0,0,0,0};
    temp.vector.x = v.x;
    temp.vector.y = v.y;
    temp.vector.z = v.z;
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
		switch (temp.flag) {
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
    }

    //update position & rotate_flag
    position.x = position.x + move.x;
    position.y = position.x + move.y;
    position.z = position.x + move.z;
    rotate_flag = (rotate_flag + rotate) % 4;

    //draw cube & transformation
    glPushMatrix();
    glTranslatef ( position.x, position.y, position.z);

    glTranslatef ( size_x/2, 0, size_z/2);
    glRotatef (rotate_flag * 90, 0.0, 1.0, 0.0);
    glTranslatef ( -size_x/2, 0, -size_z/2);
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
   
    vertex3 points[8]={{ 0, 0, 0},{ 0, 0, size_z},{ size_x, 0, size_z},{ size_x, 0, 0},
                       { 0, size_y, 0},{ 0, size_y, size_z},{ size_x, size_y, size_z},{ size_x, size_y, 0}};

    //draw cube
    glColor3f( color.R, color.G, color.B);
	    quad(0,1,2,3,points);
	    quad(4,5,6,7,points);
        quad(1,5,6,2,points);
	    quad(0,4,7,3,points);
	    quad(0,1,5,4,points);
	    quad(3,2,6,7,points);
    
        
    
    //draw small cylinder
   
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_z;j++){
			GLUquadricObj* pipe = gluNewQuadric();
            gluQuadricDrawStyle( pipe, GLU_FILL );
        
            glPushMatrix();
	        glTranslatef (0.5 + i, size_y+0.5 , 0.5 + j);
            glRotatef (90, 1.0, 0.0, 0.0);
	        gluCylinder( pipe, 0.4, 0.4, 0.4, 15, 5 );
            glPopMatrix();
        }
    }
    return this;
}

Lego::~Lego(){
	//deconstruct
}

