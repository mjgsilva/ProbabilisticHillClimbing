#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "solution.h"
#include "utils.h"
#include "hc.h"



int main(int argc, const char * argv[])
{
    char filename[25];
    int **matrix = NULL, *sol, *bestsol;
    int M, G, total, bestSolTotal=0;
    int runs, iters, swap;
    float prob;
    float sum=0;
    int i;

    if(argc != 2)
        getFilename(filename);
    else
        strcpy(filename,argv[1]);
    
     if(!checkFile(filename))
     {
         printf("File not exists!\n");
         return 0;
     }
     else
     {
         //file.c - F INPUT
         readConfig(&runs, &iters, &swap, &prob);

         //file.c - F INPUT
         if(!(matrix=readFile(filename, &M, &G)))
         {
            printf("Memory Allocation Error\n");
            return 0;
         }
         
         if(!(sol = (int *)malloc(M * sizeof(int))) || !(bestsol = (int *)malloc(M * sizeof(int))))
         {
             printf("Memory Allocation Error\n");
             return 0;
         }
         
         //utils.c
         iRand();
        
         for(i = 0; i<runs; i++)
         {
             firstSolutionGeneration(sol, M);
             
             //total = hillClimbing(sol, matrix, M, G, iters, swap);
             total = hillClimbingProb(sol, matrix, M, G, iters, swap, prob);
             printf("Solution %d\n",i+1);
             printSol(sol, M, G);
             printf("Total: %d\n\n",total);
             
             sum += total;
             
             if(bestSolTotal < total)
             {
                 copySol(sol, bestsol, M);
                 bestSolTotal = total;
             }
         }
         
         printf("MBF: %.2f\n", sum/runs);
         printf("Best Solution:\n");
         printSol(bestsol, M, G);
         printf("Best Solution Total: %d\n", bestSolTotal);
         
         free(bestsol);
         free(sol);
         free(matrix);

     }
}

