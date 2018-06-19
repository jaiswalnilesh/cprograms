#include<stdio.h>
#include<malloc.h>
void main()
{
	int arr1[7][7]={1,0,0,0,0,0,0,1,2,0,0,0,0,0,1,2,3,0,0,0,0,1,2,3,4,0,0,0,1,2,3,4,5,0,0,1,2,3,4,5,6,0,1,2,3,4,5,6,7};
	int arr2[7][7]={1,0,0,0,0,0,0,1,2,0,0,0,0,0,1,2,3,0,0,0,0,1,2,3,4,0,0,0,1,2,3,4,5,0,0,1,2,3,4,5,6,0,1,2,3,4,5,6,7};

	int arr3[7][7], arr4[7][8];
	int i, j;
	
	printf("\n The first matrix is :");

	for(i=0; i<7; i++)
	{
		printf("\n");
		for(j=0; j<7; j++)
		{
			printf("%3d", arr1[i][j]);
		}
	}

	printf("\n The second matrix is :\n");
	for(i=0; i<7; i++)
	{
		printf("\n");
		for(j=0; j<7; j++)
			printf("%3d", arr2[i][j]);
	}

	for(i=0; i<7; i++)
	{
		for(j=0; j<7; j++)
		{
			arr3[i][j]=arr2[j][i];
		}
	}

	printf("\nThe transpose of the second matrix is :\n");
	for(i=0; i<7; i++)
	{
		printf("\n");
		for(j=0; j<7; j++)
			printf("%3d", arr3[i][j]);
	}

	printf("\n");



	for(i=0; i<7; i++)
	{
		for(j=0; j<=i; j++)
		{
			arr4[i][j]=arr1[i][j];
		}
		for(; j<8; j++)
		{
			arr4[i][j]=arr3[i][j-1];
		}
	}

	printf("\nThe combined matrix is :\n");
	

	for(i=0; i<7; i++)
	{
		printf("\n");
		for(j=0; j<8; j++)
			printf("%3d", arr4[i][j]);
	}
	printf("\n");
}

