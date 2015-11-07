#pragma once

#include "fileLoader.h"

void readStr(FILE *f,char *str){
	do{
		fgets(str,255,f);
	}while((str[0]=='\0') ||(str[0] == '\n'));
	return ;
}

void objLoad(char *name,obj *o){

}

