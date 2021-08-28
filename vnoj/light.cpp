#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi d,p;
int n,m,k,s,t;

int find(vvi &c,vvi &f) {
    queue<int> q;
    fill(d.begin(),d.end(),0);
    q.push(s);
    d[s] = s; p[s] = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v=1;v<=m;++v) {
            if (!d[v]) {
                if (f[u][v]<c[u][v]) {
                    q.push(v);
                    d[v]=u;
                    p[v] = min(p[u],c[u][v]-f[u][v]);
                } else {
                    if (f[v][u]) {
                        q.push(v);
                        d[v] = -u;
                        p[v] = min(p[u],f[v][u]);
                    }
                }
                if (d[t]) return 1;
            }
        }
    }
    return 0;
}

void incflow(vvi&c,vvi&f) {
    int x=t,y,val=p[t];
    while (x!=s) {
        y = x; x=d[x];
        if (x>0) f[x][y] += val;
        else {
            x =-x;
            f[y][x]-=val;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    d.resize(n+m+3);
    p.resize(n+m+3);
    vvi c(n+m+3,vi (n+m+3));
    vvi f(n+m+3,vi (n+m+3));
    s = m+n+1; t = s+1;
    for (int i=1;i<=n;++i) {
        int d; cin >> d; c[s][i] = d;
    }
    for (int i=1;i<=m;++i) {
        int d; cin >> d; c[n+i][t] = d;
    }
    while (k--) {
        int x,y;
        cin >> x >> y;
        c[x][y+n] = 1e9;
    }
    m+=n+2;
    while (find(c,f)) incflow(c,f);
    int res = 0;
    for (int i=1;i<=n;++i) res+=f[s][i];
    cout << res;
    return 0;
}