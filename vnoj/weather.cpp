#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    typedef vector<vector<int>> vii;
    vector<int> check;
    vector<int> low;
    vector<int> num;
    vector<int> Size;
    vector<int> way;
    queue<int> q;
    stack<int> s;
    int res = 0,timer = 0,cnt = 0;
public:
    graph (int size) {
        check.resize(size+1,-1);
        low.resize(size+1,0);
        num.resize(size+1,0);
        Size.resize(size+1,0);
        way.resize(size+1,0);
    }
    void clear(int tmp) {
        switch (tmp) {
            case (1): {
                queue<int> empty;
                swap(empty,q);
                break;
            }
            case (2): {
                stack<int> empty;
                swap(empty,s);
                break;
            }
        }
    }
    void DFS(vii &g,int u,int N) {
        num[u] = low[u] = ++timer; 
        Size[u] = 1;
        for (auto v:g[u]) {
            if (check[u] == v) continue;
            if (!num[v]) {
                check[v] = u;
                DFS(g,v,N);
                Size[u] += Size[v];
                if (low[v]>=num[v]) {
                    res += 1LL * Size[v] * (N - Size[v]);
                }
                low[u] = min(low[u],low[v]);
            } else {
                low[u] = min(low[u],num[v]);
            }
        }
    }
    void BFS(vii &g,int u) {
        clear(1);
        q.push(u);
        check[u] = 1;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int v:g[u]) {
                if (!check[v]) {
                    ++cnt;
                    check[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    void solve(vii &g,int N,int M) {
        DFS(g,1,N);
        cout << res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    graph g(N+1);
    vector<vector<int>> a(N+1);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    g.solve(a,N,M);
    return 0;
}