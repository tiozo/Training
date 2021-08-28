#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
const int logn=19;
struct uc {
    int u,c;
};
typedef vector<vector<uc>> dsk;
int P[maxn][logn],L[maxn],d1[maxn][logn],d2[maxn][logn];
dsk a;

void dfs(int u) {
    for (auto p:a[u]) {
        int v = p.u, w = p.c;
        if (v!=P[u][0]) {
            P[v][0] = u; L[v] = L[u] + 1;
            d1[v][0] = d2[v][0] = w;
            dfs(v);
        }
    }
}

void preprocess(int N) {
    for (int j=1;1<<j <= N;++j) {
        for (int i=0;i <= N;++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
                d1[i][j] = min(d1[i][j-1],d1[P[i][j-1]][j-1]);
                d2[i][j] = max(d2[i][j-1],d2[P[i][j-1]][j-1]);
            }
        }
    }
}

void LCA(int N,int u,int v) {
    int tmp, log = 0, i;
    pair<int,int> ans={1e9,-1e9};
    if (L[u]<L[v]) swap(u,v);
    for (;1<<log<=L[u];++log); --log;
    for (int i = log;i>=0;--i) {
        if (L[u] - (1<<i) >= L[v]) {
            ans.first = min(ans.first,d1[u][i]);
            ans.second = max(ans.second,d2[u][i]);
            u = P[u][i];
        }
    }
    if (u!=v) {
        for (int i = log;i>=0;--i) 
            if (P[u][i] != P[v][i]) {
                ans.first = min(ans.first,min(d1[v][i],d1[u][i]));
                ans.second = max(ans.second,max(d2[v][i],d2[u][i]));
                u = P[u][i]; v = P[v][i];
            }
        ans.first = min(ans.first,min(d1[v][0],d1[u][0]));
        ans.second = max(ans.second,max(d2[v][0],d2[u][0]));
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,Q;
    cin >> N;
    a.resize(N+1);
    for (int i=1;i<N;++i) {
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    cin >> Q;
    memset(P,-1,sizeof P);
    dfs(1);
    preprocess(N+1);
    while (Q--)
    {   int u,v; cin >> u >> v;
        LCA(N,u,v);
    }
    return 0;
}