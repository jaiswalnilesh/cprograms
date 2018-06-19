#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char fName[10];
	char mName[10];
	char lName[10];
	int batchNo;
	struct node* ptr;
};

void main()
{
	struct node *first=NULL;
//	int i;

	int choose();
	void add(struct node **first);
	void addSorted(struct node **first);
	void display(struct node *first,char flag);
	void insert(struct node **first);
	void removeNode(struct node **first);

	while(1)
	{
		switch(choose())
		{
		case 1:
			addSorted(&first);
			break;
		case 2:
			display(first,'y');
			break;
		case 3:
			removeNode(&first);
			break;
		case 4:
			printf("\n\tReally Exit?(y to exit) ");
			fflush(stdin);
			if(getchar()=='y')
			{
				printf("\n");
				exit(0);
			}
			else
				printf("\n\n\t\t!!!!Don't Waste My Time!!!!!\n");
		}
		fflush(stdin);
		_getch();
	}
}

int choose()
{
	printf("\n\n\nEnter Any One : \n\t1)Add A Candidate\n\t2)Display Candidate List\n\t3)Remove A Candidate\n\t4)Exit\nYour Choice : ");
	fflush(stdin);
	return((getchar())-48);
}

void setData(struct node *temp)
{
	fflush(stdin);
	printf("\n\n\t\tEnter Candidate's First Name : ");
	fflush(stdin);
	scanf("%s",temp->fName);

	printf("\n\n\t\tEnter Candidate's Middle Name : ");
	fflush(stdin);
	scanf("%s",temp->mName);

	printf("\n\n\t\tEnter Candidate's Last Name : ");
	fflush(stdin);
	scanf("%s",temp->lName);

	printf("\n\n\t\tEnter Candidate's Batch Number : ");
	fflush(stdin);
	while(scanf("%d",&temp->batchNo)==0)
	{
		printf("\n\n\t\tEnter VALID Batch Number : ");
		fflush(stdin);
	}
}


void addSorted(struct node **first)
{
	struct node *current=*first,*prev=*first,*temp;	
	void setData(struct node *temp);

	temp=(struct node *)malloc(sizeof(struct node));
	setData(temp);	

	if(*first==NULL)
	{
		*first=temp;
		(*first)->ptr=NULL;
	}
	else
	{
		while((current!=NULL)&&(strcmp(current->fName,temp->fName)<0))
		{
			prev=current;
			current=current->ptr;
		}
		if(current!=*first)
			prev->ptr=temp;
		else
			*first=temp;
		temp->ptr=current;		
	}
	printf("\n\t\tCandidate Added .... Press Any Key....");
}


void display(struct node *first,char flag)
{
	int count=1;
	if(first==NULL)
		printf("\n\n\t\tLIST EMPTY");
	else
	{
		if(flag=='y')
			printf("\n\n\nList Is.....\n\n");
		while(first!=NULL)
		{
			printf("\n\n Candidate Number : %d",count++);
			printf("\n\t First Name \t:\t%s",first->fName);
			printf("\n\t Middle Name \t:\t%s",first->mName);
			printf("\n\t Last Name \t:\t%s",first->lName);
			printf("\n\tBatch Number \t:\t%d",first->batchNo);

			first=first->ptr;
		}
		if(flag=='y')
			printf("\n\n\tPress Any Key......");
	}
}

void removeNode(struct node **first)
{
	struct node *current=*first,*prev=*first;
	char canName[10];	
	if(*first==NULL)
	{
		printf("\n\n\tLIST EMPTY...Press Any Key....");
		return;
	}
	else
	{
		printf("\n\nAvailable Nodes Are : \n");
		display(*first,'n');
		printf("\n\nEnter The Name Of The Candidate To Be DELETED : ");
		fflush(stdin);
		scanf("%s",canName);

		while(current!=NULL)
		{
			if(strcmp(current->fName,canName)==0)
			{
				printf("\n\t\tCandidate Found!!!!REALLY DELETE?('y' to Delete) ");
				if(_getche()=='y')
				{
					if(current==*first)
						*first=(*first)->ptr;
					else if(current!=NULL)
						prev->ptr=current->ptr;
					else 
						prev->ptr=current;
					free(current);
					printf("\n\t\tCANDIDATE DELETED .... Press Any Key....");
				}
				return;
			}
			prev=current;
			current=current->ptr;
		}		
	}
	printf("\nWARNING!!!!Candidate NOT Found.... Try Again Later ....Press Any Key....");
}
/*
void insert(struct node **first)
{
	struct node *temp=*first,*temp1;
	int nodeValue;	
	if(*first==NULL)
	{
		printf("\n\n\tLIST EMPTY...INSERTING THE NODE AT START: ");
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\n\t\tEnter Node Value : ");
		fflush(stdin);
		scanf("%d",&temp->data);
		*first=temp;
		(*first)->ptr=NULL;
		printf("\n\t\tNode Inserted .... Press Any Key....");
		return;
	}
	else
	{
		printf("\n\nEnter The Node Value After Which Node Is To Be Inserted : ");
		fflush(stdin);
		scanf("%d",&nodeValue);

		while(temp!=NULL)
		{
			if(temp->data==nodeValue)
			{
				temp1=(struct node *)malloc(sizeof(struct node));
				temp1->ptr=temp->ptr;
				temp->ptr=temp1;
				printf("\n\n\t\tEnter Node Value : ");
				fflush(stdin);
				scanf("%d",&temp1->data);
				printf("\n\t\tNode Inserted .... Press Any Key....");
				return;
			}
			temp=temp->ptr;
		}
		
	}
	printf("\n\t\tNode Cannot Be Inserted .... Try Again Later ....Press Any Key....");
}

*/
/*
void add(struct node **first)
{
	struct node *temp=*first;

	if(*first==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\n\t\tEnter Node Value : ");
		fflush(stdin);
		scanf("%d",&temp->data);
		*first=temp;
		(*first)->ptr=NULL;
	}
	else
	{
		while(temp->ptr!=NULL)
			temp=temp->ptr;
		temp->ptr=(struct node *)malloc(sizeof(struct node));
		temp=temp->ptr;
		printf("\n\n\t\tEnter Node Value : ");
		fflush(stdin);
		scanf("%d",&temp->data);
		temp->ptr=NULL;
	}
	printf("\n\t\tNode Added .... Press Any Key....");
}
*/