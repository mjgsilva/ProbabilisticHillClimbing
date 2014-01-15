#ifndef solution_h
#define solution_h

void firstSolutionGeneration(int *sol, int M);
int checkGroupPos(int M, int G, int index);
int avoidingIndexesInSameGroup(int M, int G, int x);
void neighbouringGen(int sol[], int newSol[], int M, int G, int nRepetions);

int calFitness(int sol[], int **mat, int M, int G);
int calSubFitness(int sol[], int **mat, int firstPos ,int nElements, int M);
int getEdgeValue(int **mat, int M, int x, int y);

void swapSolPos(int *sol, int pos1, int pos2);
void copySol(int sol[], int newSol[], int M);
void printSol(int sol[], int M, int G);

#endif
