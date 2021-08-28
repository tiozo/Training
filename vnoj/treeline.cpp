#include<bits/stdc++.h>
using namespace std;

const int N = 1e5, V = 2*(N+1), MOD = 1e9;
bool isp[V+1];
int p[V+1], c[V+1], a[N], n,np;

void eratos() {
    memset(isp,-1,sizeof isp);
    isp[0] = isp[1] = false;
    for (int i=2;i*i<=V;++i) if (isp[i]) 
        for (int j=i+i;j<=V;j+=i) 
            isp[j] =false;
    for (int i=2;i<=V;++i) if (isp[i]) 
        p[np++] = i;
}

void t1() {
    int res = 2, mn = a[n-1];
    for (int i=n-2;i>=0;--i) {
        if (a[i]<=mn) ++res, mn = a[i];
        else break;
    }
    cout << res << '\n';
}

void analysis(int n, bool dec) {
    for(int i = 0; i < np; ++i) {
        long long x = p[i];
        while(x <= n) {
            if(dec) c[i] -= n / x;
            else c[i] += n / x;
            x *= p[i];
        }
    }
}

long long powmod(long long a, long long n) {
    long long res = 1;
    for(; n != 0; n >>= 1) {
        if(n & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

void t2() {
    ++n;
    analysis(2*n, false);
    analysis(n, true);
    analysis(n+1, true);
    long long res = 1;
    for(int i = 0; i < np; ++i)
        res = res * powmod(p[i], c[i]) % MOD;
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    eratos();
    int h; cin >> n >> h;
    for (int i=0;i<n;++i) cin >> a[i];
    t1(); t2();
    return 0;
}