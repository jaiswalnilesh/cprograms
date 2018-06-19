#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX	20

char pop(char** stack_top);
char push(char oper,char** stack_top);
//char checkPrece(char oper);

char stack[MAX];
void main()
{

	char *stack_top;
	char done='y';
	char *result,*source,pre;
	int len;

	stack_top=&stack[MAX];

	source=(char*)malloc(30);
	result=(char*)malloc(30);
	printf("\nEnter Source String\n");
	
	do
	{
		if(done=='n')
			printf("\nEnter a valid String:   ");
		done='n';
		result=source;
		gets(source);
		len=strlen(source);
		realloc(source,sizeof(char)*len+1);
		realloc(result,sizeof(char)*len+1);
		

		while(*result != '\0')
		{
			if(*result == 'C' || *result == 'c')
			{
				done='y';
				break;
			}

			result++;
		}
	}while(done!='y');

	while(*source!='C' && *source!='c')
	{
		done=push(*source,&stack_top);
		if(done=='n')
		{
			printf("\n\tStack Overflow");
			break;
		}	
		source++;
	}

	source++;
	done='y';
	while(*source != '\0')
	{
		pre=pop(&stack_top);
		if(pre!=0)
		{
			if(pre!=*source)
			{
				done='n';
				break;
			}
		}
		else
		{
			done='n';
			break;
		}
		source++;
	}

	if(done=='y')
		printf("\n\tString is a palindrome\n");
	else
		printf("\n\tSorry Boss\n");
}


char push(char oper,char** stack_top)
{

	*stack_top=*stack_top-1;
	if(*stack_top >= stack)
	{
		**stack_top=oper;
		return 'y';
	}
	else
	{
		return 'n';
	}
}

char pop(char** stack_top)
{
	char num;
	if(*stack_top<=&stack[MAX-1])
	{
		num=**stack_top;
		*stack_top=*stack_top+1;
		return num;
	}
	else
		return 0;
}
