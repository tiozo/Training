#include<bits/stdc++.h>
using namespace std;

class graph {
private:
    typedef vector<int> vi;
    typedef vector<vi> vii;
    vector<int> check;
    queue<int> q;
    bool result=false;
public: 
    graph (int size) {
        check.resize(size+1,0);
    }
    void clear(queue<int> &q) {
        queue<int> empty;
        swap(q,empty);
    }
    void BFS(vii &g,int u) {
        clear(q);
        q.push(u);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v=1;v<=g[u].size();++v) {
                if (g[u][v] == 1 && v!=u) {
                    if (!check[v]) {
                        check[v] = u;
                        q.push(v);
                    } else if (check[u] > 0 && g[v][check[u]] && !result) {
                        result = 1;
                        cout << u << ' ' << v << ' ' << check[u];
                        return;
                    }
                }
            }
        }
    }
    void DFS(vii &g,int u) {
        for (int v=1;v<=g[u].size();++v) {
            if (g[u][v] == 1 && v!=u) {
                if (!check[v]) {
                    check[v] = u;
                    DFS(g,v);
                } else if (check[u] > 0 && g[v][check[u]] && !result) {
                    result = 1;
                    cout << u << ' ' << v << ' ' << check[u];
                    return;
                }
            }
        }
    }
    void solve(vii &g,int N) {
        for (int u=1;u<=N;++u) {
            if (!check[u]) {
                check[u] = -1;
                BFS(g,u);
                if (result) {
                    return;
                }
            }
        }
        cout << "-1 -1 -1";
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    graph g(N);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    g.solve(a,N);
    return 0;
}
/*
    cần tìm A < B < C < A
    nghĩa là 
    g[A][B] = 1 và g[B][A] = 0; 
    g[B][C] = 1 và g[C][B] = 0;
    g[C][A] = 1 và g[A][C] = 0;
    return A,B,C;
*/