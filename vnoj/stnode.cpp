#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int N,M,S,T,comp;
vector<int> a[maxn*2],ds;
vector<int> vs(maxn*2,0), cant(maxn*2);

bool dfs(int u) {
    if (u==T+N)
        return true;
    if (vs[u]) 
        return false;
    vs[u]=true;
    for (int &v:a[u]) {
        if (dfs(v)) {
            if (u+N==v) cant[u] = v;
            a[v].push_back(u);
            ds.push_back(u);
            return true;
        }
    }
    return false;
}

void dfs2(int u) {
    vs[u] = comp;
    for (int v:a[u]) {
        if (!vs[v] && v!=cant[u]) dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> S >> T;
    for (int i=0;i<M;++i) {
        int u,v; cin >> u >> v;
        a[u+N].push_back(v);
    }
    for (int i=1;i<=N;++i) a[i].push_back(i+N);
    dfs(S);
    fill(vs.begin(),vs.end(),0);
    for (int i=ds.size()-1;i>=0;--i) {
        if (!vs[ds[i]]) {
            ++comp;
            dfs2(ds[i]);
        }
    }
    int dem = 0;
    for (int i=1;i<=N;++i) if (i!=S && i!=T && vs[i]!=vs[i+N]) ++dem;
    cout << dem;
    return 0;
}