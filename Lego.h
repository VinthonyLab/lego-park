#pragma once

#include "camera.h"
#include "VecStack.h"

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
	void move(vec3 v);
	void rotate(vec3 v);
	void setColor(vec3 color);
	vec3 getColor();
	void reflash();
};

