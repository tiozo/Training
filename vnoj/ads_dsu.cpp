#include<bits/stdc++.h>
using namespace std;

class dsu {
private:
    vector<int> cha,rank,n,m;
public:
    dsu (int size): cha(size+1),n(size+1),m(size+1) {
        for (int i=1;i<=size;++i) {
            cha[i] = i;
            m[i] = 0;
            n[i] = 1;
        }
    }
    int val(int u,string need_val){
        if (need_val == "cha") 
            return cha[u];
        else if (need_val == "m") 
            return m[u];
        return n[u];
    }
    int find(int u) {
        if (cha[u] != u) cha[u] = find(cha[u]);
        return cha[u];
    }
    void join(int u,int v) {
        u = find(u); v = find(v);
        if (u==v) {
            m[u]++;
            return;
        }
        if (rand()&1) swap(u,v); // random 1 số xem nó có phải số lẻ không 
        cha[v] = u;
        n[u] += n[v];
        m[u] += m[v] + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    dsu d(N);
    for (int i = 1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        d.join(u,v);
    }
    int res = 0;
    for (int i=1;i<=N;++i) {
        if (d.val(i,"cha") == i) {
            res += d.val(i,"m") - d.val(i,"n") + 1; 
        }
    }
    cout << res;
    return 0;
}