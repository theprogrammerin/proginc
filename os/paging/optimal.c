#include<stdio.h>
#define ps(x) 	printf("%s",x)
#define si(x) 	scanf("%d",&x)
#define f(x,y,z) 	for(x=0; x<y; x+=z)
#define pi(x)	printf("%d ",x);

int main()
{
	int n,t,l[50],c,qu[10];
	int i,j,k,flag =0,rl,d;
	ps("Enter No. of Pages : ");
	si(n);
	ps("Enter The Page ID's ");
	f(i,n,1)
	{
		si(l[i]);
	}
	ps("Enter Cache Size : ");
	si(c);
	t =0;
	f(i,n,1)
	{
		printf("PID #%d : ",l[i]);
		f(j,t,1)
		{
			if(qu[j] == l[i])
			{
				flag = 1;
				ps("Available - ");
				break;
			}
			else
			{
				flag = 0;
			}
		}
		if(flag == 0)
		{
			if(t<c)
			{
				qu[t] = l[i];
				t++;	
			}
			else
			{
				ps("Fault - ");
				d = 0;
				rl = 0;
				for(k = 0 ; k < t; k++)
				{
					for(j = i; j<n ; j++)
					{
						if( l[j] == qu[k] )
							break;
					}
					if( (j-i) >= d)
					{
						d = j-i;
						rl = k;
					}
				}
				for(j = k ; k< t-1; k++)
					qu[k] = qu[k+1];
				qu[t-1] = l[i];
			}
		}
		f(j,t,1)
		{
			pi(qu[j]);
			ps(" "); 
		}
		ps("\n");
	}
	ps("\n");
	return 0;
}

/*
	*	@param 	n 	size of list
	*	@param 	t	top of queue
	*	@param 	l[]	list of page ID's 
	*	@param 	c	cache size
	*	@param	qu	queue for cache
	*	@param 	i,j,k	for parameters
	*	@param 	rl	replacement array location
	*	@param	d	distance
*/
