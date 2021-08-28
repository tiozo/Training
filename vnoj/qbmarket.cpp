#include<bits/stdc++.h>
using namespace std;

int n,s;
int c[501],m[501];
long long f[100001][501];
bool kq[100001][501];
long long res = 0;

inline long long dp(long long i,long long j) {
    //if (j>n) return 0;
    if (i==0) return 1;
    if (j==0) return 0;
    if (kq[i][j]==1) return f[i][j];
    long long res = 0;
    for (int t=0;t<=m[j];++t) {
        if (i>=c[j]*t) {
            res = (res+dp(i-c[j]*t,j-1));
        }
    } 
    kq[i][j] = 1;
    return f[i][j] = (res);
    //cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s >> n;
    for (int i=1;i<=n;++i) {
        cin >> c[i] >> m[i];
    }
    //memset(kq,0,sizeof kq);
    res = dp(s,n);
    cout << res;
    //return 0;
}

/*
    
*/