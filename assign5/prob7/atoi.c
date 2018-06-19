//PROGRAM TO CONVERT STRING TO INTEGER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char again='n',intString[6];
	int *no=(int*)malloc(sizeof(int));
	char strToInt(char *str,int *no);
	do
	{
		printf("Enter The String To Be Converted To Int: ");
		fflush(stdin);
		if(strToInt(gets(intString),no)=='y')
			printf("\n\nString %s CONVERTED TO String IS %d",intString,*no);
		else
			printf("\n\nString %s CANNOT BE CONVERTED TO INT",intString);
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	free(no);
}


/*
converts the given string to integer
@param str : string to be converted to integer
@param no : integer pointer in which the parsed number is to be stored;
@return char : return 'y' if function successful in parsing
			   return 'n' if function in NOT successful in parsing
*/
char strToInt(char *str,int *no)
{
	*no=0;
	while(*str)
	{
		if(!(isdigit(*str)))
			return 'n';
		else
		{
			*no=(int)((*no)*10+((*str)-48));
			str++;
		}
	}
	return 'y';
}
