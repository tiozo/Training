#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> a(N+1);
    vector<int> b(N+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=N;++i) {
        cin >> b[i];
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    int t=N, res = 2e9;
    for (int i=1;i<=N;++i) {
        for(res=min(res,abs(a[t]+b[i]));t>1&&abs(a[t-1]+b[i])<=abs(a[t]+b[i]);--t) res = min(res,abs(a[t-1]+b[i]));
    }
    cout << res;
    return 0;
}