#include<bits/stdc++.h>
using namespace std;
#define u first
#define c second
int N,M,K;
vector<vector<int>> g;
vector<vector<int>> trace;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    g = vector<vector<int>>(N+1,vector<int>(N+1));
    trace = vector<vector<int>>(N+1,vector<int>(N+1));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (i==j) g[i][j] = 0;
            else g[i][j] = 1e9;
        }
    }
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        cin >> g[u][v];
        g[v][u] = g[u][v];
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) trace[i][j] = j;
    }
    for (int k=1;k<=N;++k) {
        for (int u=1;u<=N;++u) {
            for (int v=1;v<=N;++v) {
                if (g[u][v] > g[u][k] + g[k][v]) {
                    g[u][v] = g[u][k]+g[k][v];
                    trace[u][v] = trace[u][k];
                }
            }
        }
    }
    while (K--) {
        int q,u,v;
        cin >> q >> u >> v;
        int x = u;
        if (q) {
            vector<int> s;
            do {
                s.push_back(u);
                u = trace[u][v];
            } while (u!=v);
            s.push_back(v);
            cout << s.size();
            for (int i=0;i<s.size();++i) {
                cout << ' ' << s[i];
            }
            cout << '\n';
        } else cout << g[u][v] << '\n';
    }
    return 0;
}