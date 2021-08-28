#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,d,t; cin >> N >> t;
    long long res = 0; res = t;
    for (int i=2;i<=N;++i) {
        cin >> d;
        if (d>t) res += d-t;
        t = d;
    }
    cout << res;
    return 0;
}