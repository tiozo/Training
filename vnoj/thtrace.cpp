#include<bits/stdc++.h>
using namespace std;

const int maxn = 1111;
int M,N,K;
vector<int> rabit,wolf;
vector<int> adj[maxn];

int main() {
    cin >> N >> M >> K;
    while (K--) {
        int r,w;
        cin >> w >> r;
        rabit.push_back(r);
        wolf.push_back(w);
    }
    while (M--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}