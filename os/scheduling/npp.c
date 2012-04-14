#include<stdio.h>
#define pi(x)   printf("%d ",x)
#define pit(x)  printf("%d \t",x);
#define pdn(x)  printf("%f \n",x);
#define ps(x)   printf("%s", x)
#define psn(x) printf("%s \n",x)
#define si(x)   scanf("%d",&x);
#define f(x,y,z)    for(x=0; x<y; x+=z)
#define ft(x,y,z)    for(x=z; x<=y; x+=z)
int main()
{
        int at[10],st[10],rt[10],ft[10],e[10],p[10];
        int i,j,k,n,wt,tat,cp=0,ep=0,ct=0,tt=0;
        double ntat;
        ps("Enter Number Of Process : ");
        si(n);
        psn("Enter Arrival Time, Service Time and Priority for Each Process ");
        f(i,n,1)
        {
                ps("Process ");
                pi(i+1);
                ps(" : ");
                si(at[i]);
                si(st[i]);
                si(p[i]);
                e[i] = 0;
                rt[i] = st[i];
                tt += st[i];
        }
        ps("Gantt Chart : ");
        while(ct<= tt)
        {
        	f(i,n,1)
        	{
        		if(rt[cp]==0)
        		{
        			cp = i;
        		}
        		if( (e[i]==0 && p[i] < p[cp] && at[i]<=ct) )
        		{
        			cp = i;
        		}	
        	}
        	if(at[cp]<=ct)
        	{
        		rt[cp]--;
        		if( rt[cp] == 0 )
        		{
        			e[cp] = 1;
        			ft[cp] = ct;
        		}
        		pi(cp+1);
        		ps(" ");
        	}
        	else
        	{
        		ps("-- ");
        	}
        	ct++;
        }
        psn("\n");
        psn("PID\tAT\tST\tFT\tWT\tTAT\tNTAT\t");
        f(i,n,1)
        {
        	wt = ft[i] - st[i] - at[i] + 1;
        	tat = ft[i] - at[i] + 1;
        	ntat = (double)tat / (double)st[i];
        	pit(i);
                pit(at[i]);
                pit(st[i]);
                pit(ft[i]);
                pit(wt);
                pit(tat);
                pdn(ntat);
        }
        return 0;
}
