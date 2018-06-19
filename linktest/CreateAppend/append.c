/*Program to create a link list and append some elements to it */

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void addNode(struct Node**);
void setData(struct Node*);
int count=1;
struct Node
{
	char* name;
	struct Node *Next;
};

void main()
{
	int i=0;
	struct Node *first=NULL,*temp=NULL;
	
	for (count=1;count<=4;count++)
	{
		addNode(&first);
	}

	temp=first;
	i=0;

	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}
}

void addNode(struct Node** first)
{
	struct Node *temp=*first;

	if(*first==NULL)
	{
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->Next=NULL;
		*first=temp;
		setData(temp);
	}

	else
	{
		while(temp->Next != NULL)
			temp=temp->Next;

		temp->Next=(struct Node*)malloc(sizeof(struct Node));
		temp=temp->Next;
		temp->Next=NULL;
		
		setData(temp);
	}
}


void setData(struct Node* temp)
{
	temp->name=(char*)malloc(100);
	fflush(stdin);
	printf("Enter a Name(%d):",count);
	scanf("%s",temp->name);
	realloc(temp->name,strlen(temp->name)+1);

}


