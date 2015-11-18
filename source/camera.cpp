#include "camera.h"


Camera::Camera()
{
	_aspect = SCREEN_WIDTH / (GLdouble)SCREEN_HEIGHT;
	_camera = { 20.0,10.0,0.0 };
	_center = { 0, 0, 0 };
	_up = { 0 , 1 , 0 };
	_fov = FOV;
	_zNear = 0.1;
	_zFar = 100;
	_draw();
}

Camera::~Camera()
{
}
void Camera::Init() {
	_draw();
}
void Camera::_draw() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fov, _aspect, _zNear, _zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(_camera.x, _camera.y, _camera.z, _center.x, _center.y, _center.z, _up.x, _up.y, _up.z);
}
void Camera::setLookAt(vec3 camera, vec3 center, vec3 up)
{
	_camera = camera;
	_center = center;
	_up = up;
	_draw();
}

void Camera::setLookAtCamera(vec3 camera)
{
	_camera = camera;
	_draw();
}
void Camera::setLookAtCenter(vec3 v) {
	_center = v;
	_draw();
}

void Camera::setLookAtUp(vec3 v) {
	_up = v;
	_draw();
}

void Camera::setPerspectiveFOV(GLint fov) {
	_fov = fov;
	_draw();
}
void Camera::setPerspectiveAspect(GLdouble aspect) {
	_aspect = aspect;
	_draw();
}
void Camera::setPerspectiveZNear(GLdouble znear) {
	_zNear = znear;
	_draw();
}
void Camera::setPerspectiveZFar(GLdouble zfar) {
	_zFar = zfar;
	_draw();
}
void Camera::setPerspective(GLint fov, GLdouble aspect, GLdouble znear, GLdouble zfar) {
	_fov = fov;
	_aspect = aspect;
	_zNear = znear;
	_zFar = zfar;

}

vec3 Camera::getCameraPosition() {
	return _camera;
}