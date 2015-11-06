#pragma once
#include "camera.h"
#include <stack>
//http://www.cs.utsa.edu/~wagner/CS2213/stack/stack_template.html
#define MAX_STACK 10000

template <class vec3> class Stack
{
	int EmptyStack;
	vec3 item[MAX_STACK];
	int top;
public:
	Stack();
	~Stack();
	void push(vec3 v);
	vec3 pop();
	int empty();
	int full();
};