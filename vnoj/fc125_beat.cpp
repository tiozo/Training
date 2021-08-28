#include<bits/stdc++.h>
using namespace std;

struct state {
    int  x,y,z;
    state() {}
    state(int x,int y,int z): x(x), y(y), z(z) {}
};

struct dp {
    double val;
    state track;
    dp() {}
    dp(double val, state track): val(val), track(track) {}
};

const int maxn = 105;
int N;
vector<int> ans;
vector<int> a,b,c;
vector<double> ln;
dp f[maxn][maxn][maxn];

void optimal(dp&a,dp b) {
    if (a.val<b.val) a = b;
}

void trace(int i,int j,int k) {
    int x = f[i][j][k].track.x;
    int y = f[i][j][k].track.y;
    int z = f[i][j][k].track.z;
    if (x&&y&&z) trace(x,y,z);
    if (a[i]==b[j] && b[j] == c[k]) ans.push_back(a[i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    a.resize(N+1);
    b.resize(N+1); c.resize(N+1);
    ln.resize(N+1);
    for (int i=1;i<=N;++i) cin >> a[i];
    for (int i=1;i<=N;++i) cin >> b[i];
    for (int i=1;i<=N;++i) cin >> c[i];
    for (int i=1;i<=N;++i) ln[i] = log(a[i]);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            for (int k=1;k<=N;++k) {
                optimal(f[i][j][k],dp(f[i-1][j][k].val,state(i-1,j,k)));
                optimal(f[i][j][k],dp(f[i][j-1][k].val,state(i,j-1,k)));
                optimal(f[i][j][k],dp(f[i][j][k-1].val,state(i,j,k-1)));
                if (a[i]==b[j]&&c[k]==b[j]) 
                    f[i][j][k] = dp(f[i-1][j-1][k-1].val+ln[i],state(i-1,j-1,k-1));
            }
        }
    }
    trace(N,N,N);
    cout << ans.size() << '\n';
    if (ans.size()) {
        for (int &a:ans) cout << a << ' ';
    }
    return 0;
}