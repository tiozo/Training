#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int u,v,w;
};

bool cmp (uv&a,uv&b) {
    return a.w > b.w;
}

class dsu {
private:
    vector<int> par,rank;
public:
    dsu (int size):par(size+1), rank(size+1,0) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return u==par[u] ? u : par[u] = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u);
        v = find(v);
        if (u==v) return false;
        if (rank[u]==rank[v]) rank[u]++;
        if (rank[u]>rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M; 
    cin >> N >> M;
    uv a[M];
    for (uv &a:a) cin >> a.u >> a.v >> a.w;
    sort(a,a+M,cmp);
    dsu sett(N);
    int res = 0;
    for (uv &a:a) {
        if (!sett.join(a.u,a.v)) res+=a.w;
    }
    cout << res;
    return 0;
}