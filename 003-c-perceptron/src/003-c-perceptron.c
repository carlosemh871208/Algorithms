/*
 ============================================================================
 Name        : 003-c-perceptron.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Perceptron in C, Ansi-style
 	 	 	   This perceptron is doing NAND operation
 	 	 	   A B  R
 	 	 	   0 0  1
 	 	 	   0 1  1
 	 	 	   1 0  1
 	 	 	   1 1  0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define lenght 2

int main(void) {
	float perceptronWeights[lenght] = {-2,-2};
	signed char perceptronInputs[lenght] = {1,1};
	signed char perceptronBias = 3;
	signed char perceptronOperator = 0;
	unsigned char perceptronOutput = 0u;
	unsigned char counter = 0;
	for(counter = 0;counter<lenght;counter++)
	{
		perceptronOperator = perceptronOperator + (signed char)(perceptronWeights[counter]*
				             perceptronInputs[counter]);
	}
	perceptronOperator = perceptronOperator + perceptronBias;
	if(0 < perceptronOperator)
	{
		perceptronOutput = 1u;
	}
	return EXIT_SUCCESS;
}
