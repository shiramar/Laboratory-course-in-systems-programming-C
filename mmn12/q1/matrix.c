#include "data.h"

/*the function get the matrix from the user or a input file*/
int getMatrix(int matrix[N][N],int *flag){

	int count=0,i=0,j=0;
	int input,c;
		
	while((c=(scanf("%d",&input)))==1){/*if the input isn't int, stop while*/

		++count;

		if((input<0)||(input>POWN))/*if the number is not in range 0-N^2*/
			*flag=FALSE;

		else if(count>POWN)/*if there are too many numbers*/ 
			printError(2);
			
		matrix[i][j]=input;/*if it a valid input ,insert into the matrix*/

		j++;
		if(j==N)/*end line*/
			j=0,i++;
	
	}

		
	if(c==0)/*if isn't a int input*/ 
		printError(1);
	

	else if(count<(POWN))/*if there are too few numbers*/
		printError(3);
	

	return TRUE;


}


/*the matrix check if there is a variable that appears more then once*/
int checkOne(int matrix[N][N]){

	int i,j,num;
	int cuntArr[POWN+1];/*counters array*/

	for(i=0;i<(POWN+1);i++){/*array boot*/
		cuntArr[i]=0;
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			num=matrix[i][j];
			cuntArr[num]++;/*we will add to place 'num' 1*/
			if(cuntArr[num]!=1)/*if there is a num that appear twice*/
				return FALSE;
		}
	}
	return TRUE;
}


/*the function check if the sum of lines,columns,diagonals is a magic square sum*/
int checkSum(int matrix[N][N]){

	int i,j;
	int sumRow=0,sumCol=0,sumRiDiag=0,sumLeDiag=0;

	/*we use a for loop, for row i is for line and j for columns and for col opposite*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if((j==0)&&(i!=0)){
				if((sumRow==MAGIC_SUM)&&(sumCol==MAGIC_SUM))/*if it is end of line/column, we need to reset the sum if is a magic sum*/
					sumRow=0,sumCol=0;
				else
					return FALSE;
			}
			sumRow+=matrix[i][j];
			sumCol+=matrix[j][i];
			
			if(i==j)/*i=j in the left diagonal*/
				sumLeDiag+=matrix[i][j];		
		}
	}
	
	/*for loop for right diagonal*/
	for(i=0,j=N-1;i<N;i++,j--){
			sumRiDiag+=matrix[i][j];
	}


	if((sumRow==MAGIC_SUM)&&(sumCol==MAGIC_SUM)&&(sumRiDiag==MAGIC_SUM)&&(sumLeDiag==MAGIC_SUM))
		return TRUE;
	
	return FALSE;
}


