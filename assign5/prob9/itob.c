//PROGRAM TO CONVERT AN INT TO A STRING IN A SPECIFIED BASE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	char again='n';
	char *intString;
	int no,base;	
	void itob(int no,char *s,int base);


	do
	{
		printf("Enter The Int To Be Converted To String : ");
		fflush(stdin);
		while(scanf("%d",&no)==0)
		{
			printf("Enter The VALID Int To Be Converted To String : ");
			fflush(stdin);
		}
		intString=(char *)malloc(10*sizeof(char));
		printf("Enter The Base For The Number Conversion : ");
		fflush(stdin);
		scanf("%d",&base);
		while(base<0 || base>16)
		{
			printf("Enter The VALID Base (1 to 16) For The Number Conversion : ");
			fflush(stdin);
			scanf("%d",&base);
		}
		itob(no,intString,base);
		printf("\n\nInt %d CONVERTED TO Int Base %d IS %s",no,base,intString);
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}




/*
converts the given integer to string with specified base

@param no : integer to be converted to string 
@param s : string in which the parsed number is to be stored;
@param base : the base value in which the number is to be stored.
*/
void itob(int no,char *s,int base)
{

	char *hexa="0123456789ABCDEF";
	int i=0;
	while(no>0)
	{
		s[i++]=hexa[no%base];
		no/=base;
	}
	s[i]='\0';
	realloc(s,(i+1)*sizeof(char));
	strrev(s);
}
