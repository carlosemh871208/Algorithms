/*
 ============================================================================
 Name        : 005-c-callbackexample.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  (unsigned char)1u;
#define FALSE (unsigned char)0u;

/*Dummy function definition*/
unsigned char dummyFunction (void);

/*Pointer to function declaration*/
typedef unsigned char (*ptr2function)(void);

/*Callback function*/
void callBackFunction (ptr2function ptr);

int main(void) {
	callBackFunction (&dummyFunction);
	return EXIT_SUCCESS;
}

/*Dummy function implementation*/
unsigned char dummyFunction (void)
{
    return TRUE;
}

/*CallBack function implementation*/
void callBackFunction (ptr2function ptr)
{
    unsigned char value = FALSE;
    value = (*ptr)();
}
