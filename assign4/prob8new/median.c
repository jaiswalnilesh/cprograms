//check for 1 1 1 2 2 2 2 3 3
//PROGRAM THAT FINDS THE MEDIAN.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	int findMedian(int *arr,int count);
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
		
		printf("\n\nMedian Of the Array Is %d",findMedian(arr,count));
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
@return int : returns the median of the array
*/
int findMedian(int *arr,int count)
{
	int i,sumCount=0,j,sumCount1=0;
	char sumCount1Done='n',sumCount_1Done='n';
	int getAbs(int i);

	int equalCount=0;
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
					if(j!=i)
					{
						if(getAbs(sumCount)>count/2)
							break;
						if(arr[i]>arr[j])
							sumCount++;
						else if(arr[i]<arr[j])
							sumCount--;
						else equalCount++;
					}
				}
				if(equalCount>count/2)

					return arr[i];
				else if(getAbs(sumCount)<count/2)
				{
					if((sumCount1Done=='n')&&((sumCount==1)||((sumCount>0)&&(getAbs(sumCount)-equalCount==1))))
					{
						sumCount1+=arr[i];
						sumCount1Done='y';
					}
					else if((sumCount_1Done=='n')&&((sumCount==-1)||((sumCount<0)&&(getAbs(sumCount)-equalCount==1))))
					{
						sumCount1+=arr[i];
						sumCount_1Done='y';
					}
					if(sumCount1Done=='y' && sumCount_1Done=='y')
					{
						return (sumCount1/2);
					}
				}
				equalCount=0;
//				sumCount1=0;
			}
			return sumCount1;
		}
		else
		{
			for(i=0;i<count;i++)
			{
				sumCount=0;
				for(j=0;j<count;j++)
				{
					if(j!=i)
					{
						if(getAbs(sumCount)>count/2)
							break;
						if(arr[i]>arr[j])
							sumCount++;
						else if(arr[i]<arr[j])
							sumCount--;
						else equalCount++;
					}
				}
				if(equalCount>count/2)
					return arr[i];
				else if(getAbs(sumCount)<count/2)
				{
					if((sumCount==0)||(equalCount>count/2)||((getAbs(sumCount)-equalCount)==0))
						return arr[i];
				}
				equalCount=0;
			}
		}
	}
	return -1;
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

/*
checks whether the input no is integer or not
@param no : integer to be parsed;
@return char : return 'y' if function successful in parsing
			   return 'n' if function in NOT successful in parsing
*/
/*char isInt(int no)
{
	char ok='y';
	int p;
	if((no>0)||(no<=0))
	{
		while(no>0)
		{
			p=isdigit(no%10);
			if(p==0)
			{
				ok='n';
				break;
			}
			else
				no=no/10;
		}
	}
	else
		return 'n';
	return ok;
}*/