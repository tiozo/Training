#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N+3,vector<int> (N+3,0));
    vector<vector<int>> F(N+3,vector<int> (N+3,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
            F[i][j] = 1e9;
        }
    }
    F[1][1] = 0;
    for (int i=1;i<=N-1;++i) {
        for (int j=i;j<=N;++j) {
            F[i][j+1] = min(F[i][j+1],F[i][j] + a[j][j+1]);
            if (i<j) F[i+1][j] = min(F[i+1][j],F[i][j]+a[i][i+1]);
            F[j][j+1] = min(F[j][j+1],F[i][j] + a[i][j+1]);
        }
    }
    int res = 1e9;
    for (int i=1;i<=N;++i) res = min(res,F[i][N]+a[i][1]+a[N][1]);
    cout << res;
    return 0;
}