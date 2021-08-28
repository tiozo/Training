#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int n,k;

int contains(int mask,int i) {
    if (i>20) return 0;
    return (mask>>i)&1;
}

void dfs(int u,int father,const vector<vector<int>>&adj,
         const vector<int>&c,const int cant,vector<int>&f) {
    if (contains(cant,c[u])) {
        f[u] = 0;
    } else f[u] = 1;
    for (int v:adj[u]) {
        if (v==father) continue;
        dfs(v,u,adj,c,cant,f);
        int cnt_v = (1+f[v])%mod;
        f[u] = (f[u]*cnt_v)%mod;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    while (cin >> n >> k) {
        vector<int> c(n);
        for (int &x:c) {
            cin >> x; --x;
        }
        vector<vector<int>> adj(n);
        for (int i=0;i<n-1;++i) {
            int u,v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        for (int cant=0;cant<(1ll<<k);++cant) {
            vector<int>f(n,0);
            dfs(0,-1,adj,c,cant,f);
            int sum = std::accumulate(f.begin(), f.end(), 0LL) % mod;
            if (__builtin_popcount(cant)%2==0) {
                res = (res+sum)%mod;
            } else res = (res-sum+mod)%mod;
        }
        cout << res << '\n';
        break;
    }
    return 0;
}