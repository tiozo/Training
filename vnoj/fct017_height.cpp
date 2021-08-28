#include<bits/stdc++.h>
using namespace std;

inline bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.first!=b.first ? a.first<b.first : a.second<b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> a(N+1);
    vector<int> f(N+1);
    for (int i=1;i<=N;++i) { 
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end(),cmp);
    for (int i=1;i<=N;++i) {
        if (a[i].first!=a[i-1].first)
            f[a[i].second] = i-1;
        else f[a[i].second] = f[a[i-1].second];
    }
    for (int i=1;i<=N;++i) {
        cout << f[i] << ' ';
    }
    return 0;
}