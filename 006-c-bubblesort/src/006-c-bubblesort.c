/*
 ============================================================================
 Name        : 006-c-bubblesort.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Bubble sort project in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE (unsigned char) 10u

/*Bubble sort function definition*/
static void bubbleSort (unsigned char* array);

int main(void)
{
	unsigned char array[SIZE] = {4,3,6,2,7,8,9,1,5,0};
	bubbleSort(array);
	return EXIT_SUCCESS;
}

/*Bubble sort function implementation*/
static void bubbleSort (unsigned char* array)
{
	unsigned char counter = 0u;
	unsigned char index = 0u;
	unsigned char aux = 0u;
	for(counter = 0u;counter < SIZE;counter++)
	{
		for(index = counter;index < SIZE;index++)
		{
			if (*(array + counter) > *(array + index))
			{
				/*Do nothing*/
			}else
			{
				aux = *(array + counter);
				*(array + counter) = *(array + index);
				*(array + index) = aux;
			}
		}
	}
}
