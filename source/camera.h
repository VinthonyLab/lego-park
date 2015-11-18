#pragma once
#include <iostream>

#include <GL\GLUT.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "constant.h"

// could using the singleton design to make the code stronger.

class Camera
{
public:
	Camera();
	~Camera();
	void setLookAtCamera(vec3 v);
	void setLookAtCenter(vec3 v);
	void setLookAtUp(vec3 v);
	void setPerspectiveFOV(GLint fov);
	void setPerspectiveAspect(GLdouble aspect);
	void setPerspectiveZNear(GLdouble znear);
	void setPerspectiveZFar(GLdouble zfar);
	void setPerspective(GLint fov,GLdouble aspect,GLdouble znear,GLdouble zfar);
	void setLookAt(vec3 v, vec3 x, vec3 m);
	vec3 getCameraPosition();
	void Init();
private:
	vec3 _camera;
	vec3 _center;
	vec3 _up;
	GLdouble _aspect;
	GLdouble _zNear;
	GLdouble _zFar;
	GLint _fov;
	void _draw();
};
