//PROGRAM TO ROTATE A STRING
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char again='n';
	char *str=(char *)malloc(100*sizeof(char));
	void rotate(char *str);
	do
	{
		printf("\n\nEnter A String : ");
		fflush(stdin);
		gets(str);
		realloc(str,((strlen(str)+1)*sizeof(char)));
		printf("\n\nRotated String Is : ");
		rotate(str);
		printf("\n\n\t\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}
/*
METHOD TO ROTATE A STRING
@param str : input string
*/
void rotate(char *str)
{
	int i,j,len=strlen(str);
	char ch;
	for(i=0;i<len;i++)
	{
		ch=*str;
		for(j=0;j<len-1;j++)
		{			
			*(str+j)=*(str+j+1);
		}
		*(str+j)=ch;
		printf("\n\tRotetion %d\t\t",(i+1));
		puts(str);
	}
}