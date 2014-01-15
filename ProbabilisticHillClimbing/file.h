#ifndef file_h
#define file_h

void getFilename(char *filename);
int checkFile(char *filename);
int ** readFile(char *filename, int *M, int *G);
void readConfig(int *runs, int *iters, int *swap, float *prob);

#endif
