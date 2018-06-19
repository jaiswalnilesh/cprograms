#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int choose(int firstOrSecond);
void addSorted(struct node **first);
void mergeSorted(struct node **first,struct node *second);
void interChange(struct node **first);
void deleteList(struct node **first);
void display(struct node *first,char flag);
void insert(struct node **first);
void removeNode(struct node **first);
void createList(struct node **head,int firstOrSecond);
struct node* concatAndOrderList(struct node **first,struct node *second);

struct node
{
	int data;
	struct node* ptr;
};


void main()
{
	struct node *first,*second;
	do
	{		
		first=second=NULL;
		createList(&first,1);
		createList(&second,2);
		printf("\n\n\t\t\tConcatinated Lists Are \n");
		display(concatAndOrderList(&first,second),'y');
		printf("\n\n\t\tDo You Want To Enter Again : (y to continue)");
		fflush(stdin);
		deleteList(&first);
//		deleteList(&second);
	}while(getchar()=='y');
}

void createList(struct node **head,int firstOrSecond)
{
	int i=0;
	while(i!=4)
	{
		switch(i=choose(firstOrSecond))
		{
		case 1:
			addSorted(head);
			break;
/*		case 2:
			insert(head);
			break;
		case 3:
			interChange(head);*/
			break;
		case 2:
			display(*head,'y');
			break;
		case 3:
			removeNode(head);
			break;
		case 5:
			printf("\n\tReally Exit?(y to exit) ");
			fflush(stdin);
			if(getchar()=='y')
			{
				deleteList(head);
				printf("\n");
				exit(0);
			}
			else
				printf("\n\n\t\t!!!!Don't Waste My Time!!!!!\n");
		}
		if(i==4)
			printf("%s List Completed......Press Any Key.....",(firstOrSecond==1?"First":"Second"));
		fflush(stdin);
		_getch();
	}
	
}


struct node* concatAndOrderList(struct node **first,struct node *second)
{
	struct node **temp;
	struct node *tempSecond=second,*tempSecond2=second;
	temp=first;
	if(*first==NULL)
		return second;
	else if(second==NULL)
		return *first;
	else
		while(second!=NULL)
		{
			tempSecond=second->ptr;
			mergeSorted(temp,second);
			second=tempSecond;
		}
	second=tempSecond2;
	return *first;
}


int choose(int firstOrSecond)
{
	int choice;
	printf("\n\n\n\t\t\t\t%s List Creation\n",(firstOrSecond==1?"First":"Second"));
	printf("\n\n\nEnter Any One : \n\t1)Add A Node\n\t2)Display List\n\t3)Remove A Node\n\t4)Enough Elements\n\t5)Exit\nYour Choice : ");
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


void mergeSorted(struct node **first,struct node *second)
{
	struct node *current=*first,*prev=*first;	
	void setData(struct node *temp);

	if(*first==NULL)
	{
		*first=second;
		(*first)->ptr=NULL;
	}
	else
	{
		while((current!=NULL)&&(current->data<second->data))
		{
			prev=current;
			current=current->ptr;
		}
		if(current!=*first)
			prev->ptr=second;
		else
			*first=second;
		second->ptr=current;		
	}
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


void addSorted(struct node **first)
{
	struct node *current=*first,*prev=*first,*temp;	
	void setData(struct node *temp);

	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n\n\t\tEnter Node Value : ");
	fflush(stdin);
	while(scanf("%d",&temp->data)==0)
	{
		printf("\n\n\t\tEnter VALID Node Value : ");
		fflush(stdin);
	}

	if(*first==NULL)
	{
		*first=temp;
		(*first)->ptr=NULL;
	}
	else
	{
		while((current!=NULL)&&(current->data<temp->data))
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
	printf("\n\t\tNode Added .... Press Any Key....");
}
