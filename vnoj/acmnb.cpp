#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
    return (a.first-a.second<b.first-b.second);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    int res = 0;
    vector<pair<int,int>> a(2*N);
    for (pair<int,int> &a:a) {
        cin >> a.first >> a.second;
    }
    sort(a.begin(),a.end(),cmp);
    for (int i=0;i<N;++i) {
        res+=a[i].first;
    }
    for (int i=N;i<2*N;++i) {
        res+=a[i].second;
    }
    cout << res;
    return 0;
}