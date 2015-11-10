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
	int size_x;
	int size_y;
	int size_z;
	vec3 color;
	vec3 position;
	Stack<vec3> history;
public:
	Lego(int x,int y,int z);
	~Lego(void);
	Lego* move(vec3 v);
	Lego* rotate(vec3 v);
	Lego* setColor(vec3 color);
	Lego* reset();
	vec3 getColor();
	Lego* reflash();
};

