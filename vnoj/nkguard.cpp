#include<bits/stdc++.h>
using namespace std;
#define nd second
#define st first
typedef vector<vector<int>> vii;
class graph {
private:
    queue<pair<int,int>> s;
    vector<vector<int>> check;
    vector<pair<int,int>> ke{{-1,-1},{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1}};
    int res = 0;
    int high = 0;
public:
    graph (int size) {
        check.resize(size+1);
        for (int i=0;i<=size;++i) {
            check[i].resize(size+1,0);
        }
    }
    void clear( queue<pair<int,int>> &q )
    {
        queue<pair<int,int>> empty;
        swap( q, empty );
    }
    void BFS(vii &g,int xx,int yy,int N,int M) {
        int x,y;
        clear(s);
        pair<int,int> u;
        s.push({xx,yy});
        check[xx][yy] = 1;
        while (!s.empty()) {
            u = s.front();
            s.pop();
            for (pair<int,int> k: ke) {
                x = u.first + k.first;
                y = u.second + k.second;
                if (x < 0 || y < 0 || x > N || y > M) {
                    continue;
                }
                if (!check[x][y] && g[x][y] == g[xx][yy]) {
                    s.push({x,y}); check[x][y] = true;
                } else if (g[xx][yy] < g[x][y]) high = 0;
            }
        }
    }
    void DFS(vii &g,int xx,int yy,int N,int M) {
        check[xx][yy] = 1;
        for (auto k: ke) {
            int x = xx + k.first, y = yy + k.second;
            if (x < 0 || y < 0 || x > N || y > M) continue;
            if (!check[x][y] && g[x][y] == g[xx][yy]) {
                DFS(g,x,y,N,M);
            } else if (high && g[x][y] > g[xx][yy]) high = 0;
        }
    }
    void solve(vii &g,int N,int M) {
        for (int i = 1;i<=N;++i) {
            for (int j=1;j<=M;++j) {
                if (!check[i][j]) {
                    high = 1; 
                    DFS(g,i,j,N,M);
                    // BFS(g,i,j,N,M);
                    /*
                    dùng DFS vì đỉnh ta tìm có thể ở xa so với đỉnh hiện tại đang xét
                    tối ưu hơn về tốc độ khi có nhiều nhánh tìm bị ra ngoài.
                    THỰC CHẤT: queue làm cho BFS chậm hơn DFS 
                    và vì đề bài không có yêu cầu tìm lân cận
                    */
                    res += high;
                }
            }
        }
        cout << res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    graph g(max(N,M));
    vector<vector<int>> a(N+1,vector<int> (M+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
        }
    }
    g.solve(a,N,M);
    return 0;
}