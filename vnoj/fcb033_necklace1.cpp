#include<bits/stdc++.h>
using namespace std;

int N,K; vector<int> a;
const long long oo = 9e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    a.resize(N);
    for (int &a:a) cin >> a;
    vector<vector<long long>> f1(N,vector<long long>(K+1,oo));
    auto f0 = f1;
    f1[0][1] = a[0];
    f0[0][0] = 0;
    for (int i=1;i<N;++i) {
        for (int j=0;j<=K;++j) {
            f0[i][j] = f0[i-1][j];
            f1[i][j] = f1[i-1][j];
            if (i>=2 && j>=1) {
                f0[i][j] = min(f0[i][j],f0[i-2][j-1]+a[i]);
            }
            if (i>=2 && i!=N-1 && j>=1) {
                f1[i][j] = min(f1[i][j], f1[i-2][j-1] + a[i]);
            }
        }
    }
    auto f = f0;
    if (f1[N-1][K] < f[N-1][K]) {
        f = f1;
    }
    cout << f[N-1][K] << '\n';
    int ii = N-1, jj = K;
    while (true) {
        if (f[ii][jj]==f[ii-1][jj]) --ii;
        else {
            cout << ii << ' ';
            ii-=2;
            jj--;
        } 
        if (!jj) {
            cout << '\n';
            break;
        }
        if (ii==0) {
            cout << "0\n"; break;
        }
    }
    return 0;
}