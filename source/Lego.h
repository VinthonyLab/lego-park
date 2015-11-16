#pragma once

#include "constant.h"
//wired problem£¬ can't find source file of VecStack.h, could fixed
// it with include vecstack.cpp
// maybe it's because i recreate this two file.
// but i using .hpp to hybrid the .h and .cpp to avoid this problem.
#include "VecStack.h"

class Lego
{
private:
	int size_x=0;
	int size_y=0;
	int size_z=0;
	RGB color={1.0,0.0,0.0};
	Stack<vec3_flag> history;
public:
	Lego(int x,int y,int z);
	~Lego(void);
	Lego* move(GLint x, GLint y, GLint z);
	Lego* rotate(int d);
	Lego* setColor(RGB c);
	Lego* reset();
	Lego* reflash();
};

