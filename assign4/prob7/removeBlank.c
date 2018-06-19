//PROGRAM TO PEPLACE ALL MULTIPLE BALNKS BY SINGLE ONE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char again='n',*str=(char *)malloc(100*sizeof(char));	
	char *removeBlanks(char *str);
	do
	{
		printf("Enter The String To Get Blanks get Reduced: ");
		fflush(stdin);
		gets(str);
		realloc(str,((strlen(str)+1)*sizeof(char)));
		printf("The String After Removing the Multiple Blanks is : \n\t");
		puts(removeBlanks(str));
		printf("\n\n\t\tDo You want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
METHOD TO PEPLACE ALL MULTIPLE BALNKS BY SINGLE ONE
@param str : input string
@return char * : the multi blank replaced be single blank string 
*/
char *removeBlanks(char *str)
{
	char *result1=str,*result=str;
	while(*str)
	{
		if(!((*str==' ') && ((*(str+1))==' ')))
			*result1++ = *str;
		str++;
	}			
	*result1='\0';
	return result;
}
