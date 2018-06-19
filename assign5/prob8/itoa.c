//PROGRAM TO CONVERT A INTEGER TO A STRING

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	char *itoa(int no);
	char again='n',*temp;
	int no;	

	do
	{
		printf("Enter The Int To Be Converted To String : ");
		fflush(stdin);
		while(scanf("%d",&no)==0)
		{
			printf("Enter The VALID Int To Be Converted To String : ");
			fflush(stdin);
		}
		printf("\n\nInt %d CONVERTED TO Int IS %s",no,(temp=itoa(no)));
		free(temp);
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	free(temp);
}


/*
converts the given integer to string
@param no : integer to be converted to string 
@return char* : string in which the parsed number is to be stored;
*/
char* itoa(int no)
{
	char *intString=(char *)malloc(10*sizeof(char));
	int i=0;
	while(no>0)
	{
		intString[i++]=(no%10)+48;
		no/=10;
	}
	intString[i]='\0';
	realloc(intString,(i+1)*sizeof(char));
	return strrev(intString);
}
