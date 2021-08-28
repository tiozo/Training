#include<bits/stdc++.h>
using namespace std;

/// N fields, M cows
struct Base {
    char type; int u;
};
int N,M,numbers = 1;
vector<int> check;
vector<vector<int>> S,D;
bool impossible;

void dfs(int u,int v) {
    check[u] = v;
    for (auto n:S[u]) {
        if (check[n]==3-v) impossible = true;
        if (check[n]==0) dfs(n,v);
    }
    for (auto n:D[u]) {
        if (check[n]==v) impossible = true;
        if (check[n]==0) dfs(n,3-v);
    }
}

int main() {
    cin >> N >> M;
    char type; int u,v;
    check.resize(N+1);
    S.resize(N+1);
    D.resize(N+1);
    for (int i=1;i<=M;++i) {
        cin >> type >> u >> v;
        if (type == 'S') {S[u].push_back(v);S[v].push_back(u);}
        else {D[u].push_back(v);D[v].push_back(u);}
    }
    for (int i=1;i<=N;++i) {
        if (!check[i]) {dfs(i,1); numbers++;}
    }
    if (impossible) cout << "0\n";
    else {
        cout << "1";
        for (int i=0; i<numbers-1; i++) cout << "0";
        cout << "\n";
    } 
    return 0;
}