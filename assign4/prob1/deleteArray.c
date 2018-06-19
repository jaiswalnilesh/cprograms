//PROGRAM TO KEEP THOSE ELEMENTS IN A 10 ELEMENTS ARRAY TO 5 ELEMETS 
//ARRAY BY REMOVING THE ELEMENTS IN THE INDEX ARRAY
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *numberArray,indexArray[5],j,temp,i,k=0;
	char again;
	do
	{
		numberArray=(int *)malloc(10*sizeof(int));
		printf("\n\nEnter 10 Numbers\n");
		for(i=0;i<10;i++)
		{
			printf("\t%d\t:\t",(i+1));
			scanf("%d",&numberArray[i]);
			printf("\n");
			fflush(stdin);
		}
		printf("Enter the Index array(The indexes that you want to keep.Rest will be removed");
		for(i=0;i<5;i++)
		{
			printf("\t%d\t:\t",(i+1));
			scanf("%d",&indexArray[i]);
			while(indexArray[i]<0 || indexArray[i] >10)
			{
				printf("\nPlease enter number between 0 and 9 : ");
				scanf("%d",&indexArray[i]);
				fflush(stdin);
			}
			printf("\n");
			fflush(stdin);
		}
		for(i=0;i<10;i++)
		{
			if(!(i==indexArray[0]||i==indexArray[1]||i==indexArray[2]||i==indexArray[3]||i==indexArray[4]))
			{
				for(j=i;j<10;j++)
				{
					if((j==indexArray[0]||j==indexArray[1]||j==indexArray[2]||j==indexArray[3]||j==indexArray[4]))
					{
						temp=numberArray[i];
						numberArray[i]=numberArray[j];
						numberArray[j]=temp;
						indexArray[k++]=i;
						break;
					}
				}
			}
		}
		printf("\n\nAfter taking Input");
		printf("\n\tThe List After Operation is \n");
		for(i=0;i<5;i++)
			printf(" %d ",numberArray[i]);
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}