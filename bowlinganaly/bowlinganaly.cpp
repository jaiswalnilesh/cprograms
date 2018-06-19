#include<stdio.h>
#include<malloc.h>

struct bowl
{
	int overs, maiden, wicket, runs;
	char name[20];
	struct bowl *link;
};

void interchange(struct bowl **, struct bowl **, struct bowl **);
void selectionsort(struct bowl**, int );
void bubblesort(struct bowl**, int );
void insertionsort(struct bowl**, int, int);
void shellsort(struct bowl**, int);
struct bowl* getpossiblenode(struct bowl*, int);
int xstrcmp(char *, char*);
void display(struct bowl*);
main()
{
	struct bowl *header1, *temp1;int indx;
	int type;
	header1 = (struct bowl *) malloc (sizeof(bowl));
	
	temp1 = header1;
	
	FILE *fp ;
	fp = fopen("c:\\bowlinganaly.txt", "r");

	if(fp == 0)
	{
		printf("\nFile could not be opened") ;
		return -1;
	}
	
	temp1 = header1;
	while((fscanf(fp, "%s %u %u %u %u", temp1->name, &(temp1->overs), &(temp1->maiden), &(temp1->wicket), &(temp1->runs)))!=EOF)
	{
		temp1->link = (struct bowl *) malloc (sizeof(bowl)); 
		temp1 = temp1->link ;
		
	}
	temp1->link = NULL;
	temp1 = header1;

	while(temp1->link->link)
		temp1 = temp1->link;
	free(temp1->link);
	temp1->link = NULL;
	fclose(fp) ;
	display(header1);

	do
	{	

		printf("\n Enter 1 Selection sorting :");
		printf("\n Enter 2 Bubble sorting :");
		printf("\n Enter 3 Insertion sorting :");
		printf("\n Enter your method :");
		fflush(stdin);

		scanf("%d", &type);
		fflush(stdin);
		if(type ==1 || type ==2 || type ==3)
		{
			printf("\n 1 want to sort by overs delivered :");
			printf("\n 2 want to sort by maiden overs :");
			printf("\n 3 want to sort by wickets :");
			printf("\n 4 want to sort by runs:");
			printf("\n 5 want to sort by name :");
			printf("\n Enter your type :");
			scanf("%d", &indx);
		
			if(type == 1)
				selectionsort(&header1, indx);
			else
				if(type == 2)
					bubblesort(&header1, indx);
				else
					if(type ==3)
						shellsort(&header1, indx);
			display(header1);
		}
		else
			printf("\n Invalid entry");                   
	}
	while(1);
}
struct bowl* getpossiblenode(struct bowl* header, int inc)
{
	struct bowl *temp1, *temp2, *ret;
	
	temp1 = header;
	int k = inc;
	while(k)
	{
         k--;
		if(k == 0 && temp1->link != NULL)
			ret = temp1->link;
		if(temp1->link == NULL)
			return ret;
		if(temp1)
			temp1 = temp1->link;
	}
}
void display(struct bowl *header1)
{
	printf(" Bowler\t\t\tovers\tmaidens\twickets\truns  \n");
		
		while(header1)
		{
			printf("\n%-20s\t%-4d\t%-4d\t%-4d\t%-4d", header1->name, header1->overs, header1->maiden, header1->wicket, header1->runs);
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
			if((indx == 5 && xstrcmp(temp->name, prnx2->link->name) == 1) || (indx<5 && ((int*)(temp))[indx-1] > ((int*)(prnx2->link))[indx-1]))
			{
				if(temp == prnx2)
					temp2 = prnx2->link;
				else
					temp2 = prnx2;
				temp1 = prnx1;
				interchange(&prnx1, &prnx2, &(*header));
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


void bubblesort(struct bowl**header, int indx)
{
	struct bowl *temp1, *temp2, *prnx1, *temp, *temp3, *prnx2; 
	temp = *header;
	prnx1 = NULL ;
	temp1 = NULL ;
	temp3 = NULL ;
	prnx2 = *header ;
	temp2 = prnx2 ;
	
	while((*header)->link != temp3)
	{
		prnx1 = NULL;		
		prnx2 = *header;
		temp = *header;
	
		
		while(prnx2->link != temp3)
		{ 
			if((temp) && (indx == 5 && xstrcmp(temp->name, prnx2->link->name) == 1) || (indx<5 && ((int*)(temp))[indx-1] > ((int*)(prnx2->link))[indx-1]))
			{
				temp2 = prnx2->link;					
				temp1 = prnx1;
				interchange(&prnx1, &prnx2, &(*header));
				prnx1 = temp1;
				prnx2 = temp2;
				if(!temp1)
					temp = *header;
				else
					temp = prnx1->link;
			}
		
			prnx2 = prnx2->link ;
			prnx1 = temp;
			temp = temp->link;		
					
		}
		temp3 = prnx2;
	}
}
/*void insertionsort(struct bowl** header, int indx, int k)
{
	struct bowl *temp2, *temp, *temp3, *prev1, *prev2;
	prev2 = *header;
	prev1 = NULL;
	temp = *header;
	temp2 = temp->link;
	while(temp2)
	{
		temp3 = temp2;
		temp = *header;
		prev1 = NULL;
		
		while(temp3 != temp)
		{
			if((indx == 5 && (xstrcmp(temp3->name, temp->name) == -1) || (indx<5 && ((int*)(temp3))[indx-1] < ((int*)(temp))[indx-1])))
			{
				prev2->link = temp3->link;
				if(prev1)
					prev1->link = temp2;

				temp3->link = temp;

				if(!prev1)
					*header = temp3;
				break;
			}
			prev1 = temp;
			temp = getpossiblenode(temp,k);
		}
		prev2 = temp2;
		temp2 = temp2->link;
	}
}*/
void insertionsort(struct bowl** header, int indx, int k)
{
	struct bowl *temp2, *temp, *temp3, *prev1, *prev2;
	prev2 = *header;
	prev1 = NULL;
	temp = *header;
	
	while(*header)
	{
		temp2 = getpossiblenode(temp, k);
		temp3 = temp2;
		
		prev1 = NULL;
		if(temp && temp->link && temp3 != NULL)
		{
			while(temp3 != temp)
			{
				if((indx == 5 && (xstrcmp(temp3->name, temp->name) == -1) || (indx<5 && ((int*)(temp3))[indx-1] < ((int*)(temp))[indx-1])))
				{
					prev2->link = temp3->link;
					if(prev1)
						prev1->link = temp2;

					temp3->link = temp;

					if(!prev1)
						*header = temp3;
					break;
				}
				prev1 = temp;
				temp = getpossiblenode(temp,k);
			}
			prev2 = temp2;
			temp2 = temp2->link;
		}
	}
}	

void shellsort(struct bowl **header, int indx)
{
	struct bowl *temp1, *temp2, *temp3, *temp4, *prev1, *prev2;
	temp1 = *header;
	temp2 = temp1;
	int count, arr[3] = {5, 3, 1};
	for(int i = 0; i < 3; i++)
	{
		count = arr[i];
		while(temp1)
		{
			temp2 = temp1;
			insertionsort(&temp2, 1, arr[i]);
			temp1 = temp1->link;
		}
	}
}
int xstrcmp(char* s, char* d)
{
	while(1)
	{
		if(!*s && !*d)
			return 0;
		if(*s < *d)
			return -1 ;
		if(*s > *d)
			return 1;
		s++;
		d++;
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
			(*f_prnx2) = (*f_prnx1)->link ;
			(*f_prnx1)->link = f_temp1->link ;	
		}
	if((*f_prnx1))
		f_temp1->link = (*f_prnx2) ;
}
			
