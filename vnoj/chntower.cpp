#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int M,N,K;
    ull f[65][65];
    for (int i=1;i<=64;++i) f[1][i] = 1;
    for (int i=2;i<=64;++i) f[i][3] = f[i-1][3]*2+1;
    for (int i=2;i<=64;++i)
        for (int j=4;j<=64;++j) 
            if (i<=j-1) f[i][j] = 2*i-1;
            else {
                f[i][j] = f[i][j-1];
                for (int k=1;k<=i-1;++k)  
                    f[i][j] = min(f[i][j],f[i-k][j-1]+f[k][j]*2);
            }
    while (cin >> N >> M) 
        cout << f[N][M] << '\n';
    return 0;
}