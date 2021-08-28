#include<bits/stdc++.h>
using namespace std;

const int maxn = 301;
int d[maxn][maxn][maxn];

int nRow,nCol,k;
string board[maxn];
string need;
const int moves[5] = {0, 1, 0, -1, 0};
bool valid(int u,int v) {
    return (u>=1 && u<=nRow && v>=1 && v<=nCol);
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin >> nRow >> nCol >> k;
    cin >> need; need = ' ' + need + ' ';
    for (int i=1;i<=nRow;++i) {
        cin >> board[i];
        board[i] = ' ' + board[i] + ' ';
    }
    queue<tuple<int,int,int>> q;
    memset(d,-1,sizeof d);
    for (int i=1;i<=nRow;++i) for (int j=1;j<=nCol;++j) {
        q.push({0,i,j});
        d[0][i][j] = 0;
    }
    while (!q.empty()) {
        int matched = get<0>(q.front()), u = get<1>(q.front()), v = get<2>(q.front()); q.pop();
        if (matched==k) {
            cout << d[matched][u][v] << '\n';
            return 0;
        }
        for (int dir=0;dir<4;dir++) {
            int x = u + moves[dir];
            int y = v + moves[dir+1];
            if (!valid(x,y)) continue;
            int matched2 = matched;
            if (need[matched2+1]==board[x][y]) ++matched2;
            if (d[matched2][x][y]<0) {
                d[matched2][x][y] = d[matched][u][v] + 1;
                q.push({matched2,x,y});
            }
        }
    }
    assert(false);
    return 0;
}