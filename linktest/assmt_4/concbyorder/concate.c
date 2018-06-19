/* Program to merge two lists in order */
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void conc(struct Node** first,struct Node** second);
void addNode(struct Node** first,char* str);
//Global Structure used as Node in the lists
struct Node
{
	char* name;
	struct Node *Next;
};

void main()
{
	char* str;
	int count=0;
	struct Node *first=NULL,*second=NULL,*temp=NULL;
	
	printf("\nEnter the 4 elements of first list :\n");

	// Get the Strings to be added in the First list from the user
	for (count=1;count<=4;count++)
	{
		str=(char*)malloc(100);
		fflush(stdin);
		printf("Enter a Name(%d):",count);
		scanf("%s",str);
		realloc(str,strlen(str)+1);

		addNode(&first,str);//call the function add node to add this node to the list
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

		addNode(&second,str);
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
	
	conc(&first,&second);//call the function to merge list by order

	printf("List contains after merging:\n");
	temp=first;
	//Print the List after Merging 
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");
}
/*
* Function addNode to add a Node to the given List at appropriate position.
*	Parameters: Accepts the header of the list in which node is to be added.
*			  : Accepts the String which is to be added in the node.
*	Returns	  : Void.
*/

void addNode(struct Node** first,char* str)
{
	struct Node *temp;
	struct Node *temp1,*prev;
	
	temp=*first;
	// Create a NODE
	temp1=(struct Node*)malloc(sizeof(struct Node));//allocate Memory to the Node
	temp1->Next=NULL;
	temp1->name=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp1->name,str);//Copy the perticular String in the Node.

	if(*first==NULL)
	{	
		*first=temp1;// If no first Node make our Node as first node
	}

	else
	{
		if(strcmp(temp->name,str)==0 || strcmp(temp->name,str)>0)
		{//if the Node has to fit at the very first position change the appropriate pointers to do so.
			temp1->Next=*first;
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
			temp1->Next=temp;
				
		}
	}
}
/*
*Function to merge two list two form a single ordered List.
*	Parameters : Accepts Header of the first List.
*			   : Accepts Header of the second List.
*	Returns	   : Void.
*/
void conc(struct Node** first,struct Node** second)
{
	struct Node *temp, *temp2=*second;
	struct Node *temp1,*prev;
	
	while(temp2!=NULL)
	{//do till the Second List doen't end up.
		temp=*first;
		temp1=temp2->Next;
		
		if(strcmp(temp->name,temp2->name)==0 || strcmp(temp->name,temp2->name)>0)
		{//if the node of the Second list fits at the first postion Fit it and modify appropriate pointers.
			temp2->Next=temp;
			*first=temp2;
		}
		else
		{//Find the appropriate position and fit the node there
			while(temp!=NULL && strcmp(temp->name,temp2->name)<0)
			{
				prev=temp;
 				temp=temp->Next;
			}
			
			prev->Next=temp2;
			temp2->Next=temp;
			
		}
		temp2=temp1;					
	}
}
