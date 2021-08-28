/// không khả dụng khi cần phải tương tác từ lá lên các nút cha 
#include <bits/stdc++.h>
using namespace std;

const int MAX_LABEL = 1e6;

class IT {
private:
    class _uv {
    public:
        int _max;
        int _min;
    };
    int max_label;
    vector<_uv> T;
public: 
    IT (int size) {
        max_label = size;
        T.resize(2*max_label+1, {0,0});
    }
    /// size của 4 thằng dưới khác size ở trên
    void update(vector<int> &a,int size) {
        for (int i=size-1;i<2*size;++i) {
            T[i]._max=a[size-i-1];
            T[i]._min=a[size-i-1];
        }
    }
    void build(int size) {
        for (int i=size-1;i>=0;--i) {
            T[i]._min = min(T[i<<1]._min, T[i<<1|1]._min);
            T[i]._max = max(T[i<<1]._max, T[i<<1|1]._max);
        }
    }
    void combine(int label,int val) {
        T[label]._max=val;
        T[label]._min=val;
    }
    void modify(int label,int val,int size) {
        for (combine(label+=size,val); label > 1; label >>=1 ) {
            T[label << 1]._min = min(T[label]._min, T[label^1]._min);
            T[label << 1]._max = max(T[label]._max, T[label^1]._max);
        }
    }
    int QMAX(int size, int l, int r) {
        int res = -1e7;
        for (l += size , r += size; l < r; l >>= 1, r >>= 1 ) {
            if (l & 1) res = max(res, T[++l]._max);
            if (r & 1) res = max(T[--r]._max, res);
        }
        return res;
    }
    int QMIN(int size, int l, int r) {
        int res=1e7;
        for (l += size , r += size; l < r; l >>= 1, r >>= 1 ) {
            if (l & 1) res = min(T[++l]._min, res);
            if (r & 1) res = min(T[--r]._min, res);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    IT tree(MAX_LABEL);
    int N,Q;
    cin >> N >> Q;
    vector<int> a(N,0);
    for (int i=0;i<N;++i) {
        cin >> a[i];
    }
    tree.update(a,N);
    tree.build(N);
    for (int i=0;i<N;++i) {
        tree.modify(0,a[i],N);
    }
    int u,v;
    for (int i=1;i<=Q;++i) {
        cin >> u >> v;
        cout << tree.QMAX(N,u,v) << ' '  << tree.QMIN(N,u,v) << '\n';
    } 
    return 0;
}