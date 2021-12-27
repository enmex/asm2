#pragma once

#include "asm2.h"
#include <stdio.h>

int main() {

	//result = bc
	printf("%s\n", getSubstr("aabbccdd", 8, 3, 2));

	//result = bccd
	printf("%s\n", getSubstr("aabbccdd", 8, 3, 4));

	//result = null
	printf("%s\n", getSubstr("", 0, 3, 2));

	//result = null
	printf("%s\n", getSubstr("aabbccdd", 8, 9, 2));

	//result = cdd
	printf("%s\n", getSubstr("aabbccdd", 8, 5, 10));

}