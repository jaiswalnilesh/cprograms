/*Program to create a link list and insert some elements to it */

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"

void addNode(struct Node**,int num);
char delNode(struct Node**,int num);

int count=1;

struct Node
{
	int a;
	struct Node *Next;
	struct Node *Prev;
};

void main()
{
	int i=0,num,operation;
	char done;
	struct Node *first=NULL,*temp=NULL,*last;

	do
	{
		fflush(stdin);
        printf("\nEnter 1 or 2 or 3 for following operations !!\n 1) Display List \n 2) Add element to the list\n 3) Delete element from the list \n any other key to exit\n");
		if(scanf("%d",&operation)==0)
		{
			exit(0);
		}


		switch (operation)
		{
			case 1:
				{
					temp=first;
					if(temp==NULL)
						printf("No Elements in the List\n");
					while(temp!= NULL)
					{
						printf("\n %d\n",temp->a);
						last=temp;
						temp=temp->Next;
					}
					printf("\n\n Form last to first\n");

					
					while(last!=NULL)
					{
						printf("\n %d\n",last->a);
						last=last->Prev;					
					}
					printf("\n\n");
					break;
				}
			case 2:
				{
					fflush(stdin);
					printf("Enter NO.to be added  :");
					scanf("%d",&num);
					addNode(&first,num);
					printf("\t\tAdded!!\n\n");
					break;
				}
			case 3:
				{
					printf("\n\nIf u wanna delete some node enter the element of that node:");

					count=1;
					do
					{
						if(count==0)
							printf("Enter a valid Integer:");

						fflush(stdin);
						count=scanf("%d",&num);
					}while(count==0);
					 
					done=delNode(&first,num);
					if(done=='y')
						printf("\t\tdeleted!\n");
					else
						printf("\t\tNumber is not present in the list\n");
					
					break;
				}
			default:
				exit(1);
		}
	
	printf("Press any key..............");
	_getch();
	}while(operation>0 && operation <4);
}

void addNode(struct Node** first,int num)
{
	struct Node *temp=*first;
	struct Node *temp1,*prev;

	temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->Next=NULL;
	temp1->Prev=NULL;
	temp1->a=num;

	if(*first==NULL)
	{		
		*first=temp1;
	}

	else
	{
		if(temp->a>num)
		{			
			temp1->Next=*first;
			*first=temp1;
			temp->Prev=temp1;
		}
		else
		{
			while(temp!=NULL && temp->a<num )
			{
				prev=temp;
				temp=temp->Next;
			}
			
				prev->Next=temp1;
				temp1->Prev=prev;
				temp1->Next=temp;
				if(temp!=NULL)
			
					temp->Prev=temp1;
			
		}
	}
}
char delNode(struct Node** first,int num)
{
	struct Node *temp=*first,*prev;
	if(temp==NULL)
		return 'n';
	if(temp->a==num)
	{
		*first=temp->Next;
		(*first)->Prev=NULL;
		free(temp);	
		return 'y';

	}
	else
	{
		while(temp->a!=num)
		{
			prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{
				return 'n';		
			}
		}

		//prev=temp->Prev;
		prev->Next=temp->Next;
		free(temp);
		temp=prev->Next;
		temp->Prev=prev;
		return 'y';
	


	}

}
