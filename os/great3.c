#include<stdio.h>

int main()
{
	int x,y,z,m;
	scanf("%d %d %d",&x,&y,&z);
	m = x>=y?x:y;
	m = m>=z?m:z;
	printf("\n The Max is %d",m);
	return 0;
}
