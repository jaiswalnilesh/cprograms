#include<stdio.h>
void main(void)
{
	int array[10];
	int incr[3];
	int i, n = 10, num = 3, inc, j, k, span, y;

	printf("\n Enter the elements of array :\n");

	for(i = 0; i < 10; i++)
		scanf("%d", &array[i]);

	printf("\nEnter the increments :\n");
	
	for(i = 0; i < 3; i++)
		scanf("%d", &incr[i]);


	for(inc = 0; inc < num; inc++)
	{
		span = incr[inc];
		for(j = span; j < n; j++)
		{
			y = array[j];
			
			for(k = j-span; k >= 0 && y < array[k]; k -= span)
 				array[k + span] = array[k];

			array[k + span] = y;
		}
	}


	printf("\nThe sorted list is : \n");

	for(i = 0; i < 10 ; i++)
		printf("%3d", array[i]);
	printf("\n");
}

	