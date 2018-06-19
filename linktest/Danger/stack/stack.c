#include "stdio.h"
#include "stdlib.h"
#include "malloc.h" 
#define MAX	100

int pop(int** stack_top);
char push(int num,int** stack_top);
int stack[MAX];
void main()
{
	int *st,i=1,count,num;
	static int **stack_top;
	char done;
	st=&stack[MAX];
	stack_top=&st;
	//st = (int*)malloc(sizeof(int*));
	//stack_top=&

	do
	{
	printf("How many nos would u like to push (1-9)");
	scanf("%d",&count);
	}while(count<=0 || count>9);
	
	while(i<=count)
	{
		printf("\nEnter number %d to b pushed: ",i);
		scanf("%d",&num);
		done=push(num,stack_top);

		if(done == 'n')
		{
			printf("Stack overflow");
			break;
		}

		i++;
	}

	if(done != 'n')
	for(i=1;i<=count;i++)
	{
		printf("\nPOP %d will give : %d\n",i,pop(stack_top));		
	}

}

char push(int num,int** stack_top)
{

	*stack_top=*stack_top-1;
	if(*stack_top >= stack)
	{
		**stack_top=num;
		return 'y';
	}
	else
	{
		return 'n';
	}
}

int pop(int** stack_top)
{
	int num=**stack_top;
	*stack_top=*stack_top+1;
	return num;

}
