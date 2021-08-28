#include<bits/stdc++.h>
using namespace std;

int n,m,s,f;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

int dijkstra(vvi &c,vi &d,vi &t) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({s,0});
    fill(d.begin(),d.end(),1e9);
    d[s] = 0;
    t[s] = -1;
    while (!q.empty()) {
        int u = q.top().first, flow = q.top().second; q.pop();
        if (flow > d[u]) continue;
        for (int v=1;v<=n;++v) {
            if (c[u][v] != 1e9 && flow+c[u][v] < d[v]) {
                q.push({v,d[v]=flow+c[u][v]});
                t[v] = u;
            }
        }
    }
    for (int i=f;t[i]!=-1;i=t[i]) {
        c[i][t[i]]=-c[i][t[i]];
        c[t[i]][i] = 1e9;
    }
    return d[f];
}

int FordBellman(vvi &c,vi&d,vi&t) {
    fill(d.begin(),d.end(),1e9); d[s] = 0; t[s] = -1;
    for (int step = 0,stop =0;step < n-1 && !stop;++step) {
        stop = 1;
        for (int u = 1;u<=n;++u) if (d[u]!=1e9){
            for (int v=1;v<=n;++v) if (c[u][v]!=1e9 && d[u]+c[u][v] < d[v]){
                d[v] = d[u]+c[u][v];
                t[v] = u;
                stop = 0;
            }
        }
    }
    for (int v = f;t[v]!=-1;v=t[v]) {
        c[t[v]][v] = 1e9;
    }
    return d[f];
}

void BalanceGraph(vvi &g) {
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) {
            if (g[i][j]!=1e9 && g[j][i] != 1e9) {
                g[i][j] = g[j][i] = 1e9;
            }
        }
    }
}

stack<int> st;
void dfs(vvi &c,int u) {
    if (u==s) {
        cout << st.size()+1 << ' ' << s << ' ';
        for (;!st.empty();st.pop()) cout << st.top() << ' ';
        cout << '\n';
    } else {
        for (int v = 1;v<=n;++v) {
            if (c[u][v]!=1e9) {
                st.push(u);
                dfs(c,v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> f;
    vvi g(n+1,vi (n+1,1e9));
    vi d(n+1,1e9);
    vi par(n+1);
    for (int i=1;i<=m;++i) {
        int u,v,l;
        cin >> u >> v >> l;
        g[u][v] = g[v][u] = l;
    }
    cout << dijkstra(g,d,par) + FordBellman(g,d,par) << '\n';
    BalanceGraph(g);
    dfs(g,f);
    return 0;
}