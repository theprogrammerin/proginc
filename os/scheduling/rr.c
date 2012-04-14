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
        int at[10],st[10],rt[10],ft[10],e[10];
        int i,j,k,n,it,t,tt=0,r,cp,ex=0,itw,wt,tat;
        double ntat;
        ps("Enter Number Of Process : ");
        si(n);
        psn("Enter Arrival Time and Service Time for Each Process ");
        f(i,n,1)
        {
                ps("Process ");
                pi(i+1);
                ps(" : ");
                si(at[i]);
                si(st[i]);
                tt += st[i];
                rt[i] = st[i];
                e[i] = 0;
        }
        ps("Enter Time Interval : ");
        si(it);
        itw = it;   
        cp =0;
        t=0;
        while(ex!=n)
        {
        	if(at[cp]<=t && rt[cp]>0)
        	{
        		rt[cp] -= itw;
        		t = t+itw;
        	}
        	
        	if(rt[cp]<0)
        	{
        		itw = itw - rt[cp];
        		t = t + rt[cp];
        		rt[cp]=0;
        	}
        	else
        	{
        		itw = it;
        	}
        	if(rt[cp]==0 && e[cp]==0)
        	{
        		ft[cp] = t;
        		ex++;
        		e[cp] = 1;
        	}
        	cp++;
        	if(cp>=n) 
        		cp=0;
        }
        psn("PID\tAT\tST\tFT\tWT\tTAT\tNTAT\t");
        f(i,n,1)
        {
        	wt = ft[i] - st[i] - at[i];
        	tat = ft[i] - at[i];
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
