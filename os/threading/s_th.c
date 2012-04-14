#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THR 5

void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hello World from #%ld!\n",tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THR];	
	int rc;
	long t;
	for(t=0; t<NUM_THR; t++)
	{
		printf("In Main Creating thread %ld\n",t);
		rc = pthread_create(&threads[t],NULL,PrintHello,(void *)t);
		if(rc)
		{
			printf("ERROR; return code from pthread_create() id %d\n", rc);
			exit(-1);
		}
	}
	
	/* Last thing that main() should do */
	pthread_exit(NULL);
}
