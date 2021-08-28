#include<bits/stdc++.h>
using namespace std;

class graph {
private: 
    typedef vector<vector<int>> vii;
    vector<vector<int>> check;
    vii backup;
    queue<pair<int,int>> q; 
    vector<pair<int,int>> movements{{0,1},{1,0},
                     {0,-1},{-1,0}};
    int min_val = 1e9;
    int mn = 0;
    int mx = 0;
public: 
    graph(int size) {
        check.resize(size+1);
        for (int i=0;i<=size;++i) {
            check[i].resize(size+1,0);
        }
        backup = check;
    }
    void reset() {
        check = backup;
    }
    void clear(queue<pair<int,int>> &q) {
        queue<pair<int,int>> empty;
        swap(q,empty);
    }
    bool DFS(vii &g,int u,int v,int N) {
        check[u][v] = 1; if( u == N && v == N ) return 1;
        for(auto move: movements) {
            int x = u + move.first, y = v + move.second;
            if( x > 0 && y > 0 && x <= N && y <= N && !check[x][y] && g[x][y] >= mn && g[x][y] <= mx )
                if(DFS(g,x,y,N)) return 1;
        }
        return 0;
    }
    bool BFS(vii &g,int u,int v,int N) {
        int x,y;
        clear(q);
        check[u][v] = 1;
        q.push({u,v});
        pair<int,int> u1;
        while (!q.empty()) {
            u1 = q.front();
            q.pop();
            for (auto move: movements) {
                x = u1.first + move.first; y = u1.second + move.second;
                if (x < 1 || y < 1 || x > N || y > N) {
                    continue;
                }
                if (!check[x][y] && g[x][y]>=mn && g[x][y]<=mx) {
                    q.push({x,y}); check[x][y] = 1;
                    if (x==N && y==N) return true;
                }
            }
        }
        return false;
    }
    void solve(vii &g,int N) {
        for(mn = 0; mn <= g[1][1]; ++mn) {
            int L = 0, H = 120;
            while( L <= H ) {
                int mid = (L+H)>>1;
                mx = mn+mid;
                reset();
                bool ok = DFS(g,1,1,N); // hoặc BFS cũng đc cách nào cx như nhau
                if( L == H ) {
                    if( !ok ) L = 1e9;
                    break;
                }
                if(ok) H = mid;
                else L = mid + 1;
            }
            min_val = min(min_val,L);
        }
        cout << min_val;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    graph g(N);
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    g.solve(a,N);
    return 0;
}