#include<stdio.h>
int main()
{
	int i,j,k,n,st[50],at[50],wt[50],ft[50],tat[50];
	double NTAT = 0.0,temp = 0.0;
	printf("Enter The No. of Processes :");
	scanf("%d",&n);
	printf("Enter The Arrival Time and The Service Time for each Process: \n");
	for(i=0;i<n;i++)
	{
	       printf("Process %d : ",(i+1));
	       scanf("%d %d",&at[i],&st[i]);
	}
	printf("Calculating Time.....\n");
	printf("Final Operating Tmie for each Process\n");
	printf("Process \t AT \t ST \t WT \t FT\t TAT\t   NTAT\n");
	wt[0] = 0;
	ft[0] = st[0];
	for(i=0;i<n;i++)
	{
	       if(i!=0)
	       {
	               wt[i] = ft[i-1] - at[i];
	               ft[i] = at[i] + wt[i] + st[i];
	       }
	       tat[i] = wt[i] + st[i];
	       temp = (double)tat[i]/(double)st[i]; 
	       printf("%d \t\t %d \t %d \t %d \t %d \t %d \t %6.2f \n",i,at[i],st[i],wt[i],ft[i],tat[i],temp) ;
	       NTAT += (double)temp; 
	}
	printf("NTAT total = %6.2f \n",NTAT);
	printf("Task Completed \n");
	return 0;

}
