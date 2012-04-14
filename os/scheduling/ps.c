#include<stdio.h>

int main()
{
	int i,j,k,n,st[10],at[10],wt[10],ft[10],tat[10],it,tt=0,ex[10],p[10];
	int ct,x,y;
	double NTAT = 0.0,temp = 0.0;
	printf("Enter The No. of Processes :");
	scanf("%d",&n);
	printf("Enter The Arrival Time and The Service Time and Priority for each Process: \n");
	for(i=0;i<n;i++)
	{
	       printf("Process %d : ",(i+1));
	       scanf("%d %d %d",&at[i],&st[i], &p[i]);   
	       ex[i] = 0;
	   
	}
	ct = at[0];
	x = 0;
	for(i=0;i<n;i++)
        {
                y =0 ;
                for(j=0;j<n;j++)
                { 
                        if(ex[j]==0 && y==0)
                        {
                                y = p[j];
                        }
                        if( (ex[j] ==0) &&  (at[j] <= ct)  && (p[j] <= y) )
                        {
                                y = p[j];
                                x = j;
                        }
                }
                wt[x] = ct - at[x];
                ct = ct + st[x];
                ft[x] = ct;
                tat[x] = ft[x] - at[x];
                ex[x] = 1;
	}
	
	
	printf("Process \t AT \t ST \t WT \t FT\t TAT\t   NTAT\n");
	for(i=0;i<n;i++)
	{
	       temp = (double)tat[i]/(double)st[i]; 
	       printf("%d \t\t %d \t %d \t %d \t %d \t %d \t %6.2f \n",i,at[i],st[i],wt[i],ft[i],tat[i],temp) ;
	       NTAT += (double)temp; 
	}
	printf("Average Time .....\n");
	printf("%6.2f ", (NTAT/n));
	return 0;

}
