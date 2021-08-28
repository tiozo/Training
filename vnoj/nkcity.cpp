#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int x,y,z;
};
bool operator < (const uv &a,const uv &b) {
    return a.z<b.z;
}

class dsu {
private:
    vector<int> par,rank;
public: 
    dsu (int size): par(size+1),rank(size+1,0) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
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
    vector<uv> a(M+1);
    for (int i=1;i<=M;++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a.begin(),a.end());
    int result = 0;
    dsu sett(N);
    for (auto &a:a) {
        if (sett.join(a.x,a.y)) result = a.z;
    }
    cout << result;
    return 0;
}