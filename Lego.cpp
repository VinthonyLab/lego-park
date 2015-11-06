#include "Lego.h"
//wired problem£¬ can't find source file of VecStack.h, could fixed
// it with include vecstack.cpp
#include "VecStack.cpp"

Lego::Lego(int x,int y,int z)
{
	// using a stack to store all the movement we apply on the lego
	size_x = x;
	size_y = y;
	size_z = z;
	// generator the lego cube here
}

void Lego::move(vec3 v){
	position = v;
	//translate the position of lego cube
}
void Lego::rotate(vec3 v){
	//rotate the cube
}
void Lego::setColor(vec3 c){
	//
	color = c;
}
vec3 Lego::getColor(){
	// get the color

	return color;
}
void Lego::reflash(){
	// reflash the new position and translation of lego

}

Lego::~Lego(){
	//deconstruct
}