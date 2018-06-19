#include<stdio.h>
int lshift(int, int);
int rshift(int, int);
void main(void)
{
	unsigned char arr[4], temp, mask;
	void showbits(int);
	int num, shift, i; 
	
	printf("Enter the numbers to be shifted :");
	for(i = 3; i >= 0; i--)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr[i] = temp;
	}

	printf("The number is :n");
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

	
		printf("\nHow many times you want the number to be right shifted: ");
	//	fflush(stdin);
		scanf("%d",&num);

		shift = num / 8;
		if(shift >= 4)
		{
			mask = arr[3] & 0x80;
			if(mask)
				mask = 0xff;
			for(i = 0; i <= 3; i++)
					arr[i] = mask;
			
		}
		else
		{
			if (shift)
			{
				for (i = 0; i <= 3-shift; i++)
					arr[i] = arr[i+shift] ;
				
				mask = arr[3] & 0x80;
				if(mask)
					mask = 0xff;
				for(; i <= 3; i++)
					arr[i] = mask;
			}

			shift = num % 8;
			
			if(shift)
			{
				for(i = 0; i < 3-(num/8); i++)
				{
					arr[i] = rshift(arr[i], shift);
					temp = lshift(arr[i+1], 8 - shift);
					arr[i] = arr [i] | temp;
				}
			
				mask = arr[3] & 0x80;
				arr[3-num/8] = rshift(arr[3-num/8], shift);
				
				if(mask)
				{
					temp = 0xff;
					temp = lshift(temp, (8 - shift));
					arr[3-num/8] = arr[3-num/8] | temp;
				}
			}
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
	int i, k, mask;

	for(i = 7; i >= 0; i--)
	{
		mask = lshift(1, i);
		k = n & mask;
		k == 0 ? printf("0") : printf("1");
	}
}
int lshift(int num, int shift)
{
	int i;
	for(i = 0; i < shift; i++)
		num = num * 2;
	return num;
}

int rshift(int num, int shift)
{
	int i;
	for(i = 0; i < shift; i++)
		num = num / 2;
	return num;
}

 