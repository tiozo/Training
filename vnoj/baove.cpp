#include<bits/stdc++.h>
using namespace std;

int N;
int bfs(int s,int t,vector<int> &par,vector<vector<int>> &a,vector<vector<int>> &cap) {
    fill(par.begin(),par.end(),-1);
    par[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,1e9});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next: a[cur]) {
            if (par[next] == -1 && cap[cur][next]) {
                par[next] = cur;
                int new_flow = min (flow,cap[cur][next]);
                if (next==t) {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s,int t,vector<vector<int>> &a,vector<vector<int>> &cap) {
    int flow = 0;
    vector<int> par(N+1);
    int new_flow;
    while (new_flow = bfs(s,t,par,a,cap)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> N;
    vector<vector<int>> a(N+1);
    vector<vector<int>> cap(N+1,vector<int> (N+1,0));
    int u,v,l;
    while (cin >> u >> v >> l) {
        a[u].push_back(v);
        a[v].push_back(u);
        cap[u][v] = l;
        cap[v][u] = 0;
    }
    cout << maxflow(N,1,a,cap);
    return 0;
}