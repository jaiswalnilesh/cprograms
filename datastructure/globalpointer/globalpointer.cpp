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
	struct node * header, *temp=NULL, *gtemp;
	char info, choice;
	char name[10];
	void addnode(struct node **, struct node**);
	void display(struct node *);
		
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

	gtemp=header;

	printf("\n");
	
	printf("The information about the candidates are:");
	
	printf("\n");

	while(gtemp->nlink!=NULL)
	{
		printf("\n");

		printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",gtemp->name,gtemp->trade, gtemp->dob);
			
		gtemp=gtemp->nlink;

		printf("\n");
	
	}	

	printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",gtemp->name,gtemp->trade, gtemp->dob);

	printf("\n");

	do
	{
		info ='n';
		printf("Want to display the information of the which candidate :");
		fflush(stdin);
		scanf("%s", &name);
		temp = gtemp;
		
		if(xstrcmp(gtemp->name, name) == 0)
		{
			printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",gtemp->name,gtemp->trade, gtemp->dob);
			info = 'y';
		}
	
		else
	
			if(xstrcmp(gtemp->name, name) == 1)
				while(gtemp!= NULL)
				{
					if(xstrcmp(gtemp->name, name) == 0)
					{
						printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",gtemp->name,gtemp->trade, gtemp->dob);
						info = 'y';
						break;
					}
					gtemp = gtemp->plink;
				}
			else
				while(gtemp != NULL)
				{
					if(xstrcmp(gtemp->name, name) == 0)
					{
						printf("Name = %s, trade = %s, date of birth in dd/mm/yy is = %d",gtemp->name,gtemp->trade, gtemp->dob);
						info = 'y';
						break;
					}
					gtemp = gtemp->nlink;
				}

			if(info == 'n')
			{
				gtemp = temp;
				printf("\n The candidate entry is not in the list ");
			}				
			
			printf("\nWant to see the information of any candidate y/n :");
			fflush(stdin);
			scanf("%c", &choice);
	}
	while(choice == 'y');

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

