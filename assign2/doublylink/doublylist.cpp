#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	char name[10];
	char trade[10];
	struct node *nlink, *plink;
	int dob;
};

int xstrcmp(char *, char *);
void main()
{
	struct node * header, *temp=NULL;
	char info;
	int num;
	char name1[10];
	void addnode(struct node **, struct node**);
	void display(struct node *);
	void delete1(struct node **, char *);
	
	header=NULL;

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
	printf("\n");

	do
	{
		printf("\n");
		printf("1 Want to display the information of the candidates :");
		printf("\n");
		printf("2 Want to delete the information of any candidate :");
		printf("\n");
		printf("Enter your choice:");
		fflush(stdin);
		scanf("%d",&num);
		
		switch (num)
		{
			case 1:	
				display(header);
				break;
	
			case 2:
		
				printf("\nEnter the name of the candidate whose information is to be delete :");
				fflush(stdin);
				scanf("%s",&name1);
				delete1(&header,name1);
				break;

			default:
				break;
		}	

	}
	while(num==1 || num==2);
		
}
	
void addnode(struct node ** f_header, struct node **f_temp)
{
	struct node *prev= NULL, *temp;
			
	if(*f_header==NULL)
	{
		*f_header=*f_temp;
		(*f_header)->plink=NULL;
		(*f_header)->nlink=NULL;
	}
	else
	{
		temp= *f_header ;
		while(temp->nlink!=NULL && ((xstrcmp(temp->name, (*f_temp)->name))==-1))
				temp=temp->nlink;
		
		if(temp->plink==NULL && ((xstrcmp(temp->name, (*f_temp)->name))==1))
		{
			(*f_temp)->nlink=*f_header;
			(*f_header)->plink=*f_temp;
			*f_header=*f_temp;
			(*f_temp)->plink=NULL;
		}
		else
			if(temp->plink==NULL)
			{
				(*f_temp) -> plink = temp;
				(*f_temp) -> nlink = temp -> nlink;
				temp -> nlink = *f_temp;
			}
	
			else
			{
				(*f_temp)->plink = temp -> plink;
				(*f_temp)->nlink = temp;
				temp -> plink -> nlink = (*f_temp);
				temp -> plink = (*f_temp);
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

	while(temp->nlink!=NULL)
	{
		printf("\n");

		printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",temp->name,temp->trade, temp->dob);
			
		temp=temp->nlink;
	
	printf("\n");
	}

	printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",temp->name,temp->trade, temp->dob);
	

	printf("\n");

	while(temp!=NULL)
	{
		printf("\n");

		printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",temp->name,temp->trade, temp->dob);
			
		temp=temp->plink;
	
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
				*f_header=temp->nlink;
				(*f_header)->plink=NULL;
				free(temp);
				return;
			}
			else
			{
				old->nlink=temp->nlink;
				temp->nlink->plink=old;
				free(temp);
				return;
			}
		}
		else
		{
			old=temp;
			temp=temp->nlink;
		}
	}
}

