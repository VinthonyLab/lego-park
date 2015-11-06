#include "VecStack.h"

template <class vec3> Stack<vec3>::Stack(){
	
}

template <class vec3> Stack<vec3>::~Stack(){
	//if using `delete[] item` deleting the item 
    // will cause a `warning C4154` problem.
	// because item array was not create with `new` 
	for(int i = 0; i <= top;i++){
		delete item[i];
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