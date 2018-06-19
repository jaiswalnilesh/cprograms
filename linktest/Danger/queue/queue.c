#include "stdio.h"
#include "stdlib.h"
#include "malloc.h" 
#define MAX	10

int q[MAX]={0};
int *qBeg,*qEnd,*qCurrent;
char Qpush(int num);
int Qpop();

void main()
{
	int num=10,i=1,count;
	char done;

	qBeg=q;
	qEnd=&q[MAX];
	qCurrent=qBeg;

	do
	{
	printf("How many nos would u like to push in the queue (1-9)");
	scanf("%d",&count);
	}while(count<=0 || count>9);
	
	while(i<=count)
	{
		printf("\nEnter number %d to b pushed in the queue: ",i);
		scanf("%d",&num);
		done=Qpush(num);

		if(done == 'n')
		{
			printf("Q overflow");
			break;
		}

		i++;
	}

	for(i=0;i<9;i++)
	{
		printf("%d ",q[i]);	
	}
	printf("\n");

	do
	{
	printf("How many nos would u like to pop in the queue (1-%d)",count);
	scanf("%d",&count);
	}while(count<=1 || count>9);

	if(done != 'n')
	for(i=1;i<=count;i++)
	{
		printf("\nPOP %d will give : %d\n",i,Qpop());		
	}

	for(i=0;i<9;i++)
	{
		printf("%d ",q[i]);	
	}
	printf("\n");
}
char Qpush(int num)
{

	if(qCurrent <= qEnd)
	{
		*qCurrent=num;
		qCurrent++;
		return 'y';
				
	}

	else
	{
		return 'n';
	
	}

}


int Qpop()
{
	int	 num,*temp;
	num=*qBeg;
	
	for(temp=qBeg;temp<qCurrent;temp++)
		*temp=*(temp+1);
	qCurrent--;

	return num;
}

