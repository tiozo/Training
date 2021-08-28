#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b, long long md) {
    long long ans = 1;
    while(b){
        if (b&1) ans*=a;
        a*=a;b>>=1;
        a%=md; ans%=md;
    }
    return ans;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long a,b; cin >> a >> b;
        cout << power(a,b,1e9+7) << '\n';
    }
    return 0;
}