#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"

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
        printf("\nEnter 1 or 2 or 3 or 4 for following operations !!\n 1) Display List \n 2) Add element to the list\n 3) Delete element from the list \n 4) Delete Every Second element \n any other key to exit\n");
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
					printf("\n\nIf u wanna delete some node enter the element of that node:");

					do
					{
						printf("Enter a valid Integer:");
						fflush(stdin);
						count=scanf("%s",&str);
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
					delete2nd(&first);
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

*/
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
	
