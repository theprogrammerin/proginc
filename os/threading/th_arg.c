#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THR 5

void *PrintHello(void *param)
{
	long tid;
	tid = (long)param;
	printf("Hello World from #%ld!\n",tid);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THR];	
	int rc,test;
	long t;
	long *param[NUM_THR];
	for(t=0; t<NUM_THR; t++)
	{
		param[t] = (long *) malloc(sizeof(long));
		*param[t] = t*345;
		printf("In Main Creating thread %ld\n",t);
		rc = pthread_create(&threads[t],NULL,PrintHello,(void *)param[t]);
		scanf("Enter Value : %d",&test);
		if(rc)
		{
			printf("ERROR; return code from pthread_create() id %d\n", rc);
			exit(-1);
		}
	}
	
	/* Last thing that main() should do */
	pthread_exit(NULL);
}
