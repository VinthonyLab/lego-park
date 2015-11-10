#ifndef _LEGO_CONSTANT_
#define _LEGO_CONSTANT_

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640
#define FOV 45
#define MAX_STACK 10000
#define LEGO_CHARACTER_1 1
#define LEGO_CHARACTER_2 2
#define LEGO_CHARACTER_3 3
#define LEGO_CHARACTER_4 4
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