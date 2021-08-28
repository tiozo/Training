#include<bits/stdc++.h>
using namespace std;

class graph {
private:
    queue<int> q;
    stack<int> s;
    vector<int> vs;
    vector<int> way;
    vector<int> possible;
    int res = 0;
public:
    void clear() {
        vector<int> emp;
        swap(emp,vs);
        stack<int> empty;
        swap(empty,s);
    }
    void DFS(vector<vector<int>> &g,int u,int target) {
        clear();
        s.push(u);
        while (!s.empty()) {
            u = s.top();
            s.pop();
            for (auto v:g[u]) {
                if (!vs[v]) {
                    s.push(v);
                    vs[v] = 1;
                }
                if (v==target) {
                    possible[u] = 1;
                    way[u] = v;
                }
            }
        }
    }
    void BFS(vector<vector<int>> &g,int u) {
        q.push(u);
        vs[u] = 1;
        while (!q.empty()) {
            --res; u = q.front(); q.pop();
            for (auto v:g[u]) {
                if (!vs[v]) {
                    vs[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    void solve(vector<vector<int>> &g,vector<int> &report,int P,int C,int N) {
        possible.resize(P+1,0);
        way.resize(P+1,0);
        vs.resize(P+1,0);
        res = P;
        for (int i=1;i<=N;++i) {
            vs[report[i]] = 1;
            for (auto v:g[report[i]]) {
                vs[v] = 1;
            }
        }
        BFS(g,1);
        cout << res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int P,C,N;
    cin >> P >> C >> N;
    vector<vector<int>> fieldpath(P+1);
    vector<int> report(N+1,0);
    graph g;
    for (int i=1;i<=C;++i) {
        int u,v;
        cin >> u >> v;
        fieldpath[u].emplace_back(v);
        fieldpath[v].emplace_back(u);
    }
    for (int i=1;i<=N;++i) {
        cin >> report[i];
    }
    g.solve(fieldpath,report,P,C,N);
    return 0;
}

// vay la dfs tu report ve lai canh dong 1
// co 1 canh dong tren doan duong bi tan pha
// 