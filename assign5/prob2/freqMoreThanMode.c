//program to get the number whose frequency is greater than the mode of that array.

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


void main()
{
	char strToInt(char *last,int *no);
	int getFreqMoreThanMode(int *arr,int count);
	int *arr,count,result;
	int *no=(int *)malloc(sizeof(int));
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

		if((result=getFreqMoreThanMode(arr,count))!=-1)
			printf("\n\n%d is Having The Frequency More Than Mode",arr[result]);
		else
			printf("\n\nNo Number Has The Frequency More Than The Mode.Sorry!!");

		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');

	free(last);
	free(arr);
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
method to get the number whose frequency is greater than the mode of 
that array.
@param arr : integer pointer that contains the numbers
@param count : the number of elements in the array.

@return int : -1 if required number is not found
			   otherwise returns the location of that number
*/
int getFreqMoreThanMode(int *arr,int count)
{
	int freq,i,j;
	if(count==1)
		return -1;
	for(i=0;i<count;i++)
	{
		freq=1;
		for(j=i+1;j<count;j++)
		{
			if(freq>count/2)
				return i;
			if(arr[i]==arr[j])
				freq++;
		}
		if(freq>count/2)	//if got the required number,return that
			return i;
	}
	return -1;//after parsing for all numbers,no one is the required number so return -1
}