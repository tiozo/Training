#include<bits/stdc++.h>
using namespace std;

int main() {
    string a,b; cin >> a >> b;
    int N = a.size();
    int M = b.size();
    vector<vector<int>> c(M+2,vector<int> (27,0));
    for (int i=0;i<=M+1;++i) {
        for (int j=0;j<=26;++j) {
            c[i][j] = M;
        }
    }
    for (int i=M-1;i>=0;--i) {
        for (int j='a';j<='z';++j) {
            if (b[i]==j) {
                c[i][j-'a']=i;
            } else c[i][j-'a']=c[i+1][j-'a'];
        }
    }
    vector<vector<int>> f(N+2,vector<int> (M+2,1e5));
    for (int i=0;i<N;++i) {
        f[i][M+1]=0;
        f[i][M] = 1;
    }
    for (int i=N-1;i>=0;--i) {
        for (int j=M-1;j>=0;--j) {
            f[i][j] = min(f[i+1][j],f[i+1][c[j][a[i]-'a']+1]+1);
        }
    }
    cout << f[0][0] << '\n';
    return 0;
}