#include<stdio.h>
void showbits(int);
main()
{
	unsigned char arr[1] = {0xff};
	showbits((int)arr[0]);
	arr[0] = arr[0] / 2;
	printf("\n");
	showbits((int)arr[0]);
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
