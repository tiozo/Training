#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;
int N,K;
int a[maxn];
long long f[maxn][maxn][maxn>>1];
long long calc(int l,int r,int k) {
    if (k==0) return 0;
    if (l>r) return -1e15;
    long long &res = f[l][r][k];
    if (res!=-1) return res;
    res = max(calc(l+1,r,k),calc(l,r-1,k));
    if (l<=r-1) {
        res = max(res,calc(l,r-2,k-1) + abs(a[r]-a[r-1]));
        res = max(res,calc(l+2,r,k-1) + abs(a[l]-a[l+1]));
        res = max(res,calc(l+1,r-1,k-1) + abs(a[l]-a[r]));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i=1;i<=N;++i) cin >> a[i];
    memset(f,255,sizeof(f));
    cout << calc(1,N,K);
    return 0;
}