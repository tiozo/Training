#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int K; cin >> K;
    while (K--) {
        int N; cin >> N;
        //vector<vector<int>> a(N+1,vector<int>(N+1,0));
        vector<vector<int>> f(N+1,vector<int>(N+1,0));
        vector<vector<int>> cntR(N+1,vector<int>(N+1,0));
        vector<vector<int>> cntC(N+1,vector<int>(N+1,0));
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                int x;
                cin >> x;
                cntR[i][j] = cntR[i][j-1]+x;
                cntC[i][j] = cntC[i-1][j]+x;
            }
        }
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                if (cntR[i][j]%2==0 && f[i-1][j]==0) f[i][j]=1;
                else if (cntC[i][j]%2==0 && f[i][j-1]==0) f[i][j]=1;
                else f[i][j]=0;
            }
        }
        if (!f[N][N]) puts("NO");
        else puts("YES");
    }
    return 0;
}