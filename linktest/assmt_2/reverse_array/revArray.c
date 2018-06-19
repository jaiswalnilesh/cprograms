/* Program to reverse a given array */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	unsigned int count=0;
	char again;
	int *ptr,DataArr[50];
	int *RevArray(int *arr ,int arr_count);
	do
	{
		printf("Enter elments of array(0 to stop)");
	
		do
		{
			printf("\nEnter the number :");
			fflush(stdin);
			scanf("%d",&DataArr[count++]);

		}while(DataArr[count-1]!=0);

		ptr = RevArray(DataArr,count-2);// CALL THE REVERSE ARRAY FUNCTION

		while (count-1>0)
		{
			printf("%d",*ptr++);
			count--;
		}

			
		printf("\t\tDO U WANNA REPETE (y/n):");
		scanf("%c\n",&again);

	}while(again=='y' || again=='Y');

}

/*FUNCTION TO REVERSE THE GIVEN ARRAY
 *ACCEPTS STARTING ADDRESS OF THE ARRAY AND NUMBER OF ELEMENTS IN THE ARRAY
 *RETURNS ARRAY POINTER
 
*/
int *RevArray(int *arr ,int arr_count)
{
	int i=0;
	while(i<arr_count)
	{
		arr[i]=arr[i]+arr[arr_count];
		arr[arr_count]=arr[i]-arr[arr_count];
		arr[i]=arr[i]-arr[arr_count];
		arr_count--;
		i++;
	}
return arr;

}





