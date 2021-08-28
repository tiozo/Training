///prim N*N
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    vector<int> d(N+1,1e9);
    vector<bool> vs(N+1,0);
    for (int i=1;i<=N;++i) {
        int tmp;
        cin >> tmp;
        a[i][0] = a[0][i] = tmp;
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    for (int z=N;z--;) {
        int u = -1;
        for (int i=0;i<=N;++i) {
            if (!vs[i]) {
                if (u<0 || d[u] > d[i]) u = i;
            }
        }
        if (u<0) break;
        vs[u] = true;
        for (int i = 0;i<=N;++i) {
            if (!vs[i]) {
                d[i] = min(d[i],a[i][u]);
            }
        }
    } 
    int res = 0;
    for (int i=1;i<=N;++i) {
        res+=d[i];
    }
    cout << res;
    return 0;
}