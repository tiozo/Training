#include<bits/stdc++.h>
using namespace std;

class graph {
private:
    const int INF = 1e9;
    queue<pair<pair<int,int>,int>> q;
    vector<vector<vector<int>>> d;
    vector<int> vs;
public:
    graph (int size) {
        vector<vector<vector<int>>> empty(size+1,vector<vector<int>> (size+1,vector<int> (2,1e9+5)));
        swap(empty,d);
    }
    void BFS(vector<vector<int>> &g) {
        while (!q.empty()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int who = q.front().second;
            q.pop();
            if (!who) {
                for (int w:g[u]) {
                    if (d[w][v][1-who]>=INF) {
                        d[w][v][1-who] = d[u][v][who] + 1;
                        
                        q.push({{w,v},1-who});
                    }
                }
            } else {
                for (int w:g[v]) {
                    if (d[u][w][1-who]>=INF) {
                        d[u][w][1-who] = d[u][v][who] + 1;
                        q.push({{u,w},1-who});
                    }
                }
            }
        }
    }
    void solve(vector<vector<int>> &g,int N,int M,int S,int T) {
        q.push({{S,T},0});
        d[S][T][0]=0;
        BFS(g);
        int res = INF;
        for (int i=1;i<=N;++i) {
            res = min(res,d[i][i][0]);
        }
        if (res == INF) {
            cout << -1;
            return;
        }
        cout << res/2;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M,S,T;
    cin >> N >> M >> S >> T;
    graph g(N);
    vector<vector<int>> a(N+1);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
    }
    g.solve(a,N,M,S,T);
    return 0;
}