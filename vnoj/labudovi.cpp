#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int u,v;
};

class graph {
private:
    int inf;
    queue<uv> q;
    //vector<vector<vector<int>>> d;
    vector<vector<int>> g;
    vector<vector<int>> g1;
    vector<pair<int,int>> moveset {{0,1},{0,-1},{1,0},{-1,0}};
    bool valid = false;
public:
   /* graph (int R,int C) {
        vector<vector<vector<int>>> empty(R+1,vector<int> (C+1,0));
        swap(d,empty);
    }*/
    void BFS(int R,int C) {
        while (!q.empty()) {
            int u = q.front().u;
            int v = q.front().v;
            q.pop();
            for (auto move:moveset) {
                int x = u + move.first;
                int y = v + move.second;
                if (x>0 && y>0 && x<=R && y<=C && g[x][y]==inf) {
                    g[x][y] = g[u][v] + 1;
                    q.push({x,y});
                    
                }
            }
        }
    }
    int solve(vector<vector<int>> &a,queue<uv> &_q,uv S,uv E,int _R,int C,int _inf) {
        swap(a,g);
        g[S.u][S.v] = 0;
        g[E.u][E.v] = 0;
        swap(_q,q);
        swap(_inf,inf);
        BFS(_R,C);
        vector<vector<int>> vs(_R+1,vector<int> (C+1,0));
        vector<vector<int>> g1(_R+1,vector<int> (C+1,0));
        queue<uv> q2;
        /// binary search
        g1[S.u][S.v] = 1;
        g1[E.u][E.v] = 2;
        q.push(S);
        vs[S.u][S.v] = 1;
        for(int step = 0; !q.empty(); ++step) {
            /// BFS từ con thiên nga ở trên xem thử coi đường đi thế nào và truyền nhiệm vụ xuống BFS của thiên nga 2;
            while(!q.empty()) {
                int u = q.front().u, v = q.front().v; q.pop();
                q2.push({u,v});
                for (auto move:moveset) {
                    int x = u + move.first;
                    int y = v + move.second;
                    if (x>0 && y>0 && x<=_R && y<=C && !vs[x][y] && g[x][y]<=step) {
                        vs[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
            /// làm nhiệm vụ của thiên nga 1 trên giao theo dõi xem phần băng nào đã tan.
            while(!q2.empty()) {
                int u = q2.front().u, v = q2.front().v; q2.pop();
                if(g1[u][v]==2) {
                    return step;
                }
                for (auto move:moveset) {
                    int x = u + move.first;
                    int y = v + move.second;
                    if (x>0 && y>0 && x<=_R && y<=C && !vs[x][y] && g[x][y]<=step+1) {
                        vs[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
	    }
        assert(false);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int R,C;
    cin >> R >> C;
    vector<vector<int>> a(R+1,vector<int> (C+1,-1));
    queue<uv> q;
    graph g;
    uv S,E={0,0};
    int cnt = 0;
    int inf = a[1][1];
    for (int i=1;i<=R;++i) {
        for (int j=1;j<=C;++j) {
            char tmp;
            cin >> tmp;
            if (tmp =='.') {
                a[i][j] = 0;
                q.push({i,j});
            } else if (tmp == 'L') {
                q.push({i,j});
                S = E;
                E = {i,j};
            }
        }
    }
    cout << g.solve(a,q,S,E,R,C,inf);
    return 0;
}