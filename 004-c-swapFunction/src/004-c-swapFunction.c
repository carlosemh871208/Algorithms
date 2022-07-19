/*
 ============================================================================
 Name        : 004-c-swapFunction.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Swap function in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*Swap function by value definition*/
void swapValue (unsigned char* a, unsigned char* b);
/*Swap function by reference definition*/
void swapAddress (unsigned char* a, unsigned char* b);

int main(void)
{
	unsigned char valA = 0u;
	unsigned char valB = 1u;
	swapAddress (&valA,&valB);
	swapValue (&valA,&valB);
	return EXIT_SUCCESS;
}

void swapValue (unsigned char* a, unsigned char* b)
{
    unsigned char aux = 0u;
    aux = *a;
    *a = *b;
    *b = aux;
}

void swapAddress (unsigned char* a, unsigned char* b)
{
    unsigned char* aux = NULL;
    aux = a;
    a = b;
    b = aux;
}
