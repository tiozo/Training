#include<bits/stdc++.h>
using namespace std;

const int maxn = 350, maxm = 70;
vector<bool> pr(maxn+1,1);
vector<int> p;
vector<vector<long long>> f(maxn+1,vector<long long> (maxm+1,0));

void eratos() {
    pr[0]=pr[1]=0;
    for (int i=2;i*i<=maxn;++i) {
        if (pr[i]) {
            for (int j=i+i;j<=maxn;j+=i) {
                pr[j] = 0;
            }
        }
    }
    for (int i=0;i<=maxn;++i) if (pr[i]) p.push_back(i);
}

void solve() {
    for (int j=0;j<=maxm;++j) f[0][j] = 1;
    for (int i=1;i<=maxn;++i) {
        for (int j=1;j<=maxm;++j) {
            f[i][j] = max(f[i][j-1],f[i-1][j]);
            for (int d=p[j-1];i>=d;d*=p[j-1]) f[i][j] = max(f[i][j],f[i-d][j-1]*d);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    eratos();
    solve();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N<=maxn-3) cout << f[N][maxm] << '\n';
        else cout << "14757354782123793840\n";
    }
}