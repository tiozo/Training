#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
int dfs(int u,int cha,vii &a,vi &visited,vi &instack) {
    visited[u] = 1;
    instack[u] = 1;
    int res = 0;
    for (int v : a[u]) if (v!=cha) {
        if (instack[v]) res++;
        if (!visited[v]) res += dfs(v,u,a,visited,instack);
    }
    instack[u] = 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    vii a(N+1);
    vi visited(N+1,0);
    vi instack(N+1,0);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v; 
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    int res = 0;
    for (int i=1;i<=N;++i) {
        if (!visited[i]) {
            res += dfs(i,0,a,visited,instack);
        }
    }
    cout << res;
    return 0;
}