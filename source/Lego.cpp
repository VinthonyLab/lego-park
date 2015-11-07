#include "Lego.h"



Lego::Lego(int x,int y,int z)
{
	// using a stack to store all the movement we apply on the lego
	size_x = x;
	size_y = y;
	size_z = z;
	// generator the lego cube here
}

Lego* Lego::move(vec3 v){
	position = v;
	//translate the position of lego cube
	return this;
}
Lego* Lego::rotate(vec3 v){
	//rotate the cube
	return this;
}
Lego* Lego::setColor(vec3 c){
	//
	color = c;
	return this;
}
vec3 Lego::getColor(){
	// get the color

	return color;
}
Lego* Lego::reflash(){
	// reflash the new position and translation of lego
	return this;
}

Lego::~Lego(){
	//deconstruct
}