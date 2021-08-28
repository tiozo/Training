#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int N = s1.size(),M=s2.size();
    vector<vector<int>> f(N+1,vector<int>(M+1));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            if (s1[i-1]==s2[j-1]) {
                f[i][j] = f[i-1][j-1] + 1;
            } else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    cout << f[N][M];
    return 0;
}