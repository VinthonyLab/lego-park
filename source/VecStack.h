#ifndef VECSTACK_H_
#define VECSTACK_H_

#include "constant.h"
#include <stack>

template <class vec3_flag>
class Stack
{
private:
	//int EmptyStack;
	vec3_flag item[MAX_STACK];
	int top;
public:
	Stack();
	~Stack();
	void push(vec3_flag v);
	void pop(vec3_flag & v);
	bool isempty();
	bool isfull();
	void empty();
};

template <class vec3_flag>
Stack<vec3_flag>::Stack()
{
	top = 0;
}

template <class vec3_flag>
Stack<vec3_flag>::~Stack()
{
	//#issue 1
	//if using `delete[] item` deleting the item 
	// will cause a `warning C4154` problem.
	// because item array was not create with `new` 
	// there are server ways to free a structure in cpp
	// `vec3` struct doesn't using point , so just delete it's memory.
	for (int i = 0; i < top; i++) {
		delete &item[i];
	}
}

template <class vec3_flag>
void Stack<vec3_flag>::push(vec3_flag v)
{
	if (top<MAX_STACK)
	{
		item[top].vector.x = v.vector.x;
		item[top].vector.y = v.vector.y;
		item[top].vector.z = v.vector.z;
		item[top].flag = v.flag;
		top++;
	}
}

template <class vec3_flag>
void Stack<vec3_flag>::pop(vec3_flag & v)
{

	if (isempty()==false)
	{
		top--;
		v.vector.x = item[top].vector.x;
		v.vector.y = item[top].vector.y;
		v.vector.z = item[top].vector.z;
		v.flag = item[top].flag;
	}
	
}

template <class vec3_flag>
bool Stack<vec3_flag>::isempty()
{
	//cout <<"isempty: "<< top << endl;
	return top == 0;
}

template <class vec3_flag>
bool Stack<vec3_flag>::isfull()
{
	//cout <<"isfull: "<< top << endl;
	return top == MAX_STACK;
}

template <class vec3_flag>
void Stack<vec3_flag>::empty()
{
	top = 0;
}


#endif