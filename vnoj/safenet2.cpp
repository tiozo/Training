#include<bits/stdc++.h>
using namespace std;

class graph {
private:
    typedef vector<int> vi;
    typedef vector<vi> vii;
    vector<int> num,low;
    vector<vector<int>> components;
    stack<int> s;
    int counter=0,ans=0;
public:
    void DFS(vii &g,int u,int root) {
        low[u] = num[u] = ++counter;
        if (g[u].empty()) {
            components.emplace_back(vector<int> (1,u));
            return;
        }
        s.push(u);
        for (auto v: g[u]) {
            if (num[v]>-1) {
                low[u] = min(low[u],num[v]);
            } else {
                DFS(g,v,0);
                low[u] = min(low[u],low[v]);
                if (root || low[v] >= num[u]) {
                    components.emplace_back(vector<int> (1,u));
                    while (1) {
                        int x = s.top();
                        s.pop();
                        components.back().emplace_back(x);
                        if (x==v) break;
                    }
                }
            }
        }
    } 
    void solve(vii &g,int N,int M) {
        low.resize(N+1,-1);
        num.resize(N+1,-1);
        counter = 0;
        for (int i=1;i<=N;++i) {
            if (num[i]<0) {
                DFS(g,i,1);
            }
        }
        for (int i=0;i<int(components.size());++i) {
            ans = max(ans,int(components[i].size()));
        }
        cout << ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<vector<int>> a(N+1);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    graph g;
    g.solve(a,N,M);
    return 0;
}