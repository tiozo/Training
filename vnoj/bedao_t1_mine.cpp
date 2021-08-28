#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M; cin >> N >> M;
    vector<vector<int>> a(N+2,vector<int>(M+2,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
        }
    }
    //cout << '\n';
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cout << (a[i][j]^1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}