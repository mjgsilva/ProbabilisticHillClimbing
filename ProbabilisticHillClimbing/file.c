#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define NRUNS 10
#define NITERS 1000
#define NEIGH 1
#define PROBV 0.01

/*
    Get the filename by an user input
*/
void getFilename(char * filename)
{
    size_t len;
    printf("Filename: \n");
    if(fgets(filename,sizeof(filename),stdin))
    {   len = strlen(filename)-1;
        
        if(filename[len] == '\n')
            filename[len] = '\0';
    }
}

/*
    Check if the file exists
*/
int checkFile(char *filename)
{
    FILE *f;
    f = fopen(filename, "r");
    
    if(!f)
        return 0;
    else
        return 1;
    
    fclose(f);
    
}

/* Read the solution length (M - Number of Elements) and number of groups (G)
   Allocate memory for matrix
   Read the edge values and fill the matrix
*/
int ** readFile(char *filename, int *M, int *G)
{
    FILE *f;
    char buffer[150];
    int edges;
    int **matrix;
    int i,j,k,aux;
    
    f = fopen(filename, "r");
    
    fscanf(f, " %d", M);
    fscanf(f, " %d", G);
    fgets(buffer,150,f);
    
    edges = (*M * (*M - 1)/2);
    
    if(!(matrix = (int **)malloc(*M * sizeof(int *))))
        return NULL;
    
    
    for(i=0; i < *M; i++)
    {
        if(!(matrix[i] = (int *)calloc(*M,sizeof(int))))
            return NULL;
        printf("i: %d\n",i);
    }
    
    
    for(k = 0; k < edges; k++)
    {
        fscanf(f, " %d %d", &i, &j);
        fscanf(f, " %d", &aux);
        matrix[i][j] = aux;
        matrix[j][i] = aux;
    }
        
    fclose(f);
    return matrix;
}

/*
    Read Param Config file
*/

void readConfig(int *runs, int *iters, int *swap, float *prob)
{
    FILE *g;
    
    if(checkFile("paramconfig.txt"))
    {
        g = fopen("paramconfig.txt", "r");

        fscanf(g," runs: %d", runs);
        fscanf(g," iters: %d", iters);
        fscanf(g," swap: %d", swap);
        fscanf(g," prob: %f", prob);
    }
    else
    {
        *runs = NRUNS;
        *iters = NITERS;
        *swap = NEIGH;
        *prob = PROBV;

    }
}
