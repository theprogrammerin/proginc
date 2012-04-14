#include<stdio.h>
int main()
{
	int x,y,z,n;
	x = -1;
	y = +1;
	z = x+y;
	scanf("%d",&n);
	while(z<=n)
	{
		printf("%d ",z);
		x = y;
		y = z;
		z = x+y;
	}
	return 0;
}
