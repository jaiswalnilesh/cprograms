#include<stdio.h>
int lshift(int, int);
int rshift(int, int);
void main(void)
{
	unsigned char arr[4];		
	unsigned char temp;
	
	void showbits(int);
	int num, shift, i, choice; 
	
	printf("Enter the numbers to be shifted :");
	for(i = 0; i <= 3; i++)
	{
		fflush(stdin);
		scanf("%x", &temp);
		arr[i] = temp;
	}

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

	printf("\n 1 Right shift ");
	printf("\n 2 Left shift ");
	printf("\n Enter your choice ");

	//fflush(stdin);
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
		printf("\nHow many times you want the number to be right shifted: ");
	//	fflush(stdin);
		scanf("%d",&num);

		shift = num / 8;
		if(shift >= 4)
		{
			for (i = 3; i >=0; i--)
				arr[i] = 0x00;
		}
		else if (shift)
		{
			for (i = 0; i <= 3-shift; i++)
				arr[i] = arr[i+shift] ;
				
			for (; i <= 3; i++)
				arr[i] = 0x00;
		}

		shift = num % 8;
		
		if(shift)
		{
			for(i = 0; i < 3-(num/8); i++)
			{
				arr[i] = rshift(arr[i], shift);
				temp = lshift(arr[i+1],(8 - shift));
				arr[i] = arr [i] | temp;
			}
		
			arr[3-num/8] = rshift(arr[3-num/8], shift);
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

	break;

	case 2:
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
				arr[i] = lshift(arr[i], shift);
				temp = rshift(arr[i-1], 8 - shift);
				arr[i] = arr [i] | temp;
			}
	
			arr[num/8] = lshift(arr[num/8], shift);
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

int rshift(int num , int shift)
{
	int i;
	for(i = 0; i < shift; i++)
		num = num / 2;
	return num;
}
int lshift(int num, int shift)
{
	int i;
	for(i = 0; i< shift; i++)
		num = num * 2;
	return num;
}
 