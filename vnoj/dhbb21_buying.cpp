#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const long long oo = 1e18;
const long long N = 3003;

ll dp[N][N], a[3003], b[3003], c[3003], n, ans = oo;

void minimize(ll &a, ll b){
    if (a > b) a = b;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    //dp theo b va c.
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
                dp[i][j] = oo;
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            if (i + j <= n) {
                ll idx = i + j;
                if (j)
                    minimize(dp[i][j], dp[i][j-1] + b[idx] - j + 1);
                if (i)
                    minimize(dp[i][j], dp[i-1][j] + c[idx] - i + 1);
                if (i + j == n)
                    minimize(ans, dp[i][j]);
            }
    /* greedy 
    int reduce = 0;
    ll A=0,B=0,C=0;
    for (int i=1;i<=n;i++) {
        A+=a[i];
        B+=(b[i]-i+1);
        C+=(c[i]-i+1);
    }*/
    //ans = min({A,B,C});
    cout << ans;
    return 0;
}


