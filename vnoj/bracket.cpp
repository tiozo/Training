#include<bits/stdc++.h>
using namespace std;

const int maxn = 66;
long long f[maxn][maxn][maxn], g[maxn][maxn][2][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N,d; cin >> N >> d;
    string s; cin >> s;
    g[N][0][0][0]=1;
    for (int i=N;i;--i) 
        for (int j=0;j<=d;++j) {
            for (int k=0;k<=d;++k) {
                if (g[i][j][0][k]||g[i][j][1][k]) {
                    f[i][j][k] = g[i][j][0][k] + g[i][j][1][k];
                    g[i-1][j+1][1][max(k,j+1)] += f[i][j][k];
                    if (j) g[i-1][j-1][0][k] += f[i][j][k];
                }
            }
        }
    cout << g[0][0][0][d] << '\n';
    int deg = 0; long long res = 1; bool passed = false;
    for (int i=0;i<N;++i) {
        if (s[i]==')') {
            if (passed) res+= accumulate(g[i][deg][0],g[i][deg][0]+d+1,0);
            else res+=g[i][deg][0][d];
        }
        if (s[i]=='(') deg++; else deg--;
        if (deg==d) passed = true;
    }
    cout << res << '\n';
    return 0;
}