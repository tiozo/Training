#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    while (cin >> n >> m) {
        for (int i=1;i<=n;++i) {
            cin >> a[i];
        }
        for (int i=1;i<=m;++i) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        scc();
        for (int i=1;i<=n;++i) {
            if (dfs2(a[i])==true) {

            }
        }
    } 
    return 0;  
}