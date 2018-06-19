#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
char forwardNode(struct Node **first,char* str,int factor);
void deleteList(struct Node **first);
void addNode(struct Node**,char* str);
char delNode(struct Node**,char* str);
void delete2nd(struct Node **first);

int count=1;

struct Node
{
	char* name;
	struct Node *Next;
};

void main()
{
	int i=0,operation;
	char done,*str;
	struct Node *first=NULL,*temp=NULL;

	do
	{
		fflush(stdin);
        printf("\nEnter 1 or 2 or 3 or 4 for following operations !!\n 1) Display List \n 2) Add element to the list\n 3) Delete element from the list \n 4) forward node \n any other key to exit\n");
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
					else while(temp!= NULL)
					{
						printf("\n %s\n",temp->name);
						temp=temp->Next;
					}
					break;
				}
			case 2:
				{
					fflush(stdin);
					printf("Enter NAME to be added  :");
					str=malloc(100);
					scanf("%s",str);
					addNode(&first,str);
					printf("\t\tAdded!!\n\n");
					break;
				}

			case 3:
				{
					//str1=(char*)malloc(12);
					printf("\n\nIf u wanna delete some node enter the element of that node:");

					do
					{
						printf("Enter a valid Integer:");
						fflush(stdin);
						count=scanf("%s",str);
					}while(count==0);
					 
					done=delNode(&first,str);
					if(done=='y')
						printf("\t\tdeleted!\n");
					else
						printf("\t\tName is not present in the list\n");
					
					break;
				}
				
			case 4:
				{
					//delete2nd(&first);
					//break;
					//str1=(char*)malloc(12);
					printf("Enter Node Name:\n");
					scanf("%s",str);
					printf("Enter Factor");
					while(scanf("%d",&count)==0 || count<0 )
					{
						printf("\nEnter valid no.\n");
					}
					done=forwardNode(&first,str,count);
					if(done=='y')
					{
						printf("done");
					}
					else
					{
						printf("Failed\n");
					}
					break;
				}
			default:
				exit(1);
		}
	fflush(stdin);
	printf("Press any key..............");
	_getch();
	}while(operation>0 && operation <5);
	deleteList(&first);
}

void addNode(struct Node** first,char* str)
{
	struct Node *temp;
	struct Node *temp1,*prev;
	
	temp=*first;

	temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->Next=NULL;
	temp1->name=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp1->name,str);

	if(*first==NULL)
	{	
		*first=temp1;
	}

	else
	{
		if(strcmp(temp->name,str)==0 || strcmp(temp->name,str)>0)
		{
			temp1->Next=*first;
			*first=temp1;
		}
		else
		{
		
			while(temp!=NULL && (strcmp(temp->name,str))<0 )
			{
				prev=temp;
				temp=temp->Next;
			}
		    prev->Next=temp1;
			temp1->Next=temp;
				
		}
	}
}

char delNode(struct Node** first,char* str)
{
	struct Node *temp=*first,*prev;
	if(temp==NULL)
		return 'n';
	if(strcmp(temp->name,str)==0)
	{
		*first=temp->Next;
		free(temp);	
		return 'y';

	}
	else
	{
		while(strcmp(temp->name,str)!=0)
		{
			prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{
				return 'n';		
			}
		}

			prev->Next=temp->Next;
			free(temp);
			return 'y';
	}

}

void delete2nd(struct Node **first)
{
	struct Node *temp=*first,*prev;
	char count=1;

	while(temp !=NULL)
	{
		if(count%2==0)
		{
			prev->Next=temp->Next;
			free(temp);
			temp=prev;
			count=0;
		}
		prev=temp;
		temp=prev->Next;
		count++;
		
	}

}
void deleteList(struct Node **first)
{
	struct Node *temp;
	while(*first!=NULL)
	{
		temp=(*first)->Next;
		free(*first);
		*first=temp;
	}
}
	
char forwardNode(struct Node **first,char* str,int factor)
{
	struct Node *temp=*first,*prev,*temp1=temp;
	if(temp==NULL)
		return 'n';
	if(strcmp(temp->name,str)==0)
	{
		*first=temp->Next;
		//return 'y';
	}
	else
	{
		while(temp!=NULL && strcmp(temp->name,str)!=0)
		{
			prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{
				return 'n';		
			}
		}

		prev->Next=temp->Next;
		temp1=temp;
	}
		
		for(;temp1!=NULL && factor>=0;factor--)
		{
			prev=temp1;
			temp1=temp1->Next;
		}
		if(temp1==NULL)
			return 'n';
		else
		{
			prev->Next=temp;
			temp->Next=temp1;
			return 'y';
		}
			

}
