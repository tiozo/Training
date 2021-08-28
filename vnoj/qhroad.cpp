#include<bits/stdc++.h>
using namespace std;

int nset,N;
class uv {
public:
    int u,v;
};

class dsu {
private: 
    vector<int> par;
public:
    dsu(int size):par(size+1) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    void join(int u,int v) {
        u=find(u);
        v=find(v);
        if (u==v) return;
        if (rand()&1) par[v] = u;
        else par[u] = v;
        --nset;
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(1e7);
    int M,Q;
    cin >> N >> M >> Q;
    vector<uv> a(M+1,{0,0});
    vector<int> blocked(M+1,0);
    vector<int> d(Q+1);
    vector<int> res(Q+1,0);
    for (int i=1;i<=M;++i) {
        cin >> a[i].u >> a[i].v;
    }
    dsu st(N);
    nset = N;
    for (int i=1;i<=Q;++i) {
        cin >> d[i];
        blocked[d[i]] = 1;
    }
    for (int i=1;i<=M;++i) {
        if (!blocked[i]) {
            st.join(a[i].u,a[i].v); 
        }
    }
    for (int i=Q;i>=1;--i) {
        res[i] = nset, st.join(a[d[i]].u,a[d[i]].v);
    }
    for (int i=1;i<=Q;++i) {
        cout << res[i] << '\n';
    }
    return 0;
}