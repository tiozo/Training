///prim N*M
#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int u,v,c;
};

struct cmp {
    bool operator() (uv a,uv b) {
        return a.c > b.c;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    priority_queue<uv,vector<uv>,cmp> q;
    int a[N+1][M+1];
    int d[N+1][M+1];
    pair<int,int> moveset[4] = {{-1,0},{0,1},{1,0},{0,-1}};
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
    for (int i=1;i<=N;++i) {
        d[i][1] = a[i][1]; d[i][M] = a[i][M];
        q.push({i,1,a[i][1]});
        q.push({i,M,a[i][M]});
    }
    for (int i=2;i<M;++i) {
        d[1][i] = a[1][i]; d[N][i] = a[N][i];
        q.push({1,i,a[1][i]});
        q.push({N,i,a[N][i]});
    }
    while (!q.empty()) {
        uv u = q.top();
        q.pop();
        if (u.c != d[u.u][u.v]) continue;
        for (auto move:moveset) {
            int x = u.u + move.first;
            int y = u.v + move.second;
            if (x>0 && y>0 && x<=N && y<=M) {
                if (d[x][y] > max(d[u.u][u.v],a[x][y])) {
                    d[x][y] = max(d[u.u][u.v],a[x][y]);
                    q.push({x,y,d[x][y]});
                }
            }
        }
    }
    long long result = 0;
    for (int i=2;i<N;++i) 
        for (int j=2;j<M;++j) {
            result += d[i][j] - a[i][j];
        }
    cout << result;
    return 0;
}