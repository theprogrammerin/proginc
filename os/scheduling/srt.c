#include<stdio.h>

int main()
{
	int i,j,k,n,st[10],at[10],wt[10],ft[10],tat[10],tt=0,ex[10],rt[10];
	int ct,x,y,it=0;
	double NTAT = 0.0,temp = 0.0;
	printf("Enter The No. of Processes :");
	scanf("%d",&n);
	/*printf("Enter Interval : ");
	scanf("%d",&it);*/
	printf("Enter The Arrival Time and The Service Time for each Process: \n");
	for(i=0;i<n;i++)
	{
	       printf("Process %d : ",(i+1));
	       scanf("%d %d",&at[i],&st[i]);   
	       ex[i] = 0;
	       rt[i] = st[i];
	       tt += st[i];
	}
	ct = at[0];
	x =0;
	wt[0] = 0;
	while(ct<=tt)
	{
	       ct++;
	       rt[x]--;
	       if(rt[x]==0)
	       {
	               ft[x] = ct;
	               ex[x] = 1;
	               tat[x] = ft[x] - at[x];
	               wt[x] = tat[x] - st[x];
	       }
	       y=0;
	       for(j=0;j<n;j++)
                { 
                        if(ex[j]==0 && y==0)
                        {
                                y = rt[j];
                        }
                        if( (ex[j] ==0)  &&  (at[j] <= ct) && rt[j] <= y)
                        {
                                y = rt[j];
                                x = j;
                        }
                }
	 
	}


	
	printf("Process \t AT \t ST \t WT \t FT\t TAT\t   NTAT\n");
	for(i=0;i<n;i++)
	{
	       temp = (double)tat[i]/(double)st[i]; 
	       printf("%d \t\t %d \t %d \t %d \t %d \t %d \t %6.2f \n",i,at[i],st[i],wt[i],ft[i],tat[i],temp) ;
	       NTAT += (double)temp; 
	}
	printf("Average Time .....");
	printf("%6.2f \n ", (NTAT/n));
	return 0;

}
