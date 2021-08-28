#include<bits/stdc++.h>
using namespace std;

class IT {
private:
    vector<int> C;
    vector<int> T;
public:
    IT (int size) {
        T.resize(size*4,0);
        C.resize(size*4,0);
    }
    void update(int id,int l,int r,int u,int v) {
        if (C[id]) {
            C[id] = 0;
            T[id] = r-l+1-T[id];
            if (l<r) {
                /// (flip 0 -> 1 / 1 -> 0)
                C[id*2] ^= 1;
                C[id*2+1] ^= 1;
            }
        }
        if (l>r || r<u || l>v) return;
        if (u<=l && r<=v) {
            T[id] = r-l+1-T[id];
            if (l<r) {
                /// (flip 0 -> 1 / 1 -> 0)
                C[id*2] ^= 1;
                C[id*2+1] ^= 1;
            }
            return;
        }
        int m = (l+r)/2;
        update(id*2,l,m,u,v);
        update(id*2+1,m+1,r,u,v);
        T[id]=T[id*2] + T[id*2+1];
    }
    int query(int id,int l,int r,int u,int v) {
        if (l>r || r<u || l>v) { 
            return (0);
        }
        if (C[id]) {
            C[id] = 0;
            T[id] = r-l+1-T[id];
            if (l<r) {
                /// (flip 0 -> 1 / 1 -> 0)
                C[id*2] ^= 1;
                C[id*2+1] ^= 1;
            }
        }
        if (l>=u && r<=v) {
            return T[id];
        }
        int m=(l+r)/2;
        return ( 
            query(id*2,l,m,u,v) +
            query(id*2+1,m+1,r,u,v)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    IT tree(N);
    for (int i=1;i<=M;++i) {
        int q,s,e;
        cin >> q >> s >> e;
        if (q) {
            cout << tree.query(1,1,N,s,e) << '\n';
        } else {
            tree.update(1,1,N,s,e);
        }
    }
    return 0;
}

