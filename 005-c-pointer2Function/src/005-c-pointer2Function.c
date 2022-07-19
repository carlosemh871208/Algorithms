/*
 ============================================================================
 Name        : 005-c-pointer2Function.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer to function in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  (unsigned char)1u;
#define FALSE (unsigned char)0u;

/*Dummy function*/
unsigned char dummyFunction (void);

/*Pointer to function type declaration*/
typedef unsigned char (*ptr2Function) (void);

int main(void) {
	unsigned char value = FALSE;
	ptr2Function function = &dummyFunction; /*This variable gets the function address*/
	value = (*function)(); /*Function dereference*/
	return EXIT_SUCCESS;
}

unsigned char dummyFunction (void)
{
    return TRUE;
}
