
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void deleteList(struct Node **first);
void merge(struct Node** first,struct Node** second);
void addNode(struct Node** first,char* str);

int count=1;
struct Node
{
	char* name;
	struct Node *Next;
};

void main()
{
	char* str;
	int i=0;
	struct Node *first=NULL,*second=NULL,*temp=NULL;
	
	printf("\nEnter the 8 elements of first list :\n");

	for (count=1;count<=8;count++)
	{
		str=(char*)malloc(100);
		fflush(stdin);
		printf("Enter a Name(%d):",count);
		scanf("%s",str);
		realloc(str,strlen(str)+1);

		addNode(&first,str);
	}

	
	printf("\nEnter the 4 elements of Second list :\n");

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
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\nList two contains:\n");
	temp=second;
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");
	
	merge (&first,&second);

	printf("List contains after merging:\n");
	temp=first;
	while(temp!= NULL)
	{
		printf("\n %s",temp->name);
		temp=temp->Next;
	}

	printf("\n");

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

/*
void conc(struct Node** first,struct Node** second)
{
	struct Node *temp, *temp2=*second;
	struct Node *temp1,*prev;
	
	while(temp2!=NULL)
	{
		temp=*first;
		temp1=temp2->Next;
		if(strcmp(temp->name,temp2->name)==0 || strcmp(temp->name,temp2->name)>0)
		{
			temp2->Next=temp;
			*first=temp2;
		}
		else
		{
			while(strcmp(temp->name,temp2->name)<0 && temp->Next!=NULL)
			{
				prev=temp;
				temp=temp->Next;
			}
			
			if(temp->Next==NULL)
			{                    
				temp->Next=temp2;
				temp2->Next=NULL;
			}
			else
			{
				prev->Next=temp2;
				temp2->Next=temp;
			}
		}
		temp2=temp1;					
	}
}
*/
void merge(struct Node** first,struct Node** second)
{
	struct Node *temp, *temp2=*second;
	struct Node *temp1,*prev;
	temp=*first;
	
	while(temp->Next!=NULL && temp2->Next!=NULL)
	{
		prev=temp->Next;
		temp->Next=temp2;
		temp1=temp2->Next;
		temp2->Next=prev;
		temp=prev;
		temp2=temp1;

	}

	if(temp->Next==NULL)
	{
		temp->Next=temp2;	
	}

	if(temp2->Next==NULL)
	{
		prev=temp->Next;
		temp->Next=temp2;
		temp2->Next=prev;
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