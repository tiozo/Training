#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long long oo = 1e12;

long long x[N], y[N], u[N], v[N];
int n;

bool check(long long val) {
    long long L=-oo,R=oo,U=oo,D=-oo;
    for (int i=1;i<=n;++i) {
        L = max(L,y[i]-val); R = min(R,v[i]+val);
        D = max(D,x[i]-val); U = min(U,u[i]+val);
    }
    return L<R && D<U;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> x[i] >> y[i] >> u[i] >> v[i];
    long long l=0,r=oo,ans=-1; 
    while (l<=r) {
        long long mid = (l+r)>>1;
        if (check(mid)) {
            ans = mid; r = mid-1;
        } else l = mid+1;
    }
    cout << ans;
    return 0;
}