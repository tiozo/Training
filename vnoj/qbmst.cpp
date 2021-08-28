#include<bits/stdc++.h>
using namespace std;

class uv{
public:
    int u,v,c;
};

bool operator < (uv &a,uv &b) {
    return a.c < b.c;
}

class dsu {
private:
    vector<int> par,rank;
public:
    dsu (int size): par(size+1), rank(size+1,0) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
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
    dsu sett(N+1);
    vector<uv> a(M+1);
    for (int i=1;i<=M;++i) {
        cin >> a[i].u >> a[i].v >> a[i].c;
    }
    sort(a.begin(),a.end());
    int result = 0;
    for (uv &a:a) {
        if (sett.join(a.u,a.v)) result += a.c;
    }
    cout << result;
    return 0;
}