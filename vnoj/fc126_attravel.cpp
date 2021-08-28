#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a,int b) {
    if ((a+=b)>=MOD) a-=MOD;
    return a;
}
class point {
public:
    int x,y;
    bool operator > (const point&a) const {
        return x!=a.x ? x > a.x : y > a.y;
    }
    bool operator < (const point&a) const {
        return x!=a.x ? x < a.x : y < a.y;
    }
};

class BIT {
private: 
    vector<int> fen;
    int N;
public:
    BIT() {}
    BIT(int N): N(N), fen(N+6.9) {}
    void fillfen() {
        fill(fen.begin(),fen.end(),0);
    }
    void update(int i,int v) {
        for (i++;i<=N;i+=i&-i) {
            fen[i] = add(fen[i],v);
        }
    }
    int get(int p) {
        int res = 0;
        for (p++;p;p-=p&-p){
            res = add(res,fen[p]);
        }
        return res;
    }
} fen;  

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<point> a(N+1,{0,0});
    vector<int> b(N+1);
    vector<int> vals;
    vector<vector<int>> f(N+1,vector<int> (N+1,0));
    for (int i=1;i<=N;++i) cin >> a[i].x;
    for (int i=1;i<=N;++i) cin >> a[i].y;
    sort(a.begin()+1,a.end(),greater<point>());
    //for (int i=1;i<=N;++i) cout << a[i].x << ' ';
    for (int i=1;i<=N;++i) vals.push_back(a[i].y);
    sort(vals.begin(),vals.end()); 
    vals.resize(unique(vals.begin(),vals.end())-vals.begin());
    for (int i=1;i<=N;++i) {
        b[i] = lower_bound(vals.begin(),vals.end(),a[i].y) - vals.begin() + 1;
    }
    fen = BIT(vals.size());
    for (int i=1;i<=N;++i) {
        fen.fillfen();
        if (i==1) fen.update(0,1);
        int res = 0;
        for (int j=1;j<=N;++j) {
            f[i][j] = fen.get(b[j]-1);
            fen.update(b[j],f[i-1][j]);
            res = add(res,f[i][j]);
        }
        cout << res << ' ';
    }
    return 0;
}