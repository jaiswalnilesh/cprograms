/* Program to search an element from the List and display its details */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

struct Node
{
	char *name;
	char *lName;
	int age;
	struct Node* Prev;
	struct Node* Next;
};

void display(struct Node** first,char* str);
void addNode(struct Node** first,struct Node **last,char* str);

void main()
{
	struct Node *first=NULL,*temp=NULL,*last=NULL;
	
	char op,test,*str;

	do
	{
		test=1;
		printf("\nEnter Your Choice");
		printf("\n1) Add Node");
		printf("\n2) Display Node");
		printf("\n3) Exit\n \t\t");
		do 
		{
			fflush(stdin);
			test=scanf("%d",&op);

			if(op>3 || op<1 || test==0)
				printf("\n Enter Valid No.::");

		}while(op>3 || op<1 || test==0);


		switch (op)
		{
		case 1:
			{
				fflush(stdin);
				printf("\nEnter First NAME to be added  :");
				str=malloc(20);
				scanf("%s",str);
				addNode(&first,&last,str);
				printf("\t\tAdded!!\n\n");
				break;
			}
		case 2:
			{
				printf("\nEnter First NAME of the Candidate :");
				str=malloc(20);
				scanf("%s",str);
				display(&first,str);
				break;
			}
		case 3:
			{
				break;
			}
		}
		printf("\n\t\tPress Some key....");
		fflush(stdin);
		_getch();

	}while(op);
		
	
}

/*
* Function addNode to add a Node to the given List at appropriate position.
*	Parameters: Accepts the header of the list in which node is to be added.
*			  : Accepts the String which is to be added in the node.
*	Returns	  : Void.
*/

void addNode(struct Node** first,struct Node **last,char* str)
{
	struct Node *temp;
	struct Node *temp1,*prev;
	
	temp=*first;
	// Create a NODE
	temp1=(struct Node*)malloc(sizeof(struct Node));//allocate Memory to the Node
	temp1->Next=NULL;
	temp1->Prev=NULL;
	temp1->name=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp1->name,str);//Copy the perticular String in the Node.

	fflush(stdin);
	temp1->lName=(char*)malloc(20);
	printf("\nEnter the Last Name: ");
	scanf("%s",temp1->lName);
	printf("\nEnter the Age: ");
	scanf("%d",&temp1->age);

	if(*first==NULL)
	{	
		*first=temp1;// If no first Node make our Node as first node
		*last=temp1;
	}

	else
	{
		if(strcmp(temp->name,str)==0 || strcmp(temp->name,str)>0)
		{//if the Node has to fit at the very first position change the appropriate pointers to do so.
			temp1->Next=*first;
			(*first)->Prev=temp1;
			*first=temp1;
		}
		else
		{
			//Else find the appropriate position of the Node Compairing its String(Element) with already present List Elements.
			while(temp!=NULL && (strcmp(temp->name,str))<0 )
			{
				prev=temp;
				temp=temp->Next;
			}
			//Fit the node at the found Position
		   	prev->Next=temp1;
			temp1->Prev=prev;
			temp1->Next=temp;
			if(temp!=NULL)
				temp->Prev=temp1;
			if(temp==NULL)
				*last=temp1;
		}
	}
}


void display(struct Node** first,char* str)
{
	struct Node *Gtemp=*first;
	
	if(Gtemp==NULL)
	{
		printf("\nNo List is present\n");
		return;
	}

	while(strcmp(Gtemp->name,str)!=0)
	{
		Gtemp=Gtemp->Next;
		if(Gtemp==NULL)
		{
			printf("\nNo Such Node is present\n");
			return;
		}
	}

	printf("\n FName: %s  \n Lname: %s  \n Age: %d \n",Gtemp->name,Gtemp->lName,Gtemp->age);
	
}
				