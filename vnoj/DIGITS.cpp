#include<bits/stdc++.h> 
using namespace std;
const int N=350;
int a[500],s[500];
int main(){
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    for (int i=0;i<n;++i){
        int x;
        cin>>x;
        for (int j=N;j>=1;--j){
            s[j]=s[j+1]+a[j];
        }
        for (int j=1;j<=N;++j){
            if (a[j]==9) continue;
            int tmp=x-(s[j]+1);
            if (tmp<0) continue;
            int t1=tmp/9;
            int t2=tmp%9;
            if (t2!=0) t1++;
            if (t2==0) t2=9;
            if (t1<=j){
                if (t1<j){
                    a[j]++;
                    for (int k=1;k<j;++k) a[k]=0;
                    for (int k=1;k<=t1;++k){
                        a[k]=9;
                    }
                    if (t2!=0) a[t1]=t2;
                    break;
                }
                else{
                    if (a[j]+1+t2<=9){
                        for (int k=1;k<t1;++k){
                            a[k]=9;
                        }
                        a[j]=a[j]+1+t2;
                        break;
                    }
                }
            }
        }
        bool kt=false;
        for (int j=N;j>=1;--j){
            if (a[j]!=0) kt=true;
            if (kt) cout<<a[j];
        }
        cout<<"\n";
    }
}