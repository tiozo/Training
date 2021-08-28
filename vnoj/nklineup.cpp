#include <bits/stdc++.h>
using namespace std;

const int MAX_LABEL = 1e6;

class IT {
private:
    class _uv {
    public:
        int _max;
        int _min;
        int _distance;
    };
    int max_label;
    vector<_uv> T;
public: 
    IT (int size) {
        max_label = size;
        T.resize(4*max_label+1, {0,0,0});
    }
    void update(int id, int l,int r,int i, int val) {
        if (i < l || i > r) return;
        if ( l == r ) {
            T[id]._min = val;
            T[id]._max = val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2  , l, mid, i, val);
        update(id*2+1, mid+1, r, i, val);
        T[id]._min = min(T[id*2]._min, T[id*2+1]._min);
        T[id]._max = max(T[id*2]._max, T[id*2+1]._max);
    }
    int getMAX(int id,int l,int r,int u,int v) {
        if (l > r || l > v || r < u) {
            return -1e9; 
        }
        if (u<=l && r<=v) {
            return T[id]._max;
        }
        int mid = (l+r)/2;
        
        return max(
            getMAX(id  *2,         l, mid, u, v),
            getMAX(id * 2 + 1, mid+1, r, u, v)
        );
    }
    int getMIN(int id,int l,int r,int u,int v) {
        if (l > r || l > v || r < u) {
            return 1e7; 
        }
        if (u<=l && r<=v) {
            return T[id]._min;
        }
        int mid = (l+r)/2;
        
        return min(
            getMIN(id  *2,         l, mid, u, v),
            getMIN(id * 2 + 1, mid+1, r, u, v)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    IT tree(MAX_LABEL);
    int N,Q;
    cin >> N >> Q;
    vector<int> a(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=N;++i) {
        tree.update(1,1,N,i,a[i]);
    }
    int u,v;
    for (int i=1;i<=Q;++i) {
        cin >> u >> v;
        cout << tree.getMAX(1,1,N,u,v)-tree.getMIN(1,1,N,u,v) << '\n';
    } 
    return 0;
}