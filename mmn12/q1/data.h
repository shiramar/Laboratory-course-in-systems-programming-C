
#ifndef DATA_H
#define DATA_H

/**include for all files**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**constant**/
#define N 5
#define TRUE 1
#define FALSE 0
#define POWN (N*N)
#define MAGIC_SUM ((N*(N*N+1))/2)

/**function statement**/

/*get matrix from the user*/
int getMatrix(int matrix[N][N],int *flag);

/*The function print Eroor if it is unvalid matrix*/
void printError(int state);

/*the function print matrix*/
void printMatrix(int matrix[N][N]);

/*the function print if the matrix is a magic square ot not*/
void magicSquare(int isMagic);

/*the matrix check if there is a variable that appears more then once*/
int checkOne(int matrix[N][N]);

/*the function check if the sum of lines,columns,diagonals is a magic square sum*/
int checkSum(int matrix[N][N]);


#endif
