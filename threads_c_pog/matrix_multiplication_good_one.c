Today we are doing a little learning in the area of PThreads and Matrix multiplication. First, lets start by learning how to multiply matrices.

We are not going to go really in depth into matrices if you would like to learn more, check out: Tutorial: Matrix Multiplication

Matrix A: [ 10 15 20 ]

Matrix B:
	3 	
4
1

Rule numero uno:

The length of the rows on matrix A must equal the length of the columns on matrix B.

So if A is a 1 x 3 matrix and B is a 3 x 4 Matrix then C will be a 1 x 4 matrix. See how the 3’s canceled out to give us the dimensions of the resultant matrix?

Rule #2:

What we really wanna do is multiply the rows in A by the columns in B. SO, we just have to keep telling ourselves when we do these problems rows by columns, rows by columns.

Lets take a look at our example above: [Rows by column] (10 * 3) + (15 * 4) + (20 * 1) = [110] Therefore, matrix C is a 1 x 1 matrix with a resultant of 110.

One more:

Matrix A:
	2 	4 	-1 	
3 	-2 	-1

Matrix B:
	6 	0 	3 	
2 	1 	-2
0 	0 	1

Here, we have a 2 x 3 Matrix A and a 3 x 3 Matrix B. This will give us a 2 x 3 Matrix C.

[Rows by columns]

1,1 : (2 * 6) + (4 * 2) + (-1 * 0) = 20

1,2 : (2 * 0) + (4 * 1) + (0 * 1) = 4

1,3 : (2 * 3) + (-4 * -2) + (-1 * 1) = -3

2,1 : (3 * 6) + (-2 * 2) + (-1 * 0) = 14

2,2 : (3 * 0) + (-2 * 1) + (-1 * 0) = -2

2,3 : (3 * 3) + (-2 * -2) + (-1 * 1) = 12

Matrix C:
	20 	4 	-3 	
14 	-2 	12

Okay, great, now we understand matrix multiplication. If you are still having issues I recommend visiting the link above, its basically amazing.

Now on to PThreads on linux. For this next code tutorial we are going to be exploring pthreads a little further then last time. This time our goal is to calculate every matrix coordinate with a different thread. In my previous post,

Prime numbers using POSIX threads on Linux in [C], we discussed how to use one thread to calculate a bunch of prime numbers and print them to the command line. This time it gets a little trickier, but not too tricky.

We are first going to define our matrices statically, and then define a structure that will hold row and column information for each thread. Important question alert!! Why do we need a structure to hold row and column information for each thread??? Well, like I said before we need to assign each thread its own coordinate to figure out in the resulting matrix. Remember when we were learning how to multiply matrices earlier? Rows by columns, rows by columns? I practically beat you over the head with it, I’m sure you remember. Well that’s exactly how each thread is going to compute its coordinate, each thread needs a row and a column to multiply. Then we will create two “for” loops, one for rows and an inner one for columns. The inner one will create a new thread and call the join method so the parent will wait for all the threads to complete before it prints out the resulting matrix (the parent can print the resulting matrix because threads share all resources with its parent, remember?).

Time for the code, yay!
CODE:

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 2
#define N 3
#define NUM_THREADS 10

int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];

struct v {
   int i; /* row */
   int j; /* column */
};

void *runner(void *param); /* the thread */

int main(int argc, char *argv[]) {

   int i,j, count = 0;
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         //Assign a row and column for each thread
         struct v *data = (struct v *) malloc(sizeof(struct v));
         data->i = i;
         data->j = j;
         /* Now create the thread passing it data as a parameter */
         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes
         //Get the default attributes
         pthread_attr_init(&attr);
         //Create the thread
         pthread_create(&tid,&attr,runner,data);
         //Make sure the parent waits for all thread to complete
         pthread_join(tid, NULL);
         count++;
      }
   }

   //Print out the resulting matrix
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

//The thread will begin control in this function
void *runner(void *param) {
   struct v *data = param; // the structure that holds our data
   int n, sum = 0; //the counter and sum

   //Row multiplied by column
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   //assign the sum to its coordinate
   C[data->i][data->j] = sum;

   //Exit the thread
   pthread_exit(0);
}

Output:

lee@isis:~/programming/c/matrix$ ./matrix.out

28 23 18

41 34 27

54 45 36

Yay! Look at that it worked! Go figure, haha. If you are still having problems understanding how matrices work maybe you should write this code out by hand and see exactly what its doing and how its traversing the rows and columns.

Quick reminder, in order to compile c programs with the use of pthread in linux you need to add the -lpthread arg to gcc like so:

gcc -lpthread -o matrix.out matrix.c



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 2
#define N 3

int A[M][K]={
	{2, 3},
	{3, 5},
	{2, 4}
};

int B[K][N]={
	{3, 2, 5},
	{1, 3, 6}
};

int C[M][N]

struct v {
	int i;
	int j;
};
void *mul_matrix(void *param);

int main(int argc, char *argv[])
{
	int i, j;
	for (i=0; i<M ; M++)
	{
		for (j=0; j<N ; j++)
		{
			struct v *data=(struct *v) malloc (sizeof(struct *v));
			data->i=i;
			data->j=j;

			pthread_t tid;
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tid, &attr, mul_matrix, data);
			pthread_join(tid, NULL);
		}
	}

	for (i=0; i<M; i++ )
	{
		for (j=0; j<N ; j++)
		{
			printf("%d", C[i][j]);
		}
		printf("\n");
	}
}

void *mul_matrix (void *param)
{
	int n, sum=0;
	struct v *data=param;
	for (n=0; n<K ; n++)
	{
		sum += A[data->i][n] * B[n][data->j];
	}
	C[data->i][data->j]=sum;
	pthread_exit(0);
}