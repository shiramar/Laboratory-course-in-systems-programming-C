#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 81

void contract(char s1[], char s2[]);/Function statement/

int main(){
	
	char str1[MAX_LENGTH], str2[MAX_LENGTH];

	printf("please write your input: \n");

	fgets(str1, MAX_LENGTH, stdin);/gets the input/
	contract(str1,str2);

	printf("The abbreviated string is:\n%s",str2);
 

	return 0;
}


void contract(char s1[], char s2[]){


	int i, k=0, asci = 0, nextAsci=0, count=0;
	
	for(i=0; s1[i]!='\0'; i++){

		asci= (int)s1[i];/get the asci code of the char/
		nextAsci = (int)s1[i+1];/asci code of the next char/

		if((nextAsci == (asci + 1))&&(isalnum(s1[i]))&&(isalnum(s1[i+1])))/Check if it is consecutive characters/
			++count;	
				
		else{
			if((isalnum(s1[i]))&&(count>0)){/If there are 2 consecutive characters or more/
				s2[k] = s1[i-count];
				if(count>1){/If there are more than 2 consecutive characters/
					s2[k+1]='-';
					s2[k+2]=s1[i];
					k+=3;
				}
				else{/only 2 consecutive characters/
					s2[k+1]=s1[i];
					k+=2;
				}
				count=0;
			}
			else{/if itn't alnum or is only one alnum/
				s2[k]=s1[i];
				++k;
				count=0;
			}
		}
		

	}
		s2[k]='\0';

}
