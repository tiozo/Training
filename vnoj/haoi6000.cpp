#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int x,y,z;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    queue<uv> q;
    pair<int,int> moveset[4]={{-1,0},{0,1},{1,0},{0,-1}};
    int F[N+1][M+1][4] = {0};
    int moves[5][2] = {2, 1, 2, 3, 0, 3, 0, 1};
    int a[N+1][M+1];
    ///giving task for BFS;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];     
            if (i==1) {
                if (a[i][j] == 0) {
                    F[1][j][0] = 1;
                    q.push({1,j,0});
                } else {
                    F[1][j][3] = 1;
                    q.push({1,j,3});
                }
            }
        }
    }
    ///BFS though out the map to seek all the possible way to reach the end.
    while (!q.empty()) {
        int u = q.front().x,v=q.front().y,id=q.front().z;
        q.pop();
        for (int t=id;t<=id+1;++t) {
            int x = u + moveset[t%4].first, y = v + moveset[t%4].second;
            if (x>0 && y>0 && x<=N && y<=M) {
                int z=moves[t%4][a[x][y]];
                if (!F[x][y][z]) {
                    F[x][y][z] = F[u][v][id] + 1;
                    q.push({x,y,z});
                }
            }
        }
    }
    /// find all the small exit value;
    int res = 1e9,num = 0;
    for (int j=1;j<=M;++j) {
        for (int t=1;t<=2;++t) {
            if (F[N][j][t] && F[N][j][t] < res) {
                res = F[N][j][t];
                num = 1;
            } else if (F[N][j][t] == res) num ++;
        }
    }
    if (res == 1e9) {
        res = 0;
    }
    cout << res << ' ' << num;
    return 0;
}