#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > dsk;

int cha[800];
int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

vector<int> stacks;
vector<bool> instack(800,false),visited(800,false);
void dfs(int u, dsk &ke) {
    visited[u] = true;
    instack[u] = true;
    stacks.push_back(u);
    for (int v:ke[u]) if (instack[v]) {
        v = find(v);
        while (stacks.back() != v) {
            cha[stacks.back()] = v;
            stacks.pop_back();
        }
    }
    for (int v: ke[u]) if (!visited[v]) dfs(v,ke);
    instack[u] = false;
    if (stacks.back() == u) stacks.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<vector<int> > a(N+1);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i=1;i<=N;++i) cha[i] = i;
    for (int i=1;i<=N;++i) if (!visited[i]) dfs(i,a);
    vector<int> F(N+1,0);
    for (int i=1;i<=N;++i) F[i] = (cha[i] == i);
    for (int i=1;i<=N;++i) {
        for (int j: a[i]) {
            if (find(i)!=find(j)) F[find(j)] = 0;
        }
    }
    int res = 0;
    for (int i=1;i<=N;++i) res+=F[i];
    cout << res;
    return 0;
}
