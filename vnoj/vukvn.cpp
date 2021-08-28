#include<bits/stdc++.h>
using namespace std;

class graph {
private: 
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    vector<vector<int>> check;
    vector<pair<int,int>> moveset{{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>> q;
    int res = 0;
public: 
    void clear() {
        queue<pair<int,int>> empty;
        swap(empty,q);
    }
    void BFS(int N,int M) {
        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (auto move:moveset) {
                int x = u + move.first;
                int y = v + move.second;
                if (0<x && 0<y && x<=N && y<=M && check[x][y] > check[u][v] + 1) {
                    check[x][y] = check[u][v] + 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
    void BS(int N,int M,pair<int,int> S, pair<int,int> E) {
        vvi tmp;
        int L = 1, R = check[S.first][S.second];
        while (L<=R) {
            int Mid = (L+R) >> 1;
            vvi vs(N+1,vi (M+1,0));
            clear();
            if (check[S.first][S.second] >= Mid) {
                vs[S.first][S.second] = true;
                q.push(S);
            }
            while (!q.empty()) {
                int u = q.front().first;
                int v = q.front().second;
                q.pop();
                for (auto move:moveset) {
                    int x = u + move.first;
                    int y = v + move.second;
                    if (0<x && 0<y && x<=N && y<=M && !vs[x][y] && check[x][y] >= Mid) {
                        vs[x][y] = true;
                        q.push(make_pair(x,y));
                    }
                }
            }
            if (vs[E.first][E.second]){
                L = Mid+1;
                res = Mid;
            }
            else R = Mid - 1;
        }
        cout << res << '\n';
    }
    void make(vvi &a,queue<pair<int,int>> _q) {
        swap(check,a);
        swap(q,_q);
    }
    void solve(int N,int M,pair<int,int> S, pair<int,int> E) {
        BFS(N,M);
        BS(N,M,S,E);
    }
};

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> a(N+1,vector<int> (M+1,90));
    queue<pair<int,int>> q;
    pair<int,int> S,E;
    graph g;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            char c;
            cin >> c;
            if (c == '+') {
                q.push(make_pair(i,j));
                a[i][j] = 0;
            } else if (c == 'V') {
                S = make_pair(i,j);
            } else if (c == 'J') {
                E = make_pair(i,j);
            }
        }
    }
    g.make(a,q);
    g.solve(N,M,S,E);
    return 0;
}