#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int u,v,z;
};

bool operator < (uv &a,uv &b) {
    return a.z < b.z;
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
        return par[u] == u ? u : par[u]=find(par[u]);
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
    int P,N=0;
    cin >> P;
    vector<uv> a(P+1);
    for (int i=1;i<=P;++i) {
        cin >> a[i].u >> a[i].v >> a[i].z;
        N = max(N,max(a[i].u,a[i].v));
    }
    dsu sett(N);
    for (uv &a:a) {
        if (a.z==2) {
            if (sett.find(a.u)==sett.find(a.v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            sett.join(a.u,a.v);
        }
    }
    return 0;
}