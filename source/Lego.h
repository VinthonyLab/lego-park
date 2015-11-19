#pragma once

#include "constant.h"
//wired problem£¬ can't find source file of VecStack.h, could fixed
// it with include vecstack.cpp
// maybe it's because i recreate this two file.
// but i using .hpp to hybrid the .h and .cpp to avoid this problem.
#include "VecStack.hpp"

class Lego
{
private:
    //cube size
	int size_x=0;
	int size_y=0;
	int size_z=0;
    //cube color
	RGB color={1.0,0.0,0.0};
    //cube current position&rotate state
	vec3 position={0,0,0};
    int rotate_flag=0;
    //record operation
    Stack<vec3_flag> history;
	int type = 0;
public:
	Lego(float x,float y,float z);
	Lego(float x,float z);
	~Lego(void);
	
    Lego* move(vec3 v);
	Lego* rotate(int degree_flag);
	
    Lego* setColor(RGB c);
    RGB getColor();
	
    Lego* reset();
	Lego* reflash();
	Lego* draw();
};

