#include<stdio.h>
#include<conio.h>

int count;
void main()
{
	void hanoi(int n, char* src, char* inter, char* dst);
	do
	{
		printf("\n\nEnter The Number Of Disks " );
		hanoi(_getche()-48,"Source","Intermediate","Destination");
		count=0;
		printf("\n\n\t\tEnter Again?('y' to continue) : ");
		fflush(stdin);
	}while(_getch()=='y');

}

void hanoi(int n, char* src, char* inter, char* dst)
{	
    if(n == 0)
	{
		count++;
		return;
	}
	else
	{
		hanoi(n-1, src, dst, inter);//Move n-1 disk from source to intermidiate
		printf("\nMove %d\t:\tDisc %d from %s to %s\n",count,n,src,dst);//move nth disc from source to intermidiate
		hanoi(n-1, inter, src, dst);//Move n-1 disc from intermidiate to source.
	}
}
