#include<bits/stdc++.h>
using namespace std;

const int oo=1e6;
int N=4;
vector<vector<int> > maps(4, vector<int> (6,0));
vector<int> trace(5,0);

void dfs(int u) {
    for (int v=1;v<=N;++v) {
        if (trace[v]==0 && maps[u][v]) {
            trace[v]=u;
            cout << u << '\n';
            dfs(v);
        }
    }
}

int main() {
    dfs(1);
    return 0;
}
