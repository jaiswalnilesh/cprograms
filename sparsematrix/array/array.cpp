#include<stdio.h>
void main()
{
	int arr[5][5], i, j, arr1[15];
	char ch;

	printf("Enter the 2-D array: \n");

	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	printf("The 2-D array is entered :\n");

	for(i=0; i<5; i++)
	{
		printf("\n");
		for(j=0; j<5; j++)
			printf("%3d", arr[i][j]);
	}

	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			arr1[i*(i+1)/2 + j] = arr[i][j];
	


		printf("\n\nThe 1-D array is :\n");

		for(i=0; i<15; i++)
			printf("%3d", arr1[i]);

		do
		{
			printf("\n\nEnter the row and column whose value is to be printed :\n");
			fflush(stdin);
			scanf("%d%d", &i, &j);
			if(j > i)
				printf("\nThe element from 1-D array is :0 ");
			else
				printf("\nThe element from 1-D array is : %d", arr1[i*(i+1)/2 + j]);
			
			printf("\nWant  to check another record (y/n) : ");
			fflush(stdin);
			scanf("%c", &ch);
		}
		while(ch=='y');
			printf("\n");

}


	

