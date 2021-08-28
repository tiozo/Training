#include<bits/stdc++.h>
using namespace std;

const int MAX_LABEL = 50000;

class IT {
private:
    class _data {
    public:
        int val;
        int lazy;
    };
    int max_label;
    vector<_data> T;
public:
    IT (int size) {
        max_label = size;
        T.resize(4*size+1,{0,0});
    }
    void update(int id, int l, int r, int u,int v,int val) {
        if (l>r) {
            return;
        }
        T[id].val += T[id].lazy;
        if (l<r) {
            T[id*2].lazy += T[id].lazy;
            T[id*2+1].lazy += T[id].lazy;
        }
        T[id].lazy=0;
        if (v<l || r<u) {
            return;
        }
        if (l>=u && r<=v) {
            T[id].val += val;
            if (l<r) {
                T[id*2].lazy += val;
                T[id*2+1].lazy += val;
            }
            return;
        }
        int m=(l+r)/2;
        update(id*2,l,m,u,v,val);
        update(id*2+1,m+1,r,u,v,val);
        T[id].val = max(T[id*2].val,T[id*2+1].val);
    }
    int query(int id, int l, int r, int u, int v) {
        if (l>r) {
            return -1e6;
        }
        T[id].val += T[id].lazy;
        if (l<r) {
            T[id*2].lazy += T[id].lazy;
            T[id*2+1].lazy += T[id].lazy;
        }
        T[id].lazy=0;
        if (v<l || u>r) {
            return -1e6;
        }
        if (l>=u && r<=v) {
            return T[id].val;
        }
        int m=(l+r)/2;
        return max(
            query(id*2,l,m,u,v),
            query(id*2+1,m+1,r,u,v)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    IT tree(MAX_LABEL);
    int N,M,P;
    cin >> N >> M;
    for (int i=1;i<=M;++i) {
        int u,v,k;
        cin >> u >> v >> k;
        tree.update(1,1,N,u,v,k);
    }
    cin >> P;
    for (int i=1;i<=P;++i) {
        int u,v;
        cin >> u >> v;
        cout << tree.query(1,1,N,u,v) << '\n';
    }
    return 0;
}