#include<bits/stdc++.h>
using namespace std;

struct _uv {
    int st,en,k,id;
};
struct _uv2 {
    int gt,id;
};

bool cmp (const _uv2 &a,const _uv2 &b) { return a.gt>b.gt;}
bool cmp1(const _uv &a, const _uv &b){ return a.k > b.k;}

class BIT {
private:
    vector<vector<int> > T;
public:
    BIT(int size) {
        T.resize(size+1);
        for (int i=0;i<=size;++i) {
            T[i].resize(size+1,0);
        }
    }
    void update(int size,int value,int index) {
        for (int i=value;i<=size;i+=i&-i) {
            for (int j=index;j<=size;j+=j&-j) {
                ++T[i][j];
            }
        }
    }
    int get(int value,int index) {
        int res = 0;
        for (int i=value; i; i-=i&-i) {
            for (int j=index;j;j-=j&-j) {
                res += T[i][j];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,query;
    cin >> N;
    vector<_uv2 > a(N+1,{0,0});
    BIT tree(30000);
    for (int i=1;i<=N;++i) {
        cin >> a[i].gt;
        a[i].id=i;
    }
    cin >> query;
    vector<int> KQ(query+1,0);
    vector<_uv> Q(query+1,{0,0,0,0});
    for (int i=1;i<=query;++i) {
        cin >> Q[i].st >> Q[i].en >> Q[i].k;
        Q[i].id = i;
        KQ[i] = Q[i].en - Q[i].st + 1;
    }
    sort(Q.begin()+1,Q.end(),cmp1);
    int stt = 1;
    for (int i = 1;i<=query && stt<=N;) {
        if (stt<=N && Q[i].k<a[stt].gt) {
            tree.update(N,a[i].gt,a[stt].id);
            ++stt;
        } else {
            KQ[Q[i].id] = tree.get(Q[i].en,a[i].id) - tree.get(Q[i].st-1,a[i].id);
            ++i;
        }
    }
    for (int i=1;i<=query;++i) {
        cout << KQ[i] << '\n';
    }
    return 0;
}