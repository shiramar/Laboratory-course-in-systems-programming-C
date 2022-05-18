#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 101
#define TRUE 1  
#define FALSE 0

enum status{OUT,LEFT_SLASH,RIGHT_STAR,IN_COMMENT,IN_QUOTE}; /*Set modes for the lines to checkLine*/

int getLine(char currLine[]); /*Function that receives a line from the user at a time */
int checkLine(char currLine[],int *comment); /*Function that checks each character */
int isSpecial(char currLine[],long *countSpecial); /*Function that checks if it's a special row*/
void printLineBalance(int balance); /*Function that prints the line balance summary*/
void printGlobalBalance(int balance); /*Function that prints the global text balance summary*/

int main(){
	
	int balance=TRUE; /*the initial balance mode as balanced*/
	int comment=FALSE; /*the initial mode line is uncomment*/
	long countSpecial = 0; /*a counter for the special close*/
	char currLine[MAX_LENGTH];
	
	printf("Please enter your input, EOF for end\n");

    while(getLine(currLine)){	/*until EOF get line by line*/
		printf("%s\n" ,currLine);
		if((comment)||(!isSpecial(currLine,&countSpecial))) {/*if the line is comment we don't need check if it special line, and if it special line, we don't need check the line*/
			if(!checkLine(currLine,&comment))
				balance=FALSE;

		}
	}

	((balance==0)||(countSpecial!=0))?printGlobalBalance(FALSE):printGlobalBalance(TRUE);

	return 0;

}


int getLine(char currLine[]){

	if(fgets(currLine,MAX_LENGTH,stdin)!=NULL){
		currLine[strcspn(currLine,"\n")]='\0';

		return 1;
	}
	return 0;
}


int checkLine(char currLine[],int *comment){

	int i=-1,k=-1,state = OUT,countClose = 0;
	char arrClose[MAX_LENGTH];

	if(*comment)/*if it comment line, update the status to be a comment*/ 
		state=IN_COMMENT;

	while((currLine[i]!='\0')&&(currLine[i]!=EOF)){

	++i;
		switch(state){
				case OUT:/*neither status*/
					if(currLine[i]=='/')
						state=LEFT_SLASH;
					else if(currLine[i]=='"')
						state=IN_QUOTE;
					else if((currLine[i]=='(')||(currLine[i]=='[')||(currLine[i]=='{')){
						++k;
						arrClose[k]=currLine[i];
						++countClose;
					}
					else if(currLine[i]==')'){
						if(arrClose[k]=='('){
							arrClose[k]='\0';
							--countClose;
							--k;
						}
						else 
							++countClose;
					}
					else if(currLine[i]==']'){
						if(arrClose[k]=='['){
							arrClose[k]='\0';
							--countClose;
							--k;
						}
						else 
							++countClose;
					}
					else if(currLine[i]=='}'){
						if(arrClose[k]=='{'){
							arrClose[k]='\0';
							--countClose;
							--k;
						}
						else 
							++countClose;
					}	
					break;				
				case LEFT_SLASH:/*if ' /' */
					if(currLine[i]=='*'){
						state=IN_COMMENT;
						*comment=TRUE;
					}
					else
						state=OUT;
					break;
				case IN_COMMENT:
					if(currLine[i]=='*')
						state=RIGHT_STAR;	
					break;
				case RIGHT_STAR:/* '*' */
					if(currLine[i]=='/'){
						state=OUT;
						*comment=FALSE;

					}
					break;	
				case IN_QUOTE:/* ' " ' */
					if(currLine[i]=='"')
						state=OUT;
					break;
						
			}

	}
	
	if(countClose>0){/*if the count close up to 1 the line isn't balance*/
		printLineBalance(FALSE);				
		return FALSE;
	}
	printLineBalance(TRUE);
	
	return 1;

}

int isSpecial(char currLine[],long *countSpecial){
	
	int i=0, cnt=0;
	char special=' ';
	
	while((currLine[i]!='\0')&&(currLine[i]!=EOF)){
		if((!isspace(currLine[i]))&&(currLine[i]!='{')&&(currLine[i]!='}'))/*if the char didn't match to special line*/
			return FALSE;
		if((currLine[i]=='{')||(currLine[i]=='}')){/*counter for the special tab*/
			special=currLine[i];
			++cnt;
				
		}
		++i;
	}

	if(cnt!=1)
		return FALSE;

	printLineBalance(FALSE);
	(special=='{')?	++*countSpecial: --*countSpecial;
	if(*countSpecial<0)
		*countSpecial=(-99999999);

	return TRUE;
}

void printLineBalance(int balance){

	if(balance==FALSE)
		printf("this line isn't balance\n");
	else
		printf("this line is balance\n");
}

void printGlobalBalance(int balance){

	if(balance==FALSE)
		printf("this text isn't balance\n");
	else
		printf("this text is balance\n");
}
