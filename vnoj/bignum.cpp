#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX   2611
using namespace std;
struct bignum
{
       int nd;
       int sb;
       int d[MAX];
       bignum()
       {
        nd=0;
       }     
       bignum(int x)
       {
        if (x==0)
           {
            nd=1;
            sb=1;
            d[1]=0;
           }
        if (x>0)
           {
            nd=0;
            sb=1;
            while (x>0)
                  {
                   nd++;
                   d[nd]=x%10;
                   x=x/10;
                  }            
           }
        if (x<0)
           {
            nd=0;
            sb=-1;
            x=-x;
            while (x>0)
                  {
                   nd++;
                   d[nd]=x%10;
                   x=x/10;
                  }
           }
       }
       bignum(const bignum &x)
       {
        nd=x.nd;
        sb=x.sb;
        int i;
        for (i=1;i<=nd;i=i+1) d[i]=x.d[i];
       }
       void input(void)
       {
        char s[MAX];
        scanf("%s",s);
        sb=1;
        nd=0;
        int i;
        for (i=strlen(s)-1;i>=0;i=i-1)
            {
             nd++;
             d[nd]=s[i]-48;
            } 
       }
       void print(void)
       {
        if (sb<0) printf("-");
        int i;
        for (i=nd;i>=1;i=i-1) printf("%d",d[i]);        
       }              
       bignum abs()
       {
        bignum r=bignum(*this);
        r.sb=1;
        return (r);
       }
       int cmp(const bignum&x)
       {
        if (sb>x.sb) return (1);        
        if (sb<x.sb) return (-1);
        if (nd>x.nd) return (sb);
        if (nd<x.nd) return (-sb);
        int i;
        for (i=nd;i>=1;i=i-1)
            {
             if (d[i]>x.d[i]) return (sb);
             if (d[i]<x.d[i]) return (-sb);
            }
        return (0);
       }
       bignum operator + (const bignum &x) // only compatible for non-negative integer
       {
        int n=max(nd,x.nd);
        int i,s,c;
        bignum res (*this);
        res=bignum();
        res.sb=1;;
        s=0;c=0;
        for (i=nd+1;i<=n;i=i+1) d[i]=0;
        //for (i=x.nd+1;i<=n;i=i+1) x.d[i]=0;
        for (i=1;i<=n;i=i+1)
            {
             s=d[i]+x.d[i]+c;
             if (s>9) c=1;
             else c=0;
             res.nd++;
             res.d[res.nd]=s%10;
            }
        if (c>0)
           {
            res.nd++;
            res.d[res.nd]=1;
           }
        return (res);
       }
       bignum operator - (const bignum &x) // only compatible for non-negative integer
       {
        int tmp=cmp(x);
        if (tmp>0)
           {
            bignum res;
            res=bignum();
            res.sb=1;
            int i,s,c;
            //for (i=x.nd+1;i<=nd;i=i+1) x.d[i]=0;
            s=0;
            c=0;                
            for (i=1;i<=nd;i=i+1)
                {
                 s=d[i]-x.d[i]-c;
                 if (s<0)
                    {
                     s=s+10;
                     c=1;
                    }
                 else c=0;
                 res.nd++;
                 res.d[res.nd]=s%10;                 
                }
            while (res.d[res.nd]==0) res.nd--;            
            return (res);
           }       
        if (tmp==0) return (bignum(0));
        if (tmp<0)
           {
            bignum res;
            res=bignum();
            int i,s,c;
            res.sb=-1;
            s=0;c=0;
            for (i=nd+1;i<=x.nd;i=i+1) d[i]=0;
            for (i=1;i<=x.nd;i=i+1)
                {
                 s=x.d[i]-d[i]-c;
                 if (s<0)
                    {
                     s=s+10;
                     c=1;
                    }
                 else c=0;
                 res.nd++;
                 res.d[res.nd]=s%10;
                }                
            while (res.d[res.nd]==0) res.nd--;
            return (res);
           }     
       }
       bignum operator * (const bignum &x) //compatible for all numbers
       {
        if ((nd==1) && (d[1]==0)) return (bignum(0));
        if ((x.nd==1) && (x.d[1]==0)) return (bignum(0));
        bignum res;
        res=bignum();
        res.sb=sb*x.sb;
        int i,j,s,c;
        for (i=1;i<=x.nd;i=i+1)
            {
             bignum tmp=bignum();
             for (j=1;j<i;j=j+1)
                 {
                  tmp.nd++;
                  tmp.d[tmp.nd]=0;                  
                 }
             s=0;c=0;
             for (j=1;j<=nd;j=j+1)
                 {
                  s=d[j]*x.d[i]+c;
                  c=s/10;
                  tmp.nd++;
                  tmp.d[tmp.nd]=s%10;                  
                 }
             while (c>0)
                   {
                    tmp.nd++;
                    tmp.d[tmp.nd]=c%10;
                    c=c/10;
                   }
             res=res+tmp;
            }
        return (res);
       }
};
bignum a,b,c;
int main(void)
{
    a.input();
    b.input();
    c=a+b;
    c.print();
    printf("\n");
    c=a-b;
    c.print();
    printf("\n");
    c=a*b;
    c.print();
    printf("\n");   
}
