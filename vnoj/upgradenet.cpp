#include<bits/stdc++.h>
using namespace std;

int N,logn;
vector<int> sett;
vector<int> h;
vector<vector<pair<int,int>>> mst;
vector<pair<int,pair<int,int>>> edges;
vector<vector<int>> minDist,par;
void prepareSet() {
    for (int i=0;i<N;++i) {
        sett.push_back(i);
    }
}

int find(int u) {
    return u==sett[u] ? u : sett[u] = find(sett[u]);
}

void krushkal() {
    prepareSet();
    sort(edges.begin(),edges.end());
    mst.resize(N);
    for (auto &e:edges) {
        int u = e.second.first, v = e.second.second, c = -e.first;
        if (find(u)!=find(v)) {
            mst[u].emplace_back(v,c);
            mst[v].emplace_back(u,c);
            sett[sett[u]]=sett[v];
        }
    }
}

void dfs(int u) {
    //cout << u << '\n';
    for (auto &m:mst[u]) {
        int v = m.first, c = m.second;
        if (v!=par[u][0]) {
            h[v]=h[u]+1;
            par[v][0]=u;
            minDist[v][0] = c;
            //cout << v << ' ';
            dfs(v);
        }
    }
}

void prepareLCA() {
    for (int j=1;1<<j<N;++j) {
        for (int i=0;i<N;++i) {
            if (par[i][j-1]!=-1) {
                par[i][j] = par[par[i][j-1]][j-1];
                minDist[i][j] = min(minDist[i][j-1],minDist[par[i][j-1]][j-1]);
            }
        }
    }
}

int getMin(int u,int v) {
    if (h[u]<h[v]) swap(u,v);
    int res = 1e9;
    for (int j=logn;j>=0;--j) {
        if (h[u]-(1<<j)>=h[v]) {
            res = min(res,minDist[u][j]);
            u=par[u][j];
        }
    }
    //cout << res << ' ';
    if (u==v) return res;
    for (int j=logn;j>=0;--j) {
        if (par[u][j]!=par[v][j]) {
            res = min({res,minDist[u][j],minDist[v][j]});
            u=par[u][j]; v=par[v][j];
        }
    }
    //cout << res << '\n';
    return min({res,minDist[u][0],minDist[v][0]});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long res = 0;
    int M;
    cin >> N >> M;
    logn = 0; while (1<<logn<=N) ++logn; --logn;
    h.resize(N); h[0]=0;
    minDist=vector<vector<int>>(N,vector<int>(17,0));
    par=vector<vector<int>>(N,vector<int>(17,-1));
    for (int i=1;i<=M;++i) {
        int u,v,c; cin >> u >> v >> c;
        edges.push_back({-c,{--u,--v}});
    }
    krushkal();
    dfs(0);
    prepareLCA();
    for (auto &e:edges) {
        int u = e.second.first, v = e.second.second, c= e.first;
        res += getMin(u,v) + c;
    }
    cout << res;
    return 0;
}