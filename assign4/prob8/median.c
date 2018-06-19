//PROGRAM THAT FINDS THE MEDIAN.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	char findMedian(int *arr,int count,int *no);
	char strToInt(char *last,int *no);
	int *arr,count;
	int *no=(int *)malloc(sizeof(int));
	int *result=(int *)malloc(sizeof(int));
	char again='n',*last=(char *)malloc(10*sizeof(char));
	
	do
	{
		count=0;
		arr=(int *)malloc(50*sizeof(int));
		printf("Enter The Array (enter END to end) : \n");
		do
		{
			printf("Element %d\t ",(count+1));
			fflush(stdin);
			gets(last);
			if(strcmp(last,"END")!=0)
			{
				if(strToInt(last,no)=='y')
					arr[count++]=*no;
			}
			else 
				break;
					
		}while(1);
		
		realloc(arr,count*sizeof(int));
		if(findMedian(arr,count,result)=='y')
			printf("\n\nMedian Of the Array Is %d",*result);
		else
			printf("\n\nWARNING!!!!THE ARRAY DOESN'T HAVE A MEDIAN!!!!");

		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	free(last);
	free(arr);
}

/*
METHOD THAT FINDS THE MEDIAN.
@param arr : the number array off which the median is to be find.
@param count : the number of integers in the array
@param no : integer pointer in which the return value is to be collected if there is median
@return char : returns 'y' if there is median else returns 'n'
*/
char findMedian(int *arr,int count,int *no)
{
	int i,sumCount=0,j,sumCount1=0;
	char sumCount1Done='n',sumCount_1Done='n';
	int getAbs(int i);
	if(count==1)
		return 'n';
	if(count>0)
	{
		if(count%2==0)
		{
			for(i=0;i<count;i++)
			{
				sumCount=0;
				for(j=0;j<count;j++)
				{
					if(getAbs(sumCount)>count/2)
						break;
					if(arr[i]>arr[j])
						sumCount++;
					else if(arr[i]<arr[j])
						sumCount--;
				}			
				if(sumCount==1)
				{
					sumCount1+=arr[i];
					sumCount1Done='y';
				}
				else if(sumCount==-1)
				{
					sumCount1+=arr[i];
					sumCount_1Done='y';
				}
				if(sumCount1Done=='y' && sumCount_1Done=='y')
				{
					*no=sumCount1/2;
					return 'y';
				}
			}
			return 'n';
		}
		else
		{
			for(i=0;i<count;i++)
			{
				sumCount=0;
				for(j=0;j<count;j++)
				{
					if(getAbs(sumCount)>count/2)
						break;
					if(arr[i]>arr[j])
						sumCount++;
					else if(arr[i]<arr[j])
						sumCount--;
				}			
				if(sumCount==0)
				{
					*no=arr[i];
					return 'y';
				}
			}
			return 'n';
		}
	}
	return 'n';
}

/*
METHOD TO GET THE ABSOLUTE VALUE FOR AN INTEGER
@param i : integer to be get absoluted
@return int : returns the absolute value of the input integer
*/
int getAbs(int i)
{
	return (i<0)?-i:i;
}

/*
converts the given string to integer
@param str : string to be converted to integer
@param no : integer pointer in which the parsed number is to be stored;
@return char : return 'y' if function successful in parsing
			   return 'n' if function in NOT successful in parsing
*/
char strToInt(char *str,int *no)
{
	char ok='y';
	*no=0;
	while(*str)
	{
		if(!(isdigit(*str)))
		{
			ok='n';
			break;
		}
		else
		{
			*no=(int)((*no)*10+((*str)-48));
			str++;
		}
	}
	return ok;
}