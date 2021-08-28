#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,K,z=0,ans=2000;
    cin >> N >> K;
    vector<vector<char>> a(N+1,vector<char> (N+1));
    vector<vector<vector<vi>>> f(2,vector<vector<vi>> (2,vector<vi> (N+5,vi (N*2+5)))); 
    while (K--) {int x,y; cin >> x >> y; a[x][y]=1;}
    for (int i=1;i<=N && !a[1][i];++i) f[0][0][i][i-1]=1;
    for (int i=N;i && !a[1][i];--i) f[1][0][i][N-i]=1;
    for (int i=2;i<=N && i-1<ans;++i) {
        z^=1;
        for (int j=1;j<=N;j++)
            for (int k=0;k<=i*2;k++)
                f[0][z][j][k]=f[1][z][j][k]=0;

        for (int j=1;j<=N;j++)
            if (!a[i][j])
                for (int k=i-1;k<ans && k<=i+j-2;k++)
                    f[0][z][j][k]=f[0][1-z][j-1][k-1] | f[0][1-z][j][k-1] | f[0][z][j-1][k-1];

        for (int j=N;j;j--)
            if (!a[i][j])
                for (int k=i-1;k<ans && k<=i-1+N-j;k++)
                {
                    f[1][z][j][k]=f[1][1-z][j+1][k-1] | f[1][1-z][j][k-1] | f[1][z][j+1][k-1];
                    if (f[1][z][j][k] && f[0][z][j][k]) ans=k;
                }
    }
    cout << ans << '\n';
    return 0;
}