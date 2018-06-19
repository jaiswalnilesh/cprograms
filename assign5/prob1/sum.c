//PROGRAM TO GET THOSE 2 NUMBERS WHOSE SUM IS EQUAL 
//TO A SPECIFIED NUMBER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void main()
{
	char strToInt(char *last , int *no);
	char isInt(int no);
	char findSum(int *arr , int count , int k , int *result);
	int *arr , k , count , *result = (int *)malloc(2*sizeof(int));
	int *no = (int *)malloc(sizeof(int));
	char again='n';
	char *last=(char *)malloc(10*sizeof(char));;

	
	do
	{
		count = 0;
		arr = (int *)malloc(50*sizeof(int));
		printf("\n\n  PROGRAM TO GET THOSE 2 NUMBERS WHOSE SUM IS EQUAL TO THE SPECIFIED NUMBER : ");
		printf("\n\n\nEnter The Numbers (enter END to end) : \n");

		do
		{
			printf("Element %d\t ",(count+1));
			fflush(stdin);
			gets(last);
			if(strcmp(last,"END") != 0)
			{
				if( strToInt(last,no) == 'y')
					arr[count++] = *no;
			}
			else 
				break;
					
		}while(1);
		printf("\n\nEnter The value of k(the number that matches with sum of any 2 numbers in the array : ");
		fflush(stdin);
		while(scanf("%d",&k) == 0)
		{
			printf("\n\nEnter The VALID value of k");
			fflush(stdin);
		}

		realloc(arr,count*sizeof(int));


		if(findSum(arr,count,k,result)=='y')
			printf("The %d can be stated as %d + %d",k,result[0],result[1]);
		else
			printf("The %d can NOT be stated as sum of any 2 numbers in the array",k);
		
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again == 'y' || again == 'Y');
	free(arr);
	free(last);
	free(result);
}

/*
METHOD THAT FINDS THE 2 NUMBERS FROM THE ARRAY SUCH THAT 
THEY ARE EQUAL TO THE SPECIFIED NUMBER

@param arr : input array
@param count : the number of elements in the array
@param k : the specified number to be checked as the sum of 2 
		   numbers in the array
@param result : integer pointer that contains the result if exists

@return char : returns 'y' if function succeeds else retuyrns 'n'

*/
char findSum(int *arr,int count,int k,int *result)
{
	char done='n';
	int i,j;
	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(arr[i]+arr[j]==k)
			{
				result[0]=arr[i];
				result[1]=arr[j];
				return 'y';
			}
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
