#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>

#include "constant.h"

void setCamera(vec3 camera,vec3 center,vec3 up,GLfloat zNear,GLfloat zFar);
