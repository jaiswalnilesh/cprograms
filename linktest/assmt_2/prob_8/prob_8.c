// Program to find the median of the given Array

#include <stdio.h>
#include <stdlib.h>

void main()
{
	unsigned int count=0,i=0;
	char again;
	int *DataArr,median;
	int findMedian(int *arr ,int arr_count);
	do
	{
		printf("Enter elments of array(0 to stop)");
		DataArr=(int*)malloc(1000);
		/*do
		{
			printf("\nEnter the number of Elements in the Array(Odd Only):");
			fflush(stdin);
			scanf("%d",&count);	
		}while(count%2==0);
		*/

		do
		{
			printf("\nEnter the number :");
			fflush(stdin);
			scanf("%d",&DataArr[count++]);

		}while(DataArr[count-1]!=0);
		
		realloc(DataArr,(count-1)*sizeof(int));

		median = findMedian(DataArr,count-1);

		if(median!=0)
		printf("Median of the given Array is %d", median);
		else
		printf("Sorry boss");	
		printf("\t\tDO U WANNA REPEATE (y/n):");
		fflush(stdin);
		scanf("%c",&again);

	}while(again =='y' || again =='Y');

}

int findMedian(int *arr ,int arr_count)
{
	int i,j=0,count=0,count1=0,median=0,flag2=0;
	for (i=0;i<arr_count;i++)
	{
		count=0;
		count1=0;
		flag2=0;
		for(j=0;j<arr_count;j++)
		{
				if(j!=i)
				{
					if(count>arr_count/2 || (0 - count)>arr_count/2)
					{
						flag2=0;
						break;
					}
				
					if(arr[i]==arr[j])
					{
						count1++;
						flag2=1;
					}
					else
						if(arr[i]>arr[j])
						{
							count++;
							flag2=1;

						}
						else
						//if(arr[i]<arr[j])
						{
							count--;
							flag2=1;	
						}
				}
		}
		
			if(flag2==1)	
			{
				if((count==0) || ((count==count1)||((0-count)==count1)))
				{
				   median = arr[i];
				   break;
				}
				
				else
				{
					for(j=0;j<count1;j++)
						if(((count-j)==0 || (count+j)==0) && ((count1-j)==0) || (count1-j)%2==0)
						{
							median = arr[i];
							break;

						}
				
				}
			}
	}
	
	

		return median;
				
}

