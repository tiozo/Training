#include<bits/stdc++.h>
using namespace std;

const int more = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> a((N<<1));
    //vector<int> point;
    for (int i=0;i<N;++i) {
        cin >> a[i].first;
        a[i].second=0;
    }
    for (int i=N;i<(N<<1);++i) {
        cin >> a[i].first;
        a[i].second=1;
    }
    sort(a.begin(),a.end());
    bool skip = false; int res = 0;
    for (int i=0;i<(N<<1)-1;++i) {
        if (skip) skip = false;
        else if (a[i].second!=a[i+1].second) {
            ++res;
            skip = 1;
        }
    }
    cout << res;
    return 0;   
}