#ifndef _LEGO_CONSTANT_
#define _LEGO_CONSTANT_

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640
#define FOV 45
#define MAX_STACK 5
#define LEGO_CHARACTER_1 1
#define LEGO_CHARACTER_2 2
#define LEGO_CHARACTER_3 3
#define LEGO_CHARACTER_4 4

//record color( R, G, B)
struct RGB
{
	double R;
	double G;
	double B;
};

//record vector( x, y, z)
struct vec3
{
	float x;
	float y;
	float z;
};

//push into stack ( {vec3}, rotate_flag)
struct vec3_flag {
	vec3 vector;
	int flag;  //0:move  1:rotate 90 2:rotate 180 3:rotate 270
};

struct obj {
	int vecs;
	vec3 *points;
};

#define  LEGO_MAN  "./lego_people_obj/lego_man.obj";
#define  BASE "./lego_people_obj/";

#endif