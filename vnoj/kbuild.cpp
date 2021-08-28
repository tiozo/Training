#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000;
int res,N;
vector<int> L(maxn+2),P(maxn+2),laboratory(maxn+1);
vector<vector<int>> a;

void dfs(int u) {
    for (auto v:a[u]) {
        if (v!=P[u]) {
            P[v] = u; L[v] = L[u] + 1;
            dfs(v);
        }
    } 
}

int find(int u) {
    if (laboratory[u]!=u) laboratory[u] = find(laboratory[u]);
    return laboratory[u];
}

void LCA(int u,int v) {
    while (u!=v) {
        u = find(u), v=find(v);
        if (u==v) break;
        int lu = L[u], lv = L[v];
        if (lu<=lv) v = laboratory[v] = P[v], res--;
        if (lv<=lu) u = laboratory[u] = P[u], res--;
    }
}

int main() {
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    a.resize(N+1);
    for (int i=2;i<=N;++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    res = N-1;
    for (int i=1;i<=N;++i) laboratory[i] = i;
    int Q; cin>> Q;
    while (Q--) {
        int u,v;
        cin >> u >> v;
        LCA(u,v);
    }
    cout << res;
    return 0;
}
