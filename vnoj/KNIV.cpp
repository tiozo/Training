#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9;
const int MAXLABLE=1e4;
long long T[MAXLABLE+1][11]={0};
void update(int p,int index,int val) {
    for (int i=p;i;i-=i&-i) {
        T[i][index]=(T[i][index]+val)%mod;
    }
}

long long Count(int p,int index) {
    long long res=0;
    for (int i=p;i<=MAXLABLE;i+=i&-i) {
        res=(T[i][index]+res)%mod;
    }
    return res;
}

int main() {
    long long n,k;
    cin >> n >> k;
    vector<int>  a(n+1,0);
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    long long res=0,t=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=k;++j) {
            if (j==1) t=1;
            else t=Count(a[i]+1,j-1);
            update(a[i],j,t);
            if(j == k) res = (res + t) % mod;
        }
    }
    cout << res;
    return 0;
}
