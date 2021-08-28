#include<bits/stdc++.h>
using namespace std;

class uv {
public: 
    int u,v,w;
};

bool cmp(uv&a,uv&b) {
    return a.w < b.w;
}

class dsu {
private: vector<int> par,rank;
public:
    dsu (int size):par(size+1), rank(size+1,0) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }
    bool join(int u,int v){
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
    /// tương tự DSU + krukal thông thường có modify lại là xuất phát ở nơi có giá trị thấp nhất.
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<uv> a(M+1);
    vector<int> C(N+1);
    for (int i=1;i<=N;++i) {
        cin >> C[i];
    }
    for (int i=1;i<=M;++i) {
        int w;
        cin >> a[i].u >> a[i].v >> w;
        a[i].w = 2*w + C[a[i].u] + C[a[i].v];
    }
    sort(a.begin()+1,a.end(),cmp);
    dsu sett(N);
    int res = *min_element(C.begin()+1,C.end()),cnt = 0;
    for (uv &a:a) {
        if (sett.join(a.u,a.v)) {
            res+=a.w;
            ++cnt;
        }
        if (N-1 == cnt) break;
    }
    cout << res;
    return 0;
}