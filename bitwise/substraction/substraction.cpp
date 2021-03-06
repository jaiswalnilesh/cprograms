#include<stdio.h>
void main()
{
	void showbits(int);
	unsigned char arr1[4] = {0xf0, 0x34, 0x24, 0x45};
	unsigned char arr2[4] = {0x34, 0x56, 0x25, 0x64};
	unsigned char arr3[4];
	int i, borrow;

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
	
	borrow = 0;
	for(i = 0; i <= 3; i++)
	{
		arr3[i] = arr1[i] - arr2[i] - borrow;
		if(arr2[i] > arr1[i])
			borrow = 1;
		else
			borrow = 0;
	}
	
	printf("\n The result of substraction is :\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		showbits((int)arr3[i]);
	}
	printf("\n");
	for (i = 3; i >= 0 ; i--)
	{
		printf("\t");
		printf("%x ", arr3[i]);
		printf("\t");
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
}