#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int pos,N,limit=100;
    pair<int,int> u;
    cin >> N;
    vector<pair<int,int>> a(N+1,{0,0});
    for (int i=1;i<=N;++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin()+1,a.end());
    vector<int> f(1e6+9,0);
    int res = 0;
    for(int j=1; j<=limit; j++) {
        pos = 0; for(int i=1; i<=N; i++) f[i] = 1;
        for(int i=2; i<=N; i++) {
            u = pair<int, int> (a[i].first - j, a[i].second);
            while (pos < N && a[pos + 1] <= u) pos++;
            if (a[pos].first == u.first && a[pos].second < u.second)
                f[i] = f[pos] + 1;
            res = max(res, f[i]);
        }
    }
    cout << res;
    return 0;
}

/// dãy B dài nhất của A là một dãy có chung phép cộng D;
/*
    gọi F[D] là dãy có phép cộng dài nhất
*/