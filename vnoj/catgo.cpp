#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,M; cin >> N;
    vector<int> wood(N+1,0);
    for (int i=1;i<=N;++i) cin >> wood[i];
    cin >> M; vector<int> value(55,0);
    for (int i=1;i<=M;++i) {
        int u,c; cin >> u >> c;
        value[u] = max(value[u],c);
    }
    vector<vector<int>> g(55,vector<int>(55,0));
    vector<vector<int>> f(55,vector<int>(101,0));
    for (int i=1;i<=50;++i) g[i][0] = -1e9;
    for (int i=1;i<=50;++i) 
        for (int j=1;j<=i;++j) 
            for (int ii=0;ii<i;++ii) 
                g[i][j] = max(g[i][j],g[ii][j-1]+value[i-ii]);
    for (int i=1;i<=N;++i) 
        for (int j=1;j<=wood[i];++j) 
            for (int k=j-1;k<=100;++k) 
                f[i][k] = max(f[i][k],f[i-1][k-j+1]+g[wood[i]][j]);
    int res = 0;
    for (int i=0;i<=100;++i) res = max(res,f[N][i]-i*(i+1)/2);
    cout << res;  
    return 0;
}

/*
2
3
4
2
1 10
2 11

4 2 1 1
3 1 2
  1  1  1 
10 10 10 10
  1  1
10 10 10

1 - 2 - 3 - 4 - 5 

*/