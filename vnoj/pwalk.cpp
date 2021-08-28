#include<bits/stdc++.h>
using namespace std;

int N,Q;
struct uc {
    int u,c;
};
typedef vector<uc> vi;
typedef vector<vi> dsk;
vector<int> d,par,bac;
void dfs(int u,const dsk &a) {
    for (auto p: a[u]) if (p.u!=par[u]) {
        int v = p.u, c = p.c;
        d[v] = c;
        par[v] = u;
        bac[v] = bac[u] + 1;
        dfs(v,a);
    }
}

int solve(int u, int v) {
#define up(u) sum += d[u], u = par[u]
    int sum = 0;
    while (bac[u] > bac[v]) up(u);
    while (bac[v] > bac[u]) up(v);
    while (u != v) up(u), up(v);
    return sum;
}

int main() {
    cin >> N >> Q;
    dsk a(N+1);
    d.resize(N+1,0);
    par.resize(N+1,0);
    bac.resize(N+1,0);
    for (int i=1;i<N;++i) {
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    dfs(1,a);
    while (Q--) {
        int u,v;
        cin >> u >> v;
        cout << solve(u,v) << '\n';
    }
    return 0;
}