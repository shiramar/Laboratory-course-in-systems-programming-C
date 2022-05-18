#include "data.h"

/*The function print error if it unvalid matrix*/
void printError(int state){

	switch(state){
		case 1:
			printf("\nERROR: The matrix can include only int variables\n");
			break;
		case 2:
			printf("\nERROR:There are too many values in the input\n");
			break;
		case 3:
			printf("\nERROR:There are too few values in the input\n");
			break;

	}
exit(0);
}

/*The function print a matrix*/
void printMatrix(int matrix[N][N]){

	int i,j;

	printf("\n");

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d	",matrix[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
}

/*the functions print if the matrix is a square magic*/
void magicSquare(int isMagic){

	if(isMagic==TRUE)
		printf("The resulting matrix is a magic square, the common sum is = %d\n",MAGIC_SUM);
	if(isMagic==FALSE)
		printf("The resulting matrix isn't a magic square\n");

}

