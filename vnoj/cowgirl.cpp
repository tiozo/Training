#include<bits/stdc++.h>
using namespace std;

int M,N;
vector<vector<int>> f(31,vector<int> (91,0));

bool ok(int m1,int m2) {
    for (int i=1;i<N;++i) {
        int a = (m1 & (1<<i))!=0, b = ((m1 & (1<<(i-1))))!=0;
        int c = (m2 & (1<<i))!=0, d = ((m2 & (1<<(i-1))))!=0;
        if (a==b&&b==c&&c==d) return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N; if (M<N) swap(M,N);
        for (int i=(1<<N)-1;i>=0;--i) f[1][i] = 1;
        for (int i=2;i<=M;++i) {
            for (int j=(1<<N)-1;j>=0;--j) {
                f[i][j] = 0;
                for (int m2 = (1<<N)-1;m2>=0;--m2) {
                    if (ok(j,m2)) f[i][j] += f[i-1][m2];
                }
            }
        }
        unsigned long long res = 0;
        for (int i=(1<<N)-1;i>=0;--i) {
            res += f[M][i];
        }
        cout << res << '\n';
    }
    return 0;
}