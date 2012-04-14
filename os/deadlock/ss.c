#include <stdio.h>

#define pi(x)	printf("%d",x)
#define	si(x)	scanf("%d",&x)
#define ps(x)	printf("%s",x)
	
	int claim[10][10],alloc[10][10],resrc[10],avail[10],req[10][10];
	int m,n;
	
int safe()
{
	int i,j,k,c;
	int f1,f2,f3,fm;
	int dp=0;
	c = m;
	while(c>0)
	{
		f2 = 0;
		for(i=0;i<m;i++)
		{
			f1 = 0;
			f3 = 1;
			for(j=0;j<n;j++)
			{
				if(claim[i][j] == 0 && f3==1)
					f3 = 1;
				else
					f3 = 0;
			}
			if(f3)
				continue;
			for(j=0;j<n;j++)
			{
				if(alloc[i][j] + avail[j] >= claim[i][j]) //checking for requirements
					f1 = 1; 
				else
				{
					dp = i;
					break;
				}
			}
			if(f1)
			{
				ps("\nProcess");
				pi((i+1));
				ps(" Executed");
				for(j=0; j<n; j++)
				{
					claim[i][j] = 0;
					avail[j] += alloc[i][j];
					alloc[i][j] = 0;
					req[i][j] = 0;
				}
				f2 = 1;
				break;
			}
		}
		if(!f2)
		{
			printf("\nDeadlock Occured between Process ");
			for(i=0;i<m;i++)
			{
				f3 = 1;
				for(j=0;j<n;j++)
				{
					if(claim[i][j] == 0 && f3==1)
						f3 = 1;
					else
						f3 = 0;
				}
				if(!f3)
					printf("%d ",(i+1));
			}
			return 0;
			break;
		}
		else
		{
			c--;
			ps("\nAvailable Vector : ");
			for(i = 0; i<n; i++)
			{
				pi(avail[i]);
				ps(" ");
			}
			ps("\n");
		}
	}
	if(c==0)
		return 1;
}
int main()
{
	int i,j,k,c;
	ps("Enter Number of Process : ");
	si(m);
	ps("Enter Number of Resources :");
	si(n);
	ps("Enter Claim Matrix : \n");
	for(i = 0; i<m; i++)
	{
		printf("Process %d :",(i+1));
		for(j=0;j<n;j++)
			si(claim[i][j]);
		ps("\n");
	}
	ps("Enter Allocation Matrix : \n");
	for(i = 0; i<m; i++)
	{
		printf("Process %d :",(i+1));
		for(j=0;j<n;j++)
		{
			si(alloc[i][j]);
			req[i][j] = claim[i][j] - alloc[i][j];
		}
		ps("\n");
	}
	ps("Enter Resource Vector : ");
	for(i = 0; i<n; i++)
	{
		si(resrc[i]);
		avail[i] = resrc[i];
		for(j=0;j<m;j++)
		{
			avail[i] -= alloc[j][i]; 
		}
	}
	ps("\n");
	
	if(safe()==0)
	{
		ps("\nNot Safe\n");
	}
	else
	{
		ps("\nSafe\n");
	}
	return 0;
}
