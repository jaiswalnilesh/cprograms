#include "stdio.h"
#include "stdlib.h"
#include "malloc.h" 
#define MAX	3

int q[MAX]={0};
int *qBeg,*qEnd,*qCurrent;
char Qpush(int num);
int Qpop();

void main()
{
	int num,i=1,operation;
	char done;
	int* qrefer;
	qBeg=q;
	qEnd=&q[MAX-1];
	qCurrent=qBeg-1;

	do
	{
		printf("\n\nChoice:\n1>Add an Element to Q\n2>Pop an Element from the Q\n3>Display the Q\n4>Exit\n");
	
		do
		{
			fflush(stdin);
			scanf("%d",&operation);
			if(operation<0 || operation>4)
			{
				printf("Enter a valid number");
			}
		}while(operation<0 || operation>4);

		switch(operation)
		{
		case 1:
			{
				fflush(stdin);
				printf("\n\nEnter the Element to be added(Except 0) : ");
				scanf("%d",&num);
				done=Qpush(num);
				if(done!='y')
					printf("\n\t\tQ Overflow\n");
				else
					printf("\n\n\t\tAdded !!!\n");
				break;
				
			}
		case 2:
			{
				num=Qpop();
				if(num==0)
					printf("\n\n\t\tNo numbers in the Q\n");
				else
					printf("\n\n\t\tPop gives %d",num);
				break;
			}
		case 3:
			{
				printf("\n\n");
				for(qrefer=qBeg;qrefer<=qCurrent;qrefer++)
				{
					printf("%d  ",*qrefer);			
				}
				printf("\n");
				break;
			}
		case 4:
			{
				exit(0);
			}
		}
	}while(operation!=4);
}
char Qpush(int num)
{
	qCurrent++;
	if(qCurrent <= qEnd)
	{
		*qCurrent=num;
		return 'y';
				
	}
	else
	{
		qCurrent--;
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

