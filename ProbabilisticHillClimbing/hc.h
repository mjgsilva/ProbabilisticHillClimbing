#ifndef hc_h
#define hc_h

int hillClimbing(int sol[], int **matrix, int M, int G, int iters, int swap);
int hillClimbingProb(int sol[], int **matrix, int M, int G, int iters, int swap, float prob);

#endif
