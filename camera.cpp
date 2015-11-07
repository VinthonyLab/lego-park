#include "camera.h"

void setCamera(vec3 camera,vec3 center,vec3 up,GLfloat zNear,GLfloat zFar){
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float aspect = SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	gluPerspective(FOV,aspect,zNear,zFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.x,camera.y,camera.z,center.x,center.y,center.z,up.x,up.y,up.z);
}