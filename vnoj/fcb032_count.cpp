#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<set<int>> color;
vector<int> id;
vector<bool> vs;
inline void dfs(int u) {
    vs[u] = 1;
    for (const int &v:a[u]) {
        if (!vs[v]) {
            dfs(v);
            int pu = id[u], pv = id[v];
            if (color[pu].size() >= color[pv].size()) {
                for (const int&e:color[pv]) if (!color[pu].count(e)) color[pu].insert(e); 
            } else {
                id[u] = id[v];
                for (const int&e:color[pu]) if (!color[pv].count(e)) color[pv].insert(e); 
            }
            ans[u] = color[id[u]].size();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,p;
    cin >> N;
    ans.resize(N+1);
    id.resize(N+1);
    a.resize(N+1);
    color.resize(N+1);
    vs.resize(N+1);
    for (int i=1;i<N;++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1;i<=N;++i) {
        cin >> p;
        color[i].insert(p);
        id[i] = i;
        ans[i] = 1;
    }
    dfs(1);
    for (int i=1;i<=N;++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}