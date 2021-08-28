#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> a(M);
    vector<vector<int>> f(N+1,vector<int>(N+1));
    for (int &a:a) {cin >> a; --a;}
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            cin >> f[i][j];
        }
        f[i][i] = 1e9;
    }
    for (int k=0;k<N;++k) for (int i=0;i<N;++i) for (int j=0;j<N;++j) {
        f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    }
    //cout << "segment fault";
    long long res = 0;
    for (int i=0;i<M-1;++i) res += f[a[i]][a[i+1]];
    cout << res;
    return 0;
}