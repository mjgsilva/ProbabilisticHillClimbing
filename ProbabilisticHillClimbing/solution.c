#include <stdio.h>
#include "solution.h"
#include "utils.h"

/* 
    Generator for the first solution
    Fill sol vector with a sequence
    Call the swap function to mix solution
 */
void firstSolutionGeneration(int *sol, int M)
{
    int i;
    
    for(i=0;i<M;i++)
        sol[i] = i;

    for(i=0;i<M/2;i++)
        swapSolPos(sol,randGen(M),randGen(M));
    
}

/*
    Returns the group number using index
 */
int checkGroupPos(int M, int G, int index)
{
    int i,groupNumber=1;
    int nElements = M/G;
    
    for(i = 0; i<M; i+=nElements)
    {
        if(index >= i && index < i+nElements)
            break;
        else
            groupNumber++;
    }
    return groupNumber;
}

/*
    Generator for a solution position, avoiding
    changes between elements from the same group
*/
int avoidingIndexesInSameGroup(int M, int G, int x)
{
    int y;
    int posGx = checkGroupPos(M, G, x);
    
    do
    {
        y = randGen(M);
    } while(posGx == checkGroupPos(M, G, y));
    
    return y;
}

/*
    Generates a neighbour, based on main solution
    Calls the swap function and get the new solution
*/
void neighbouringGen(int sol[], int newSol[], int M, int G, int nRepetions)
{
    int i, x, y;
    
    copySol(sol, newSol, M);
    
    for(i = 0; i < nRepetions; i++)
    {
        x = randGen(M);
        y = avoidingIndexesInSameGroup(M, G, x);
        swapSolPos(newSol, x, y);
    }
}

/*
    Fitness calculator of all groups
 */

int calFitness(int sol[], int **matrix, int M, int G)
{
    int i;
    int nElements = M/G;
    int total=0;
    
    for(i=0 ; i<G ; i++)
        total += calSubFitness(sol, matrix, i*nElements, nElements, M);
    
    return total;
}

/*
    Fitness calculator of a group
    Calls getEdgeValue to get edge value
*/

int calSubFitness(int sol[], int **matrix, int firstPos ,int nElements, int M)
{
    int i, j;
    int lim = firstPos+nElements;
    int totalSub=0;
    
    for(i = firstPos ; i < lim; i++)
        for(j = i+1; j < lim; j++)
            totalSub += getEdgeValue(matrix, M, sol[i], sol[j]);
    
    
    return totalSub;
}

/*
    Get edge value using matrix indexes
*/

int getEdgeValue(int **matrix, int M, int x, int y)
{
    int aux;
    
    if(x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }

    return matrix[x][y];
    
}

/*
    Change the solution swaping two indexes values
*/

void swapSolPos(int *sol, int pos1, int pos2)
{
    int aux = sol[pos1];
    sol[pos1] = sol[pos2];
    sol[pos2] = aux;
}

/*
    Copy main solution to a new one
*/
void copySol(int sol[], int newSol[], int M)
{
    int i;
    
    for(i = 0 ; i < M; i++)
        newSol[i] = sol[i];
}

/*
    Print a solution
*/
void printSol(int sol[], int M, int G)
{
    int i;
    
    for(i = 0; i < M; i++)
    {
        printf("%d ",sol[i]);
        if(!((i+1) % (M/G)))
            printf("\n");
    }
}









