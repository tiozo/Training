#include<bits/stdc++.h>
using namespace std;

long long sub(long long n) {
    long long t = 1;
    long long c = n;
    for (long long i=2;i*i<=n;++i) {
        if (n%i==0) {
            t*=i;
            c*=(i-1);
            while (n%i==0) n/=i;
        }
    }
    if (n!=1) {
        c*=(n-1);
        t*=n;
    }
    return c/t;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        long long dem = sub(n);
        cout << dem << '\n';
    }
    return 0;
}