/* Program to append one list to another */
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void addNode(struct Node**);
void setData(struct Node*);
void deleteList(struct Node**);

int count=1;
//Global Struture used to create list 
struct Node
{
	char* name;
	struct Node *Next;
};

void main()
{
	int i=0;
	struct Node *first=NULL,*second=NULL,*temp=NULL;
	
	printf("\nEnter the 4 elements of first list :\n");

	for (count=1;count<=4;count++)
	{//Get four elements of first list from the user
		addNode(&first);
	}

	
	printf("\nEnter the 4 elements of Second list :\n");

	for (count=1;count<=4;count++)
	{//Get four elements of list two from the user
		addNode(&second);
	}


	
	i=0;

	printf("List one contains:\n");
	temp=first;

	//print first List
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\nList two contains:\n");
	temp=second;

	//print Second List
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");
//append second list
	{
	temp=first;
	while(temp->Next!=NULL)	//traverse till end of first list
		temp=temp->Next;
	temp->Next=second;//make end pointer of first list pointing to start of second list
	}

	printf("List contains after appending:\n");
	temp=first;

	//Print the new List
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");

	deleteList(&first);//free the allocated memory
}
/*
*Function to add a node at the end of the given list.
*	Parameters : Struct Double Pointer indicating the head of the input list 
*	Returns	   : Void
*/
void addNode(struct Node** first)
{
	struct Node *temp=*first;

	if(*first==NULL)//If there is no element in the list add one.
	{
		temp=(struct Node*)malloc(sizeof(struct Node));//create a node
		temp->Next=NULL;// make next of it as NULL
		*first=temp;// Make it as Header of the list.
		setData(temp);//Set the Data of that node
	}

	else
	{//IF Elements are there in the list traverse till the end of the list.
		while(temp->Next != NULL)
			temp=temp->Next;
	// Create a node and set the data of that node.	
		temp->Next=(struct Node*)malloc(sizeof(struct Node));
		temp=temp->Next;
		temp->Next=NULL;
		
		setData(temp);
	}
}
/*
*Function to set the data of a given NODE.
*	Parameters :struct pointer indicating node whose data is to be set.
*	Returns	   :Void  
*/

void setData(struct Node* temp)
{
	temp->name=(char*)malloc(100);//Allocate Memory to the string in structure
	fflush(stdin);
	printf("Enter a Name(%d):",count);
	scanf("%s",temp->name);//Get the input from the user to set the Data
	realloc(temp->name,strlen(temp->name)+1);

}
/*
* Function which frees all the Memory allocated to the list
*	Parameters: List Header which has to be deleted or whose memory is to be freed.
*	Returns	  : Void.	
*/
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


