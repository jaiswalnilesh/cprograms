#include<stdio.h>
int lshift(int , int);
int rshift(int , int);
void main()
{
	void showbits(int);
	unsigned char arr1[8], arr2[4];
	unsigned static char arr3[8];
	int k, i, carrygen, temp;
	

	printf("Enter the multiplicant :");
	for(i = 0; i <= 3; i++)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr1[i] = (char)temp;
	}
	printf("\n Enter the multiplier :");
	for(i = 0; i <= 3; i++)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr2[i] = (char) temp;
	}
	for(i = 7; i > 3; i--)
		arr1[i] = 0;
	
	printf("First number is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		showbits((int)arr1[i]);
	}
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		printf("%x ", arr1[i]);
		printf("\t");
	}

	printf("\nSecond number is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		showbits((int)arr2[i]);
	}
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		printf("%x ", arr2[i]);
		printf("\t");
	}
	
	carrygen = 0;
	for(i = 0; i < 32; i++)
	{
		if(arr2[0] & 0x01)
		{
			for(k = 0; k <= 7; k++)
			{
				int sum = arr3[k] + arr1[k] + carrygen;
				if(sum < arr1[k] || sum < arr3[k])
					carrygen = 1;
				else
					carrygen = 0;
				arr3[k] = sum;
			}
		}
		
		for(k = 0; k < 3; k++)
		{
			arr2[k] = rshift(arr2[k], 1);
			temp = lshift(arr2[k+1], 7);
			arr2[k] = arr2[k] | temp;
		}
		arr2[3] = rshift(arr2[3], 1);
		
		for(k = 7; k > 0; k--)
		{
			arr1[k] = lshift(arr1[k], 1);
			temp = rshift(arr1[k-1], 8-1);
			arr1[k] = arr1[k] | temp;
		}
		arr1[k] = lshift(arr1[k], 1); 
	}
	

	printf("\nMultiplication is :\n");
	for (i = 7; i >= 0 ; i--)
		showbits((int)arr3[i]);
	
	printf("\n");
	for (i = 7; i >= 0 ; i--)
	{
		printf("%x ", arr3[i]);
		printf("\t");
	}
	printf("\n");
}


int lshift(int num, int shift)
{
	int i;
	for(i = 0; i < shift; i++)
		num= num * 2;
	return num;
}

int rshift(int num, int shift)
{
	int i;
	for(i = 0; i < shift; i++)
		num = num / 2;
	return num;
}

void showbits(int n)
{
	int i, k, mask;

	for(i = 7; i >= 0; i--)
	{
		mask = lshift(1, i);
		k = n & mask;
		k == 0 ? printf("0") : printf("1");
	}
}