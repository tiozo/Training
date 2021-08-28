#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> check;
vector<int> f;
vector<vector<int>> a;

void dfs(int u) {
    check[u] = true;
    f[u] = 1;
    for (int v:a[u]) {
        if (!check[v]) {
            dfs(v);
            f[u] += f[v];
        }
    }
}

int main() {
    cin >> N >> M;
    a.resize(N+1);
    check.resize(N+1,0);
    f.resize(N+1,0);
    while (M--) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> components;
    for (int i=1;i<=N;++i) {
        if (!check[i]) {
            dfs(i);
            components.push_back(f[i]);
        }
    }
    int res = components.front();
    int ans = 0;
    for (int i=1;i<components.size();++i) {
        ans = max(ans,components[i]);
    }
    cout << res + ans;
    return 0;
}