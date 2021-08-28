#include<bits/stdc++.h>
using namespace std;

bool isprime(long long p) {
    if (p < 2) return false;
    if (p == 2) return true;
    if (p % 2 == 0) return false;
    for (long long d = 3; d * d <= p; d += 2) {
        if (p % d == 0) return false;
    }
    return true;
}

int main() {
    long long n; scanf("%lld",&n);
    //cout << n;
    for (int q=2;q<64;++q) {
        long long p = round(exp(log(n)/q));
        long long nn = 1;
        for (int i=0;i<q;++i) nn *= p;
        if (nn==n && isprime(p)) {
            printf("%lld %d",p,q);
            return 0;
        }
    }
    printf("%d\n",0);
    return 0;
}