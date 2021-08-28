#include<bits/stdc++.h>
using namespace std;

int f[40][40][40];

int main() {
    int tc; cin >> tc;
    vector<vector<int>> d = {{0,-1},{0,1},{-1,1},{-1,0},{1,0},{1,-1}};
    f[20][20][0] = 1;
    while (tc--) {
        int n; cin >> n;
        for(int k=1;k<=n;++k)
            for(int x=1;x<=38;x++)
                for(int y=1;y<=38;y++) {
                    f[x][y][k] = 0;
                    for(int l=0;l<=5;l++)
                        f[x][y][k] += f[x+d[l][0]][y+d[l][1]][k-1];
                }
        cout << f[20][20][n] << '\n';
    }
    return 0;
}