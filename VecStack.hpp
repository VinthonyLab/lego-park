#pragma once
#include "constant.h"
#include <stack>

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

template <class vec3> Stack<vec3>::Stack(){
	
}

template <class vec3> Stack<vec3>::~Stack(){
	//#issue 1
	//if using `delete[] item` deleting the item 
    // will cause a `warning C4154` problem.
	// because item array was not create with `new` 
	// there are server ways to free a structure in cpp
	// `vec3` struct doesn't using point , so just delete it's memory.
	for(int i = 0; i <= top;i++){
		delete &item[i];
	}
	
}

template <class vec3> void Stack<vec3>::push(vec3 v){
	
}

template <class vec3> vec3 Stack<vec3>::pop(){
	
}

template <class vec3> int Stack<vec3>::empty(){
	
}

template <class vec3> int Stack<vec3>::full(){
	
}