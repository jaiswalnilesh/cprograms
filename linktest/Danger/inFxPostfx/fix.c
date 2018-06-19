#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX	100

char pop(char** stack_top);
char push(char oper,char** stack_top);
char checkPrece(char oper);

char stack[MAX];
void main()
{

	char *stack_top;
	char done;
	char *result,*source,pre;
	int len;

	stack_top=&stack[MAX];

	source=(char*)malloc(100);
	do
	{
	printf("\nEnter Source String\n");
	gets(source);

	len=strlen(source);
	if(*source=='-'||*source=='+'||*source=='*'||*source=='/' || *(source+len)=='-'||*(source+len)=='+'||*(source+len)=='*'||*(source+len)=='/')
		printf("\nString is invalid\n");
	}while(*source=='-'||*source=='+'||*source=='*'||*source=='/' || *(source+len)=='-'||*(source+len)=='+'||*(source+len)=='*'||*(source+len)=='/');
	
	realloc(source,(len+1)*sizeof(char));
	result=(char*)malloc((len+1)*sizeof(char));
	len=0;

	while(*source!='\0' )
	{
		if(*source=='-'||*source=='+'||*source=='*'||*source=='/')
		{
			pre=checkPrece(*source);

			if(pre<=checkPrece(*stack_top))
			{
				if(stack_top<=&stack[MAX-1])
				{
					while(pre<=checkPrece(*stack_top) && stack_top<=&stack[MAX-1])
					{
						*(result+len)=pop(&stack_top);	
						len++;
					}
				}

				done = push(*source,&stack_top);
					
			}
			else
			{
				done=push(*source,&stack_top);

			}
			if(done=='n')
			{
				printf("Stack Overflow.. Can not contimue..");
				exit(0);
			}
				
		}
		else
		{
			*(result+len)=*source;
			len++;
		}
		source++;
	}

	while(stack_top<=&stack[MAX-1])
	{
		*(result+len)=pop(&stack_top);	
		len++;
	}

	*(result+len)='\0';
	puts(result);
}

char checkPrece(char oper)
{
	switch(oper)
	{
	case '+':case '-': return 1;
	case '*':case '/': return 2;
	default: return 0;	
	}
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
