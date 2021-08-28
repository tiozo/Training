#include<bits/stdc++.h>
using namespace std;
    
const int maxn = 1e6+5;
const int maxd = 15; 
int N,M,ans[maxn];
bool memo[maxn][maxd];
vector<int> a[maxn];

inline void dfs(int u,int d,int c) {
    if (d<0 || memo[u][d]) return;
    memo[u][d] = true;
    if (ans[u] == 0) {
        ans[u] = c;
    }
    for (int v:a[u]) {
        dfs(v,d-1,c);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int Q; cin >> Q;
    vector<int> V(Q+1),c(Q+1),d(Q+1);
    for (int i=1;i<=Q;++i) {
        cin >> V[i] >> d[i] >> c[i];
    }
    for (int i=Q;i>=1;--i) {
        dfs(V[i],d[i],c[i]);
    }
    for (int u=1;u<=N;++u) {
        cout << ans[u] << '\n';
    }
    return 0;
}