#include<bits/stdc++.h>
using namespace std;

auto cmp(pair<int,int> a,pair<int,int> b) {
    return a.first!=b.first ? a.first < b.first : a.second < b.second;
}

int main() {
    int N,T,res = 0; cin >> N >> T;
    vector<pair<int,int>> a(N+1);
    for (int i=1;i<=N;++i) cin >> a[i].first >> a[i].second;
    vector<int> f(6e3+1,0);
    sort(a.begin(),a.end(),cmp);
    for (int i=1;i<=N;++i) {
        int tmp = T;
        for (int j=T+a[i].first-1;j>=0;--j) {
            int pre = j-a[i].first;
            if (pre<0) break;
            f[j] = max(f[j],f[pre]+a[i].second);
            res = max(res,f[j]);
        }
    }
    cout << res;
    return 0;
}