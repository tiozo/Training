#include<bits/stdc++.h>
using namespace std;

//const long long oo = 1000000000;
long long powmod(long long a,long long b,long long N) {
    if (b==0) return 1;
    long long res = powmod(a,b/2,N);
    return (b%2==1) ? (((res*res)%N)*a)%N : ((res*res)%N); 
}

bool Miller(long long N,long long s,long long m) {
    long long a = (long long) rand() % (N-2) + 2, b = powmod(a,m,N);
    long long pre = N-1;
    for (int i = s; i>=0;--i) {
        if (b==1) return pre = N-1;
        pre = b; b = (b*b)%N;
    }
    return 0;
}

bool prime(long long n) {
    if(n == 2) return 1;
    if(n % 2 == 0 || n < 2) return 0;
    long long s = 63 - __builtin_clzll((n-1)&(1-n)), m = (n-1) >> s;
    for(int k=0; k<30; ++k) 
        if(!Miller(n, s, m)) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(nullptr));
    int N; cin >> N; long long x;
    while (N--) {
        cin >> x;
        while (!prime(--x));
        cout << x << '\n';
    }
    return 0;
}