#include <stdio.h>
#include <stdlib.h>

int find_n(char a[]);
void print_error(int i);
int there_n(char a[],int n);


int main(int argc, char* argv[]){

	int i=2, n, newN;
	n= find_n(argv[1]);/*cast n from char to int*/
	
	if(n<0){/*if it a negative num*/
		print_error(0);
		return 0;
	}

	else if(argc<3){/*if there are less than 3 arguments*/
		print_error(1);
		return 0;
	}

	printf("The selected 'n' is %d\n\n",n);
	
	while(i<argc){/*take file by file*/

		printf("*************************************************************\nFile '%s'\n",argv[i]);
		newN=there_n(argv[i],n);/*check if there is a character int the 'n' place*/ 

		if(newN!=-1)/*loading problem or if n>length*/
			printf("The asci code of n is: %d\n\n",newN);

		i++;			
		
	}
	

	return 0;
	
}

/*cast n from char to int*/
int find_n(char a[]){

	int n;
	
	n=atoi(a);

	return n;
}

/*this function print Error massage*/
void print_error(int i){

	printf("\nERROR: ");

	switch(i){
		case (0):
			printf("The first argument must be greater than 0\n\n");
		break;
		case(1):
			printf("Less than two arguments were passed to the program in the command line\n\n");
		break;
		case(2):
			printf("Unable to open current input file\n\n");
		break;
		case(3):
			printf("The number of characters in the current file is less than n.\n\n");
		break;
	}
}

int there_n(char a[],int n){
	
	FILE *fp;/*a pointer to the file*/
	int length;

	fp= fopen(a, "r");/*open the file for read*/

	if(fp==NULL){/*problem loading file*/
		print_error(2);
		return -1;
	}

  	fseek(fp, 0, SEEK_END);/*check length file*/
	length=ftell(fp);

	if(length<=n){
		print_error(3);
		return -1;
	}

	fseek(fp, n - 1, SEEK_SET);/*get the char in n place*/
        return fgetc(fp);

}
