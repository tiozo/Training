#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int N,x;
        cin >> N >> x;
        long long res = 0;
        vector<pair<long long,long long>> a(N+1,{0,1});
        for (int i=1;i<=N;++i) {
            cin >> a[i].first;
            res += a[i].first;
        }
        int cur = 1;
        for (long long i=1;i<=a.size();++i) {
            if (a[i].first%x==0) {
                a.push_back({a[i].first/x,a[i].second*x});
                res+=a[i].first*a[i].second;
            } else break;
        }
        cout << res << '\n';
    }
    return 0;
}