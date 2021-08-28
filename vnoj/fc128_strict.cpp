#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> a(N+1);
    for (int i=1;i<=N;++i) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 1;
    int d = 1;
    for (int i=2;i<=N;++i) {
        if (a[i]==a[i-1]) d++;
        else {
            ans = 1ll*ans*(d+1)%MOD;
            d = 1;
        }
    }
    cout << 1ll*ans*(d+1)%MOD;
    //cout << ans;
    return 0;
}