// Program to Remove the array elements not indexed in the reference array 

#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i,*arr1,arr2[]={-1,-1,-1,-1,-1},small,k;
	
	arr1=(int*)malloc(sizeof(int)*10);
	printf("Enter 10 elements for the first array\n");
	
	for (i=0;i<10;i++)
	{
		do
		{			
			fflush(stdin);
			scanf("%d",&arr1[i]);
			if(arr1[i]<0 || arr1[i]>999999)
			{
				printf("\nError:Not a Valid number \nEnter another Element");
				
			}
		}while(arr1[i]<0 || arr1[i]>999999);
	}
	
	for (i=0;i<5;i++)
	{
		do
		{
			if(i==0)
			printf("\nEnter 5 index for the first array\n");
			fflush(stdin);
			scanf("%d",&arr2[i]);
			if(arr2[i]<0 || arr2[i]>10)
			{
				printf("\nError: Array1 index Out of bound\nEnter another Element");
				
			}
		}while(arr2[i]<0 || arr2[i]>9);
	}

// SORT THE SECOND ARRAY

	for (k=0;k<5;k++)
	{
		small=arr2[k];
		for (i=k+1;i<5;i++)
		{
			if(small>arr2[i])
			{
				small=arr2[i]+small;
				arr2[i]=small-arr2[i];
				small=small-arr2[i];
			}
			
		}
		arr2[k]=small;
	}


/* CHECK FOR THE INDEXES PRESENT IN THE SECOND ARRAY 
 * ARRANGE FIRST ARRAY ACCORDING TO THOSE INDEXES
 */
	small=0;
	for(k=0,i=0;k<10;k++)
	{
		if(arr2[small]==k)
		{
			arr1[i]=arr1[k];
			i++;
			while(arr2[small+1]==arr2[small++]);
			
		}
		
	}
// Print the first Array
	for(k=0;k<i;k++)
		printf("%d ",arr1[k]);
		
}