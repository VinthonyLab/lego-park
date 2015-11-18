#pragma once
#ifndef _LEGO_MAN_
#define _LEGO_MAN_
#include <iostream>
#include <GL\glut.h>
#include <string>
#include <vector>
#include <map>
#include "tiny_obj_loader.h"
#include "constant.h"
#include "Lego.h"
#include "VecStack.hpp"



using namespace std;



const string cha[] = { "legocharacter1","legocharacter2","legocharacter3","legocharacter4" };

class LegoMan{
private:
	LEGOCHARACTER character;
	vec3 position;
	Stack<vec3> history;
	void drawLegoMan();
public:
	static vector<tinyobj::shape_t> shapes;
	static vector<tinyobj::material_t> materials;
	static GLuint Tid[30];
	static void Init();
	LegoMan(LEGOCHARACTER c);
	~LegoMan();
	LegoMan* move(vec3 v);
	LegoMan* rotate(vec3 v);
	LegoMan* reflash();
	LegoMan* reset();
};

#endif