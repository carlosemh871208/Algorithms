/*
 ============================================================================
 Name        : 001-c-strings.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : strings in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char boolean;
#define TRUE  (boolean) 1u
#define FALSE (boolean) 0u

static unsigned int strLength (unsigned char* input);
static void strCopy (unsigned char* output,unsigned char* input);
static void strInverse (unsigned char* output,unsigned char* input);
static void strCncatnt (unsigned char* output, unsigned char* inputA, unsigned char* inputB);
static void strUptoLowCase (unsigned char* input);
static void strLowtoUpCase (unsigned char* input);
static void strFilterLettersNumbers (unsigned char* output, unsigned char* input);
static boolean strCompare (unsigned char* inputA, unsigned char* inputB);
static boolean strIfPalindrome (unsigned char* input);

int main(void) {
    unsigned char inputA[50]  = "Ana la loca saco la lana";
    boolean status = strIfPalindrome (inputA);
	return EXIT_SUCCESS;
}

static unsigned int strLength (unsigned char* input)
{
	unsigned int counter = 0u;
	for(counter = 0u; 0u != *(input + counter); counter++){}
	return counter;
}

static void strCopy (unsigned char* output,unsigned char* input)
{
	unsigned int counter = 0u;
	unsigned char* auxArray = output;
	for(counter = 0u; 0u != *(input + counter); counter++)
	{
		*(auxArray + counter) = *(input + counter);
	}
}

static void strInverse (unsigned char* output,unsigned char* input)
{
	unsigned int counter = 0u;
	unsigned int lenArray = strLength (input);
	unsigned char* auxArray = output;
	for(counter = 0u; 0u != *(input + counter); counter++)
	{
		lenArray = lenArray -1;
		*(auxArray + counter) = *(input + lenArray);
	}
}

static void strCncatnt (unsigned char* output, unsigned char* inputA, unsigned char* inputB)
{
	unsigned int lenInA = strLength (inputA);
	unsigned int lenInB = strLength (inputB);
	unsigned int counter = 0u;
	unsigned char* auxOut = output;
	for(counter = 0u; counter < (lenInA + lenInB); counter++)
	{
		if(counter < lenInA)
		{
			*(auxOut + counter) = *(inputA + counter);
		}else
		{
			*(auxOut + counter) = *(inputB + counter - lenInA);
		}
	}
}

static void strUptoLowCase (unsigned char* input)
{
	unsigned int counter = 0u;
	unsigned char* auxArray = input;
	for(counter = 0u; 0u != *(input + counter); counter++)
	{
		if(65u <= *(input + counter) && 90u >= *(input + counter))
		{
			*(auxArray + counter) = *(auxArray + counter) + 32u;
		}else
		{
			/*Do nothing*/
		}
	}
}

static void strLowtoUpCase (unsigned char* input)
{
	unsigned int counter = 0u;
	unsigned char* auxArray = input;
	for(counter = 0u; 0u != *(input + counter); counter++)
	{
		if(97u <= *(input + counter) && 122u >= *(input + counter))
		{
			*(auxArray + counter) = *(auxArray + counter) - 32u;
		}else
		{
			/*Do nothing*/
		}
	}
}

static void strFilterLettersNumbers (unsigned char* output, unsigned char* input)
{
	unsigned int counter = 0u;
	unsigned int charCtr = 0u;
	unsigned char* auxArray = output;
	for(counter = 0u; 0u != *(input + counter); counter++)
	{
		if(97u <= *(input + counter) && 122u >= *(input + counter))
		{
			*(auxArray + counter - charCtr) = *(input + counter);
		}else
		{
			if(65u <= *(input + counter) && 90u >= *(input + counter))
			{
				*(auxArray + counter - charCtr) = *(input + counter);
			}else
			{
				if(48u <= *(input + counter) && 57u >= *(input + counter))
				{
					*(auxArray + counter - charCtr) = *(input + counter);
				}else{
					charCtr = charCtr + 1u;
				}
			}
		}
	}
}

static boolean strCompare (unsigned char* inputA, unsigned char* inputB)
{
	unsigned int lenInA = strLength (inputA);
	unsigned int lenInB = strLength (inputB);
	unsigned int counter = 0u;
	boolean state = FALSE;
	if(lenInA == lenInB){
		for(counter = 0u; lenInA > counter; counter++)
		{
			if(*(inputA + counter) != *(inputB + counter))
			{
				counter = lenInA;
				state = FALSE;
			}else
			{
				state = TRUE;
			}
		}
	}else{
		/*Do nothing*/
	}
	return state;
}

static boolean strIfPalindrome (unsigned char* input)
{
	unsigned char auxArray[50] = "";
	unsigned char auxInvrs[50] = "";
	boolean state = FALSE;
	strFilterLettersNumbers(auxArray,input);
	strUptoLowCase(auxArray);
	strInverse(auxInvrs,auxArray);
	state = strCompare (auxArray,auxInvrs);
	return state;
}
