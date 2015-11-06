#pragma once
#include <GL\glut.h>

struct vec3{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

void setCamera(vec3 camera,vec3 center,vec3 up,GLfloat zNear,GLfloat zFar);
