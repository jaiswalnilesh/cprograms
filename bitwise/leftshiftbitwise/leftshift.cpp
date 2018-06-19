#include<stdio.h>
void main()
{
	unsigned char arr[4] = {0x73,0x46,0x89,0x44};
	unsigned char temp;
	void showbits(int);
	int num, shift, i; 
	
	printf("The number is :\n");
	for (shift = 3; shift >= 0 ; shift--)
	{
		printf("\t");
		showbits((int)arr[shift]);
	}
	printf("\n");
	for (shift = 3; shift >= 0 ; shift--)
	{
		printf("\t");
		printf("%x ",arr[shift]);
		printf("\t");
	
	}

	printf("\nHow many times you want the number to be left shifted: ");
	scanf("%d",&num);

	shift = num / 8;
	if(shift >= 4)
	{
		for (i = 3; i >=0; i--)
			arr[i] = 0x00;
	}
	else if (shift)
	{
		for (i = 3; i >= shift; i--)
			arr[i] = arr[i-shift] ;
			
		for (; i >= 0; i--)
			arr[i] = 0x00;
		
		
	}

	shift = num % 8;
	
	if(shift)
	{
		for(i = 3; i > num/8; i--)
		{
			arr[i] = arr[i] << shift;
			temp = arr[i-1] >> (8 - shift);
			arr[i] = arr [i] | temp;
		}
	
		arr[num/8] = arr[num/8] << shift;
	}

	printf("\nAfter shifting, the number becomes :\n");
	for (shift = 3; shift >= 0 ; shift--)
	{
		printf("\t");
		showbits((int)arr[shift]);
	}
	printf("\n");
	for (shift = 3; shift >= 0 ; shift--)
	{
		printf("\t");
		printf("%x ",arr[shift]);
		printf("\t");
	}
	printf("\n");
}
void showbits(int n)
{
	int i, k, andmask;

	for(i = 7; i >= 0; i--)
	{
		andmask = 1 << i;
		k = n & andmask;
		k == 0 ? printf("0") : printf("1");
	}
}
 