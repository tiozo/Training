#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int N,k,res = 0; cin >> N >> k;
    vector<int> a(N+1,0);
    vector<int> r(N+1,0);
    vector<int> dp(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        r[i] = abs(a[i] - a[i-1]);
    }
    dp[1]=0;
    for (int i=2;i<=N;++i) {
        for (int j=1;j<i;++j) {
            if (r[i]>abs(abs(a[i])-abs(a[j]))) {
                dp[i] = dp[j]+(j-i-1);
                if (dp[i]<=k) res = max(res,r[i]);
            } dp[i] = i-1;
        }
        //cout << dp[i] << ' ';
    }
    cout << res;
    return 0;
}