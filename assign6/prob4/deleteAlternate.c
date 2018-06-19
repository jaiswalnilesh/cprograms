#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node* ptr;
};

void main()
{
	struct node *first=NULL;

	int choose();
	void add(struct node **first);
	void interChange(struct node **first);
	void deleteList(struct node **first);
	void display(struct node *first,char flag);
	void insert(struct node **first);
	void removeNode(struct node **first);
	void deleteAlternate(struct node **first);

	while(1)
	{
		switch(choose())
		{
		case 1:
			add(&first);
			break;
		case 2:
			insert(&first);
			break;
		case 3:
			interChange(&first);
			break;
		case 4:
			display(first,'y');
			break;
		case 5:
			removeNode(&first);
			break;
		case 6:
			deleteAlternate(&first);
			break;
		case 7:
			printf("\n\tReally Exit?(y to exit) ");
			fflush(stdin);
			if(getchar()=='y')
			{
				deleteList(&first);
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
	int choice;
	printf("\n\n\nEnter Any One : \n\t1)Add A Node\n\t2)Insert A Node\n\t3)Interchange 2 Nodes\n\t4)Display List\n\t5)Remove A Node\n\t6)Delete Alternet Nodes\n\t7)Exit\nYour Choice : ");
	fflush(stdin);
	while((scanf("%d",&choice)==0)||(choice<1)||(choice>7))
	{
		printf("\n\n\t\tEnter VALID Choice Value : ");
		fflush(stdin);
	}
	return(choice);
}

void setData(struct node *temp)
{
	printf("\n\n\t\tEnter Node Data: ");
	fflush(stdin);
	while(scanf("%d",&temp->data)==0)
	{
		printf("\n\n\t\tEnter VALID Node Value: ");
		fflush(stdin);
	}
}

/*
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

*/
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
			printf("\n\n Node Number : %d",count++);
			printf("\n\tNode Vaue \t:\t%d",first->data);

			first=first->ptr;
		}
		if(flag=='y')
			printf("\n\n\tPress Any Key......");
	}
}

void removeNode(struct node **first)
{
	struct node *current=*first,*prev=*first;
	int nodeValue;
	if(*first==NULL)
	{
		printf("\n\n\tLIST EMPTY...Press Any Key....");
		return;
	}
	else
	{
		printf("\n\nAvailable Nodes Are : \n");
		display(*first,'n');
		printf("\n\nEnter The Value Of The Node To Be DELETED : ");
		fflush(stdin);
		while(scanf("%d",&nodeValue)==0)
		{
			fflush(stdin);
			printf("\n\nEnter The VALID Value Of The Node To Be DELETED : ");
		}

		while(current!=NULL)
		{
			if(current->data==nodeValue)
			{
				printf("\n\t\tNode Found!!!!REALLY DELETE?('y' to Delete) ");
				if(_getche()=='y')
				{
					if(current==*first)
						*first=(*first)->ptr;
					else if(current!=NULL)
						prev->ptr=current->ptr;
					else 
						prev->ptr=current;
					free(current);
					printf("\n\t\tNODE DELETED .... Press Any Key....");
				}
				return;
			}
			prev=current;
			current=current->ptr;
		}		
	}
	printf("\nWARNING!!!!Node NOT Found.... Try Again Later ....Press Any Key....");
}

void interChange(struct node **first)
{
	struct node *curr1,*curr2,*prev1,*prev2,*temp;
	int nodeValue1,nodeValue2;	
	curr1=curr2=prev1=prev2=*first;
	
	if((*first==NULL)||((*first)->ptr==NULL))
	{
		printf("\n\n\tLIST IS NOT HAVING ENOUGH NODES TO INTERCHANG: ");
		printf("\n\t\tNode Cannot Be Interchanged .... Press Any Key....");
		return;
	}
	else
	{
		printf("\n\nAvailable Nodes Are : \n");
		display(*first,'n');

		printf("\n\nEnter First Node Value : ");
		fflush(stdin);
		while(scanf("%d",&nodeValue1)==0)
		{
			fflush(stdin);
			printf("\n\nEnter VALID First Node Value: ");
		}

		while(curr1!=NULL)
		{
			if(curr1->data==nodeValue1)
				break;
			prev1=curr1;
			curr1=curr1->ptr;
		}
		if(curr1==NULL)
		{
			printf("\n\nFIRST NODE NOT FOUND ");
			printf("\n\t\tNode Cannot Be Interchanged .... Try Again Later ....Press Any Key....");
			return;
		}

		printf("\n\nEnter Second Node Value : ");
		fflush(stdin);
		while((scanf("%d",&nodeValue2)==0)||(nodeValue2!=nodeValue1))
		{
			fflush(stdin);
			printf("\n\nEnter VALID Second Node Value: ");
		}
		
		while(curr2!=NULL)
		{
			if(curr2->data==nodeValue2)
				break;
			prev2=curr2;
			curr2=curr2->ptr;
		}
		if(curr2==NULL)
		{
			printf("\n\nSECOND NODE NOT FOUND ");
			printf("\n\t\tNode Cannot Be Interchanged .... Try Again Later ....Press Any Key....");
			return;
		}
		printf("\n\t\tNodes Found!!!!REALLY INTERCHANGE?('y' to Interchange) ");
		fflush(stdin);
		if(_getche()=='y')
		{

			temp=curr1->ptr;

			if(curr2!=prev1)
				curr1->ptr=curr2->ptr;
			else
				curr1->ptr=curr2;

			if(curr1!=prev2)
				curr2->ptr=temp;
			else
				curr2->ptr=curr1;

			

			if((prev1!=curr2)&&(prev1!=curr1))
				prev1->ptr=curr2;

			if((curr1!=prev2)&&(curr2!=prev2))
				prev2->ptr=curr1;


			if(curr1==*first)
				*first=curr2;
			else if(curr2==*first)
				*first=curr1;		

			printf("\n\t\tNode Are Interchanged .... Press Any Key....");
		}
		else
			printf("\n\n\n\t\tNODE INTERCHANGE INTERRUPTED .... Press Any Key....\n");

	}
}



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



void add(struct node **first)
{
	struct node *temp=*first;

	if(*first==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\n\t\tEnter Node Value : ");
		fflush(stdin);
		while(scanf("%d",&temp->data)==0)
		{
			printf("\n\n\t\tEnter VALID Node Value : ");
			fflush(stdin);
		}
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
		while(scanf("%d",&temp->data)==0)
		{
			printf("\n\n\t\tEnter VALID Node Value : ");
			fflush(stdin);
		}
		temp->ptr=NULL;
	}
	printf("\n\t\tNode Added .... Press Any Key....");
}

void deleteList(struct node **first)
{
	struct node *temp=*first;
	while((*first)!=NULL)
	{
		temp=*first;
		*first=(*first)->ptr;
		free(temp);
	}
}

void deleteAlternate(struct node **first)
{
	int count=0;
	struct node *temp=*first,*temp1=*first,*temp2=*first;
	if((*first!=NULL)&&((*first)->ptr!=NULL))
	{
		while(temp!=NULL)
		{
			if((count++)%2)
			{
				temp1=temp;		
				if(temp==(*first)->ptr)
					(*first)->ptr=temp->ptr;
				temp2=temp2->ptr=temp->ptr;
				temp=temp->ptr;
				free(temp1);
			}
			else
				temp=temp->ptr;
		}
		printf("\n\t\tAlternate Nodes Are Deleted .... Press Any Key....");
	}
	else
		printf("\n\t\t\t\tNot Enough Nodes!!!!!\n\t\tAlternate Nodes Cannot Be Deleted .... Press Any Key....");

}

