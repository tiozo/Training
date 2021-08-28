#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> s(4,0);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    vector<vector<int>> d(N+1,vector<int>(N+1));
    //vector<vector<pair<int,int>>> a(N+1);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (i!=j) d[i][j] = 1e9;
            else d[i][j] = 0;
        }
    }
    {
        int u,v,c;
        while (cin >> u >> v >> c) {
            if (d[u][v]>c) {
                d[u][v]=c;
                d[v][u]=c;
            }
        }
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            if (d[i][k]<1e9) {
                for (int j=1;j<=N;++j) {
                    if (d[k][j]<1e9) {
                        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                    }
                }
            }
        }
    }
    //sort(s.begin(),s.end());
    int res = 1e9;
    do {
        for (int u = 1;u<=N;++u) {
            for (int v=1;v<=N;++v) {
                res = min(res,d[u][s[0]]+d[u][s[1]]+d[v][s[2]]+d[v][s[3]]+d[u][v]);
            }
        }
    } while (next_permutation(s.begin(),s.end()));
    cout << res;
    return 0;
}