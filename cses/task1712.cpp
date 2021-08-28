#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int exp(int x,unsigned int y,int p) {
    int res = 1; x%=p;
    while (y>0) {
        if (y&1) res = (res*x)%p; 
        y>>=1; x=(x*x)%p;
    }
    return res;
}

int solve(int a,int b,int c) {
    int r = exp(b,c,mod-1);
    return exp(a,r,mod);
}

int32_t main() {
    int tc; cin >> tc;
    while (tc--) {
        int a,b,c; cin >> a >> b >> c;
        cout << solve(a,b,c) << '\n';
    }
    return 0;
}