#include <stdio.h>

#include "data.h"

/***the main function***/

int main(){

	int matrix[N][N];
	int flag=TRUE;


	printf("\nPlease enter %d numbers,between 1-%d to create a %dx%d matrix\n\n",POWN,POWN,N,N);
	
	/*if the user gave a valid matrix, print it and check if it a magic square*/
	if(getMatrix(matrix,&flag)){

		printMatrix(matrix);

		if((flag==FALSE)||(!checkOne(matrix))||(!checkSum(matrix)))
			magicSquare(FALSE);
		else
			magicSquare(TRUE);
	}


	return 0;

}
