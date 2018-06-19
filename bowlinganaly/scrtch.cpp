#include<stdio.h>
#include<malloc.h>

struct bowl
{
	int runs, wicket, maiden, overs;
	char name[20];
	struct bowl *link;
};

void interchange(struct bowl **, struct bowl **, struct bowl **);
void selectionsort(struct bowl**, int );
int xstrcmp(char *, char*);
void display(struct bowl*);
void main(void)
{


	struct bowl *header1, *temp1;
	int indx;
	char choice;
	header1 = (struct bowl *) malloc (sizeof(bowl));
	
	temp1 = header1;
	
	do
	{
		printf("\nEnter the name of the bowler :");
		fflush(stdin);
		scanf("%s", &(temp1->name));
		
		printf("\nEnter the overs delivered by the bowler :");
		fflush(stdin);
		scanf("%d", &(temp1->overs));

		printf("\nEnter the runs concieved by the bowler :");
		fflush(stdin);
		scanf("%d", &(temp1->runs));
		
		printf("\nEnter the maidens delivered by the bowler :");
		fflush(stdin);
		scanf("%d", &(temp1->maiden));
		
		
		printf("\nEnter the wickets taken by the bowler :");
		fflush(stdin);
		scanf("%d", &(temp1->wicket));
		
		
		printf("\n Want to enter more analysis of the bowler(y/n) :");
		fflush(stdin);
	   	scanf("%c", &(choice));
		

		temp1->link = (struct bowl *) malloc (sizeof(bowl));
		temp1 = temp1->link;
		temp1->link = NULL;
	}
	while(choice == 'y');
	temp1 = header1;
	while(temp1->link->link)
		temp1 = temp1->link;
	temp1->link = NULL;
	display(header1);

	do
	{
		printf("\n 1 want to sort by runs :");
		printf("\n 2 want to sort by wickets :");
		printf("\n 3 want to sort by maiden overs :");
		printf("\n 4 want to sort by overs delivered :");
		printf("\n 5 want to sort by name :");
		scanf("%d", &indx);
		selectionsort(&header1, indx);
		fflush(stdin);
		display(header1);
	}
	while(1);
}
void display(struct bowl *header1)
{
	printf(" Bowler	Overs Delivered maiden	  runs	 wickets  \n");
		
		while(header1)
		{
			printf("\n%s, %3d  %3d  %3d  %3d  %3d", header1->name, header1->overs, header1->overs, header1->maiden, header1->runs, header1->wicket);
			header1 = header1->link;
		}

}


void selectionsort(struct bowl **header, int indx)
{	
	struct bowl *temp1, *temp2, *prnx1, *temp, *prnx2; 
	temp = *header;
	prnx1 = NULL ;
	temp1 = NULL ;
	prnx2 = *header ;
	temp2 = prnx2 ;
	temp = *header ;

	while(temp->link)
	{
		if(!prnx1)
			prnx2 = *header ;
		else	
			prnx2 = temp ;
	
		
		while(prnx2 && prnx2->link)
		{ 
			if((indx == 5 && xstrcmp(temp->name, prnx2->link->name) == 1) || ((indx-1)<5 && ((int*)(temp))[indx-1] > ((int*)(prnx2->link))[indx-1]))
			{
				temp1 = prnx1;
				temp2 = prnx2;
				interchange(&prnx1, &prnx2, &(*header));
				if(!temp1)
					temp = *header ;
				prnx1 = temp1 ;
				prnx2 = temp2 ;
				if(!temp1)
					temp = *header ;
				else
					temp = prnx1->link ;
			}
			prnx2 = prnx2->link ;			
		}
		prnx1 = temp ;
		temp = temp->link ;
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

void interchange(struct bowl** f_prnx1, struct bowl** f_prnx2, struct bowl** f_header)
{
	struct bowl *f_temp1;
	
	
	if((*f_prnx1))
	{
		f_temp1 = (*f_prnx1)->link ;
		(*f_prnx1)->link = (*f_prnx2)->link ;
		(*f_prnx2)->link = f_temp1 ;
		(*f_prnx2) = (*f_prnx1)->link->link ;
		(*f_prnx1)->link->link = f_temp1->link ;
	}
	else
		if((*f_prnx2))
		{
			f_temp1 = (*f_header) ;
			(*f_header) = (*f_prnx2)->link ;
			(*f_prnx1) = (*f_prnx2)->link ;
			(*f_prnx2)->link = f_temp1 ;
			(*f_prnx2) = (*f_prnx1)->link;
			(*f_prnx1)->link = f_temp1->link ;	
		}
	if((*f_prnx1))
		f_temp1->link = (*f_prnx2) ;
}
			
