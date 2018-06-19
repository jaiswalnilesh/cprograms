/* Program to create a Link List having two Header and two Next pointers 
*  First for  a list sorted by City Name.
*  One which is sorted by Year.
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

void addNode(struct Node**, struct Node**);
char delNode(struct Node**, struct Node**, char*);
char delNodeY(struct Node**, struct Node**, int);
void deleteList(struct Node**);

struct Node
{
	char city[25];
	int year;
	struct Node* Next1;
	struct Node* Next2;
};

void main()
{
	struct Node *first1,*first2,*temp;
	char *city_in,done;
	int op,year_in;
	first2=NULL;
	first1=first2;
	temp=first1;
	city_in=(char*)malloc(20);
	

	do
	{
		printf("\n1) Add a Node\n");
		printf("2) Display List\n");
		printf("3) Delete a Node By City Name\n");
		printf("4) Delete a Node By Year\n");
		printf("5) Exit");
		printf("\nEnter your Choice:  ");

		do
		{
			scanf("%d",&op);
			if(op<0 || op>5)
			{
				printf("\nEnter valid Number:  ");
			}
		}while(op<0 || op>5);


		switch(op)
		{
			case 1:
				{
					addNode(&first1,&first2);
					break;
				}
			case 2:
				{
					printf("\n\n1) City wise\n");
					printf("2) Year wise\n");
					printf("Enter your choice:  ");
					do
					{
						scanf("%d",&op);
						if(op<0 || op>2)
						{
							printf("\nEnter valid Number:  ");
						}
					}while(op<0 || op>2);

					if(op==1)
					{
						temp=first1;
					}
					else
					{
						temp=first2;
					}

					if(temp==NULL)
						printf("No Elements in the List\n");
					else while(temp!= NULL)
					{
						printf("\n %s  %d  \n",temp->city,temp->year);
						if(op==1)
							temp=temp->Next1;
						else
							temp=temp->Next2;
					}
					break;
				}
			case 3:
				{
					printf("\nEnter the City Name: ");
					scanf("%s",city_in);
					done=delNode(&first1,&first2,city_in);
					if(done=='y')
					{
						printf("\n\t\tDeleted....!!!!\n\n");	
					}
					else
					{
						printf("\n\t\tUnable to delete....!!!!\n\n");	
					}
					break;
				}
			case 4:
				{
					printf("\nEnter the Year: ");
					scanf("%d",&year_in);
					done=delNodeY(&first1,&first2,year_in);
					if(done=='y')
					{
						printf("\n\t\tDeleted....!!!!\n\n");	
					}
					else
					{
						printf("\n\t\tUnable to delete....!!!!\n\n");	
					}
					break;
				}
			default:
				{
					exit(1);
				}
		}

		fflush(stdin);
		printf("Press any key..............");

		_getch();

	}while(1);

	deleteList(&first1);
	first2=NULL;
	
}

/*
* Function to Free all the Memory allocated to the List
*	Parameters : Header of the List whose Nodes are to be deleted.
*	Returns    : Void.
*/
void deleteList(struct Node **first)
{
	struct Node *temp;
	while(*first!=NULL)
	{//Traverse till the end of the list deleting the Nodes
		temp=(*first)->Next1;
		free(*first);
		*first=temp;
	}
}

void addNode(struct Node** first1, struct Node** first2)
{
	char* str;
	struct Node  *temp1=*first1,*temp2=*first2,*prev,*temp;

	temp=(struct Node*)malloc(sizeof(struct Node));
	str=(char*)malloc(20);

	printf("Enter the City Name:");
	scanf("%s",str);

//	if(strcmp(str,"bbs")==0)
//		printf("");
	strcpy(temp->city,str);
	
	printf("Enter the Year:");
	while(scanf("%4d",&temp->year)==0)
	{
		printf("\nEnter the Valid Year:");
		fflush(stdin);
	}
	temp->Next1=NULL;
	temp->Next2=NULL;

	if(temp1==NULL)
	{
		*first1=temp;
		*first2=temp;
	}
	else
	{
			if(strcmp(temp1->city,temp->city)>0)
			{
				temp->Next1=*first1;
				*first1=temp;
			}
			
			else
			{
				while(temp1!=NULL && strcmp(temp1->city,temp->city)<0)
				{
					prev=temp1;
					temp1=temp1->Next1;
				}
				prev->Next1=temp;
				temp->Next1=temp1;
			}
			if(temp2->year>temp->year)
			{
				temp->Next2=*first2;
				*first2=temp;
			}
			else
			{
				while(temp2!=NULL && temp2->year<temp->year)
				{
					prev=temp2;
					temp2=temp2->Next2;
				}
				prev->Next2=temp;
				temp->Next2=temp2;
			}
		
	
	}
}

/*char delNode(struct Node** first1,struct Node** first2,char* city_in)
{
	struct Node *temp1=*first1,*temp2=*first2,*prev;
	if(*first1==NULL || *first2==NULL)
	{
		return 'n';
	}
	else
	{
		if(strtemp1->city,city_in)
		{
		
		
		}
	}
}
*/

/*
*Function to find and delete a node from the given List
*	Parameters : Struct Pointer indicating the List Header
			   : Name of the Node which has to be deleted from the List.
*	Returns	   : Char indicating successfull deletion.
*/
char delNode(struct Node** first1,struct Node** first2, char* city_in)
{
	struct Node *temp1,*temp2;
	struct Node *prev=NULL;
	temp1=*first1;
	temp2=*first2;
	if(temp1==NULL || temp2==NULL)//If no Elements in the List return that Deletion is not possible.
		return 'n';
	if(strcmp(temp1->city,city_in)==0)
	{//If the Node is at the Start position delete the node and change the Header of the List.
		*first1=temp1->Next1;
	}
	else
	{//Else traverse till the required Node
		while(strcmp(temp1->city,city_in)!=0)
		{
			prev=temp1;
			temp1=temp1->Next1;
			if(temp1==NULL)
			{//If node not found return 'n';
				return 'n';		
			}
		}
		// if the Node is found delete Node and change the appropriate Pointers.
			prev->Next1=temp1->Next1;
	}

	if(temp2==temp1)
		*first2=temp2->Next2;
	else
	{
		while(temp2!=temp1)
		{
			prev=temp2;
			temp2=temp2->Next2;
		}
		
		prev->Next2=temp2->Next2;
	}

	free(temp1);
	return 'y';
}

char delNodeY(struct Node** first1, struct Node** first2, int year_in)
{
	struct Node *temp1,*temp2;
	struct Node *prev=NULL;
	temp1=*first1;
	temp2=*first2;
	if(temp1==NULL || temp2==NULL)//If no Elements in the List return that Deletion is not possible.
		return 'n';
	if(temp2->year==year_in)
	{//If the Node is at the Start position delete the node and change the Header of the List.
		*first2=temp2->Next2;
	}
	else
	{//Else traverse till the required Node
		while(temp2->year != year_in)
		{
			prev=temp2;
			temp2=temp2->Next2;
			if(temp2==NULL)
			{//If node not found return 'n';
				return 'n';		
			}
		}
		// if the Node is found delete Node and change the appropriate Pointers.
			prev->Next2=temp2->Next2;
	}

	if(temp2==temp1)
		*first1=temp1->Next1;
	else
	{
		while(temp2!=temp1)
		{
			prev=temp1;
			temp1=temp1->Next1;
		}
		
		prev->Next1=temp1->Next1;
	}

	free(temp2);
	return 'y';

}
