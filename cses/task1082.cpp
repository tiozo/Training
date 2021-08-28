#include<bits/stdc++.h>
using namespace std;

const unsigned long long mod = 1e9+7;

long long power(long long x,long long y, long long p) {
    long long res = 1;
    x = x%p;
    while (y>0) {
        if (y&1) {
            res = (res*x)%p;
        }
        y = y>>1;
        x = (x*x)%p;
    }
    return (res+p)%p;
}

long long modinv(long long x) {
    return power(x,mod-2,mod);
}

long long sum(long long n) {
    long long tmp_val = ((((n%mod)*((n+1)%mod))%mod)*modinv(2))%mod;
    return tmp_val;
}

long long divisorsum(long long n) {
    long long l = 1;
    long long ans = 0;
    while (l<=n) {
        long long k = n/l;
        long long r = n/k;
        ans += ((sum(r)-sum(l-1)%mod)*k)%mod;
        ans %= mod;
        l = r + 1;
    }
    ans = ans % mod;
    if (ans<0) {
        return ans+mod;
    } else return ans;
}

int main() {
    unsigned long long n,e,a=0; cin >> n;
    for (unsigned long long i = 1;i<=sqrt(n);++i) {
        e = (n/i)%mod;
        if (e>=i) a = (a+(e-i)*i+e*(e+1)/2-i*(i-1)/2)%mod;
    }
    cout << a;
    return 0;
}

/*
    5 
    1 2 3 4 5
    15
    1 1
    2 2 1
    3 3 1
    4 4 2 1
    5 5 1
    total = 21
*/