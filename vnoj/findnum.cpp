#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll prime[] = {0, 2,3,5,7,11,13,17,19,23,29};
ll mxpow[] = {0, 59,37,25,21,17,16,14,14,13,12};

int main() {
    int N;
    cin >> N;
    vector<vector<ll> > dp(N+1,vector<ll> (12,0));
    for (int i=1;i<=N;++i) {
        for (int j=0;j<11;++j) {
            if (i==1) dp[i][j]=1;
            else if (j==0) dp[i][j] = LLONG_MAX;
            else {
                    dp[i][j]=dp[i][j-1];
                    for (ll mul=prime[j],k=1;k<=mxpow[j];++k, mul *= prime[j]) {
                    if( i % (k+1) == 0 && dp[i/(k+1)][j-1] <= INF/mul )
                        dp[i][j] = min(dp[i][j], dp[i/(k+1)][j-1] * mul);
                }
            }
        }
    }
    cout << dp[N][10] << endl;
    return 0;
}
