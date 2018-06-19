//PROGRAM TO FIND THE MODE OF AN ARRAY OF NUMBERS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
	int *arr,count,retVal;
	int *no=(int *)malloc(sizeof(int));
	char again='n',*last=(char *)malloc(10*sizeof(char));
	char strToInt(char *last,int *no);
	int findMode(int *arr,int count);
	do
	{
		count=0;
		arr=(int *)malloc(sizeof(int)*50);
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

		retVal=findMode(arr,count);
		if(retVal!=-1)
			printf("\n\nMode Of the Array Is %d",arr[retVal]);
		else
			printf("\n\nWARNING!!!!THE ARRAY DOESN'T HAVE A MODE!!!!");
		free(arr);
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	free(last);	
	free(arr);
}
/*
Method to calculate the mode of the specified array
@param arr: the array of integers off which the mode is to be calculated
@param count : the count of numbers input
@return int : returns the mode of the array if array is not having mode
			it returns -1
*/
int findMode(int *arr,int count)
{
	int i,maxCount,sumCount,j,loc=-1;
	char done='y';
	if(count>=0)
	{
		maxCount=0;
		for(i=0;i<count;i++)
		{
			sumCount=0;
			for(j=0;j<count;j++)
			{
				if(arr[i]==arr[j])
				{
					sumCount++;
				}
			}
			if(sumCount==maxCount)
			{
				if(arr[loc]!=arr[i])
				{
					done='n';
					loc=i;
				}
			}
			else if((sumCount>maxCount)&&(arr[loc]!=arr[i]))
			{
				loc=i;
				done='y';
				maxCount=sumCount;
			}
			if(sumCount>count/2)
				break;
		}
		if(done=='y')
			return loc;
		else 
			return -1;
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