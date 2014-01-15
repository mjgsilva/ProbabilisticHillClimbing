#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

/*
    Random number generator initialization
*/
void iRand()
{
    srand((unsigned)time(NULL));
}

/*
    Returns an integer between 0 and Max
*/
int randGen(int max)
{
    return rand() % max;
}

/*
    Returns a float bewteen 0 and 1
*/
float randFloatGen()
{
    return ((float)rand()/RAND_MAX);
}