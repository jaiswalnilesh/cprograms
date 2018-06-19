#include<stdio.h>
main()
{
	void toh(int, char, char, char);
	int n;

	printf("Enter the number of disk ::=> ");
	scanf("%d", &n);

	toh(n, '1', '2', '3');
}

void toh(int n, char a, char b, char c)
{
	if(n == 1)
		printf("\nDISK IS MOVED FORM TOWER %c to %c",a, c);

	else
	{
		toh(n-1, a, c, b);
		toh(1, a, ' ', c);
		toh(n-1, b, a, c);
	}
}