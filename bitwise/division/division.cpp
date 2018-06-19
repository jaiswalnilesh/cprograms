#include<stdio.h>
void main()
{
	void showbits(int);
	unsigned char arr1[4], arr2[4];
	unsigned static char arr3[4], temp;
	int k, i, borrow, s;
	

	printf("Enter the Divisior:");
	for(i = 3; i >= 0; i--)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr1[i] = temp;
	}
	printf("\n Enter the Divident :");
	for(i = 3; i >= 0; i--)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr2[i] = temp;
	}
		
	printf("Divisior is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		showbits((int)arr1[i]);
		printf("\t");
	}
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("%x ", arr1[i]);
		printf("\t");
		printf("\t");
	}

	printf("\nDivident is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		showbits((int)arr2[i]);
		printf("\t");
	}
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("%x ", arr2[i]);
		printf("\t\t");
	}


	for(k = 3; k >= 0 ; k--)
	{
		if((unsigned char)arr1[k] > (unsigned char)arr2[k])
		{
			borrow = 0;
			break;
		}
		else if((unsigned char)arr1[k] < (unsigned char)arr2[k])
		{
			borrow = 1;
			break;
		}
		else
			borrow = 0;
	}
	
	if(borrow)
	{
		for(i = 0;i <=3; i++)
			arr3[i] = 0;
	}
	else
	{

		s = 1;

		while(s)
		{
			borrow = 0;
			for(k = 0; k <= 2; k++)
			{
				if(arr2[k] + borrow > arr1[k])
				{
					arr1[k] = ( arr1[k] + 256 ) - (arr2[k]+borrow) ;
					borrow = 1 ;
				}
				else
				{
					arr1[k] -= arr2[k]+borrow ;
					borrow = 0 ;
				}
			}
			arr1[3]-= arr2[3] + borrow ;
			
			if((unsigned char)arr3[0] > (unsigned char)(arr3[0] + 1))
			{
				if((unsigned char)arr3[1] > (unsigned char)(arr3[1] + 1))
				{
					if((unsigned char)arr3[2] > (unsigned char)(arr3[2] + 1))
					{
						arr3[3] += 1;
					}
					arr3[2] += 1;
				}
				arr3[1] += 1;
			}
			arr3[0] += 1;
					
			borrow = 1 ;
			for(k = 3; k >= 0 ; k--)
			{
				if((unsigned char)arr1[k] > (unsigned char)arr2[k])
				{
					borrow = 0;
					break;
				}
				else if((unsigned char)arr1[k] < (unsigned char)arr2[k])
				{
					borrow = 1;
					break;
				}
				else
					borrow = 0;
			}
	
		if(borrow)
			s = 0;
		}
	}		
		
		

	printf("\nQuotient is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		showbits((int)arr3[i]);
		printf("\t");
	}
	
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("%x ", arr3[i]);
		printf("\t\t");
	}

	printf("\nRemainder is :\n");
	
    for (i = 3; i >= 0 ; i--)
	{
		showbits((int)arr1[i]);
		printf("\t");
	}
	
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("%x ", arr1[i]);
		printf("\t\t");
	}
	printf("\n");
 }


void showbits(int n)
{
	int i, k, mask;

	for(i = 7; i >= 0; i--)
	{
		mask = 1 << i;
		k = n & mask;
		k == 0 ? printf("0") : printf("1");
	}
	printf(" ") ;
}

