#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_THREADS 5
#define EXIT_SUCCESS 0

void *taskcode(void *arg)
{
        long long  tid;
        tid=(long long)arg;
        printf("Hello world ! It's me, thread %d!\n", tid);
        printf ("int '%d', void * '%d'\n", sizeof(long long), sizeof(void *));
        return NULL;
}
int main (int argc, char *argv[])
{
        pthread_t threads[NUM_THREADS];
        int rc, i;

        for (i=0; i<NUM_THREADS; i++) {
                printf("In Main: create thread %d\n", i);
                rc=pthread_create(&threads[i], NULL, taskcode, (void *) &i);
                assert(0==rc);
        }

        for (i=0; i<NUM_THREADS; i++) {
                rc=pthread_join(threads[i], NULL);
                assert(0==rc);
        }

        exit(EXIT_SUCCESS);

}
