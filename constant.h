#ifndef _LEGO_CONSTANT_
#define _LEGO_CONSTANT_

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640
#define FOV 45
#define MAX_STACK 10000
struct vec3{
	float x;
	float y;
	float z;
};

struct obj{
	int vecs;
	vec3 *points;
};

#endif