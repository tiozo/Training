#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    vector<int> ans(1,0);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
            if (i==j) cout << (int)sqrt(a[i][j]) << ' ';
        }
    }
    return 0;
}
