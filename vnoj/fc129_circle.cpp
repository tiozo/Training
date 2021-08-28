#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 1e5+7;
pair<ll,ll> a[maxn];
map<ll,ll> trace;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long N; cin >> N;
    for (ll i=1;i<=N;++i) {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = 1;
    sort(a+1,a+1+N,[&](pair<ll,ll>a,pair<ll,ll>b) {
        return a.second < b.second;
    });
    for (ll i=1;i<=N;++i) {
        ll r = a[i].second, x = a[i].first;
        ll cnt = 1, right = x + r, left;
        while(trace.find(right) != trace.end() && (left = trace[right]) >= x - r)
            right = left;
        if(right == x - r) ++cnt;
        ans += cnt;
        trace[x + r] = x - r;
    }
    cout << ans;
    return 0;
}