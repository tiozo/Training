#include<bits/stdc++.h>
using namespace std;

vector<int> P,L;
int Bridge;
void dfs(int u,const vector<vector<int>> &a) {
    for (auto v:a[u]) if (v!=P[u]) {
        P[v] = u;
        L[v] = L[u]+1;
        dfs(v,a);
    } else return;
}

void LCA(int u,int v) {
#define up(u) u = P[u]
    while (L[u] > L[v]) up(u), Bridge++;
    while (L[v] > L[u]) up(v), Bridge++;
    while (u!=v) up(u), up(v), Bridge++;
    return;
} 

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N,M; 
        cin >> N >> M;
        P.resize(100,0);
        L.resize(100,0);
        vector<vector<int>> a(1000);
        Bridge = 0;
        for (int i=1;i<=M;++i) {
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            dfs(u,a);
            LCA(u,v);
            cout << Bridge << '\n';
        }
    }
    return 0;
}