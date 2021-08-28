#include<bits/stdc++.h>
using namespace std;

int N;
int tabling(int a) {
    if (a>N) return a-N;
    return a<1 ? a+N : a;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<vector<char>> a(N+1,vector<char>(N+1));
    vector<vector<char>> f(N+1,vector<char>(N+1));
    vector<int> defeated(N+1);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
            f[i][j] = 0;
        }
    }
    for (int i=1;i<=N;++i) {
        f[i][tabling(i+1)] = 1;
    }
    for (int opponents = 3; opponents<=N+1;++opponents) {
        for (int i=1;i<=N;++i) {
            int batcap = i + opponents - 1;
            int doithu = tabling(batcap);
            for (int k=i+1;k<batcap;++k) {
                if (f[i][tabling(k)]&f[tabling(k)][doithu]&(a[i][tabling(k)]|a[doithu][tabling(k)])) {
                    f[i][doithu] = 1; break;
                }
            }
        }
    }
    int res = 0;
    for (int i=1;i<=N;++i) {
        if (f[i][i]) {
            res++;
            defeated[res] = i;
        }
    }
    cout << res << '\n';
    for (int i=1;i<=res;++i) {
        cout << defeated[i] << '\n';
    }
    return 0;
}