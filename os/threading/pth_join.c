#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>

#define NUM_THR 2

void *PrintHello(void *tid)
{
	long i,j;
	double res=0;
	for(i=0;i<50;i++)
	{
		res = res + i*i;
		printf("%ld ",i);
		for(j=0;j<100000000;)
			j = j+1;
	}
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THR];	
	int rc;
	long t;
		printf("In Main Creating thread 1\n");
		
		rc = pthread_create(&threads[0],NULL,PrintHello,(void *)t);
		
		printf("In Main Creating thread 2\n");
		
		rc = pthread_create(&threads[1],NULL,PrintHello,(void *)t);
	
		pthread_join(threads[0],NULL);
	/* Last thing that main() should do */
	pthread_exit("Exiting");
}
