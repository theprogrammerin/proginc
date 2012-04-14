#include<stdio.h>

int main()
{
	int n,f,i;
	scanf("%d",&n);
	i = 1;
	f = 1;
	while(i<=n)
	{
		f = f * i;
		i++;
	}	
	printf("Factorial is : %d",f);
	return 0;
}
