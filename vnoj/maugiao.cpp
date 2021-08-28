#include<bits/stdc++.h>
using namespace std;

int N,sumMax=0,way = 0;
vector<int> f;
vector<long long> c;
vector<vector<int>> a;

int inRange(const int &x) {
    int r = x &- x, h = x+r;
    return h | (x^h) / r >> 2;
}

void DPBitMask() {
    const int Omega = 1 << N;
    c.resize(Omega+1,1);
    f[0] = 0;
    for (int i=1;i<=N;++i) {
        for (int j=(1<<(i))-1;j<Omega;j=inRange(j)) {
            f[j] = INT_MIN;
            for (int p = 1;p<=N;++p) if (j&1<<(p-1)) {
                const int pj = j&~(j&1<<(p-1));
                if (f[pj]+a[i][p]>f[j]) {
                    f[j] = f[pj] + a[i][p];
                    c[j] = c[pj];
                } else if (f[pj]+a[i][p] == f[j]) {
                    c[j] += c[pj];
                }
            }
        }
    }
    cout << f[Omega-1] << ' ' << c[Omega-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    a = vector<vector<int>>(N+1,vector<int>(N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    f.resize((1<<(N+1)));
    DPBitMask();
    return 0;
}