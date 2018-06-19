/* Program to merge two lists in order */
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

//void conc(struct Node** first,struct Node** second,struct Node** last);
void addNode(struct Node**,struct Node **last,char* str);
void deleteList(struct Node **first);
void merge(struct Node** first,struct Node** second,struct Node** last,struct Node **last2);
//Global Structure used as Node in the lists
struct Node
{
	char* name;
	struct Node *Next;
	struct Node *Prev;
};

void main()
{
	char* str;
	int count;
	struct Node *first=NULL,*second=NULL,*temp=NULL,*last1=NULL,*last2=NULL;
	
	printf("\nEnter the 4 elements of first list :\n");

	// Get the Strings to be added in the First list from the user
	for (count=1;count<=4;count++)
	{
		str=(char*)malloc(100);
		fflush(stdin);
		printf("Enter a Name(%d):",count);
		scanf("%s",str);
		realloc(str,strlen(str)+1);

		addNode(&first,&last1,str);//call the function add node to add this node to the list
	}

	//sortList(&first);

	
	printf("\nEnter the 4 elements of Second list :\n");

	// Get the Strings to be added in the First list from the user

	for (count=1;count<=4;count++)
	{
		str=(char*)malloc(100);
		fflush(stdin);
		printf("Enter a Name(%d):",count);
		scanf("%s",str);
		realloc(str,strlen(str)+1);

		addNode(&second,&last2,str);
	}
		
	printf("List one contains:\n");
	temp=first;
	//Print the first List
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\nList two contains:\n");
	temp=second;
	//Print the second List
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");
	merge(&first,&second,&last1,&last2);
	
	printf("List contains after merging:\n");
	temp=first;
	//Print the List after Merging 
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	temp=last1;
	printf("\nLast to First"); 
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Prev;
	}

	printf("\n");
	deleteList(&first);
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


void merge(struct Node** first,struct Node** second,struct Node **last,struct Node **last2)
{
	struct Node *temp, *temp2=*second;
	struct Node *temp1,*prev,*sto1,*sto2;
	temp=*first;
	
	while(temp!=NULL && temp2!=NULL)
	{
		sto1=temp;
		sto2=temp2;
		prev=temp->Next;
		temp->Next=temp2;
		temp2->Prev=temp;
		if(prev!=NULL)
			prev->Prev=temp2;
		temp1=temp2->Next;
		if(prev!=NULL)
			temp2->Next=prev;
		else 
		{
			temp2->Next=temp1;
			if(temp1!=NULL)
				temp1->Prev=temp2;
		}
		temp=prev;
		temp2=temp1;
		if(temp==NULL)
			*last=*last2;
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
