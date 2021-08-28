#include<bits/stdc++.h>
using namespace std;
#define forvct(i,v) for (int i=0,_key = v.size();i<_key;++i)
const int nn = 100001;
int n,m,l,q,t,res,test;
int p[nn][20],a[nn],tin[nn],tout[nn],mark[nn],terror[nn];
vector<int> adj[nn],_adj[nn];
stack<int> s;

void enter() {
    cin >> n;
    //adj.resize(nn);
    //_adj.resize(nn);
    int u,v;
    for (int i=1;i<n;++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    l = log2(n);
    cin >> q;
}

void dfs(const int &u) {
    tin[u] = ++t;
    for (int j=1;j<=l;++j) p[u][j] = p[p[u][j-1]][j-1];
    forvct(j,adj[u]) {
        int v = adj[u][j];
        if (v!=p[u][0]) {
            p[v][0] = u;
            dfs(v);
        }
    }
    tout[u] = ++t;
}

bool ancestor(const int &u,const int &v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u,int v) {
    if (ancestor(u,v)) return u;
    if (ancestor(v,u)) return v;
    for (int j = l;j>=0;--j) 
        if (!ancestor(p[u][j],v)) u = p[u][j];
    return p[u][0];
}

bool cmp(const int &x,const int &y) {
    return tin[x] < tin[y];
}

bool check(const int &u) {
    int cnt = 0;
    forvct (j,_adj[u]) {
        int v = _adj[u][j];
        if (terror[u] == test) {
            if (terror[v] == test && p[v][0]==u) {
                res = -1; return -1;
            }
            bool x = check(v);
            if (res == -1) return -1;
            res += x;
        } else {
            bool x = check(v);
            if (res == -1) return -1;
            cnt += x;
        }
    }
    if (terror[u]==test || cnt == 1) return 1;
    if (cnt > 1) res++;
    return 0;
}

void process() {
    cin >> m;
    for (int i=1;i<=m;++i) {
        cin >> a[i];
        _adj[a[i]].clear();
        mark[a[i]] = test;
        terror[a[i]] = test;
    }
    sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m-1;++i) {
        int tmp = lca(a[i],a[i+1]);
        if (mark[tmp]<test) {
            mark[tmp] = test;
            a[++m] = tmp;
            _adj[tmp].clear();
        }
    }
    sort(a+1,a+m+1,cmp);
    stack<int> empty;
    swap(empty,s);
    s.push(a[1]);
    for (int i=2;i<=m;++i) {
        while (tout[s.top()]<tout[a[i]]) s.pop();
        _adj[s.top()].push_back(a[i]);
        s.push(a[i]);
    }
    res = 0;
    check(a[1]);
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    enter();
    t=0;
    p[1][0] = 1;
    dfs(1);
    ///cout << "here";
    for (test=1;test<=q;++test) process();
    //return 0;
}