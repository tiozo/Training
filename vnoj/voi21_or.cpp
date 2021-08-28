#include<bits/stdc++.h>
using namespace std;

const int maxval = 1e6;
const int modulo = 1e9 + 7;

int main() {
    int N,k,L,R;
    cin >> N >> k >> L >> R;
    vector<int> a(N+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    vector<vector<vector<int>>> f(N+1,vector<vector<int>> (k+1,vector<int> (N+1,0)));
    int res = 0;
    for (int i=1;i<=N;++i) {
        for (int K=1;K<=k;++K) {
            f[i][K-1][i+1] = a[i]; 
            f[i][K][i+1] = a[i];
            for (int j=i+1;j<=N;++j) {
                f[i][K][j] |= f[i][K-1][j];
                if (f[i][K][j]%3==0 && L<=f[i][K][j] && f[i][K][j]<=R) {
                    res%=modulo;
                    ++res;
                }
            }
        }
    }
    cout << res%modulo;
    return 0;
}