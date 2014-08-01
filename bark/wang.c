#include <stdio.h>

#include "wang.h"

_declspec(dllexport) int setup(){
	printf("setup...\n");
	return 10;
}
_declspec(dllexport) int tearup(){
	printf("setup...\n");
	return 20;
}