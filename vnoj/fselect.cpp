#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
const int logn=19;
typedef vector<vector<int>> dsk;
int P[maxn][logn],L[maxn];
dsk a,ls;
int N,Q;

void dfs(int u) {
    for (auto v:a[u]) {
        if (v!=P[u][0]) {
            P[v][0] = u; L[v] = L[u] + 1;
            dfs(v);
        }
    }
}

void preprocess(int N) {
    for (int j=1;1<<j <= N;++j) {
        for (int i=0;i <= N;++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

#define TWO(x) (1<<(x))

int LCA(int u,int v) {
    int res = 0;    
    int tmp, log = 0, i;
    if (L[u]<L[v]) swap(u,v);
    for (;1<<log<=L[u];++log); --log;
    for (int i = log;i>=0;--i) {
        int x = P[u][i];
        if (x && L[x] >= L[v]) {
            res += TWO(i);
            u = x;
        }
    }
    if (u!=v) {
        for (int i = log;i>=0;--i) 
            if (P[u][i] != P[v][i]) {
                res += TWO(i) + TWO(i);
                u = P[u][i]; v = P[v][i];
            }
        res += 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    int root = 1;
    a.resize(N+1);
    ls.resize(N+1);
    for (int i=1;i<=N;++i) {
        int u,v;
        cin >> u >> v;
        ls[u].push_back(i);
        if (v) a[v].push_back(i);
        else root = i;
    }
    dfs(root);
    preprocess(N);
    for (int c=1;c<=Q;++c) {
        int x = ls[c][0],y ,best = 0,save = x,cur;
        for (int i=0;i<ls[c].size();++i) {
            y = ls[c][i];
            cur = LCA(x,y);
            if (cur>best) {
                best = cur;
                save = y;
            }
        }
        x = save, best = 0, save = x;
        for (int i=0;i<ls[c].size();++i) {
            y = ls[c][i];
            cur = LCA(x,y);
            if (cur>best) {
                best = cur;
                save = y;
            }
        }
        cout << best << '\n';
    }
    return 0;
}