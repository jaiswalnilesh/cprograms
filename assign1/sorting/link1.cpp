#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	char name[10];
	char trade[10];
	struct node *link;
	int dob;
};

int xstrcmp(char *, char *);
void main()
{
	struct node * header,*temp=NULL;
	char info;
	int num;
	char name1[10];
	void addnode(struct node **, struct node**);
	void display(struct node *);
	void delete1(struct node **,char *);
	
	header=NULL;

	printf("\n");

	do
	{
		printf("\n");
		printf("1 Want to add the information of the candidates :");
		printf("\n");
		printf("2 Want to display the information of the candidates :");
		printf("\n");
		printf("3 Want to delete the information of any candidate :");
		printf("\n");
		printf("Enter your choice:");
		fflush(stdin);
		scanf("%d",&num);
		
		switch (num)
		{
		case 1 :
			do
			{
				temp=(struct node*) malloc(sizeof(node));
			
				printf("Enter the name:");
				scanf("%s",&temp->name);

				printf("Enter the trade:");
				scanf("%s",&temp->trade);
			
				printf("Enter the date of birth in dd/mm/yy:");
				scanf("%d",&temp->dob);
				addnode(&header,&temp);
	
				fflush(stdin);

				printf("You want to enter more information y/n:");
				scanf("%c",&info);
			}
	
		while(info=='y');
		break;
		
		case 2:	
				display(header);
				break;
	
			case 3:
		
				printf("\nEnter the name of the candidate whose information is to be delete :");
				fflush(stdin);
				scanf("%s",&name1);
				delete1(&header,name1);
				break;

			default:
				break;
		}	

	}
	while(num==1 || num==2 || num==3);
		
}
	
void addnode(struct node ** f_header,struct node **f_temp)
{
	struct node *prev= NULL, *temp;
			
	if(*f_header==NULL)
	{
		*f_header=*f_temp;
		(*f_header)->link=NULL;
	}
	else
	{
		temp= *f_header ;
		while(temp->link!=NULL && ((xstrcmp(temp->name, (*f_temp)->name))==-1))
		{
			prev=temp;
			temp=temp->link;
		}
		if(prev==NULL)
		{
			(*f_temp)->link=temp; 
			*f_header=*f_temp;
		}
		else
		{
			prev->link=*f_temp;
			(*f_temp)->link=temp;
					
		}
	}
}

void display(struct node*header_f)
{			
	struct node *temp;
	temp=header_f;

	printf("\n");
	
	printf("The information about the candidates are:");
	
	printf("\n");

	while(temp!=NULL)
	{
		printf("\n");

		printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",temp->name,temp->trade, temp->dob);
			
		temp=temp->link;
	
	printf("\n");
	}
}

int xstrcmp(char* s, char* d)
{
	while(1)
	{
		if(!*s && !*d)
			return 0 ;
		if(*s < *d)
			return -1	 ;
		if(*s > *d)
			return 1 ;
		s++ ;
		d++ ;
	}
}

void delete1(struct node ** f_header,char *name2)
{
	struct node * old,*temp;
	temp=*f_header;

	while(temp!=NULL)
	{
		if(!strcmp(temp->name, name2))
		{
			if(temp==*f_header)
			{
				*f_header=temp->link;
				free(temp);
				return;
			}
			else
			{
				old->link=temp->link;
				free(temp);
				return;
			}
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
	}
}

