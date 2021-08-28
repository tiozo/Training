#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<pair<int,int>> adj[1001];

int calc(int x) {
    priority_queue<int> pq;
    vector<vector<bool>> free(1001,vector<bool>(1001,1));
    vector<int> d(1001,0);
    for (auto &a:adj[x]) {
        pq.push(a.first);
    }
    while (!pq.size()) {
        int u = pq.top(); pq.pop();
        if (u==x) return (d[x]);
    }
}

void process() {
    cin >> N >> M;
    for (int i=1;i<=M;++i) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
    }
    for (int i=1;i<=N;++i) {
        printf("%d\n",calc(i));
    }
}

int main() {
    int tc; cin >> tc;
    while (tc) {
        progress();
    }
    return 0;
}