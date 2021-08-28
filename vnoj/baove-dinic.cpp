#include <bits/stdc++.h>
#define maxn 5009
#define Task ""
#define vt vector
#define pb push_back
#define pii pair <int, int>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define mod 1000000007

using namespace std;

struct node
{
    int v, c, f;

    node (int v, int c): v(v), c(c){f = 0;}
};

int n, m, s, t, cnt = -1, num;
int mark[maxn], pos[maxn], d[maxn];
vector <int> ke[maxn];
vector <node> e;
queue <int> q;

void nhap()
{
    int u, v, w;
    cin >> n;
    s = n;
    t = 1;
    while (cin >> u >> v >> w)
    {
        ke[u].pb(++cnt);
        e.pb(node(v, w));
        ke[v].pb(++cnt);
        e.pb(node(u, 0));
    }
}

bool bfs()
{
    mark[s] = ++num;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        pos[u] = 0;
        for (int &id: ke[u])
        {
            int v = e[id].v;
            if (mark[v] == num || e[id].f == e[id].c) continue;
            mark[v] = num;
            d[v] = d[u]+1;
            q.push(v);
        }
    }
    return mark[t] == num;
}

int dfs(int u, int flow)
{
    if (u == t || flow == 0) return flow;

    for (; pos[u] < int(ke[u].size()); ++pos[u])
    {
        int id = ke[u][pos[u]];
        int v = e[id].v;
        if(d[v] != d[u]+1 || e[id].f == e[id].c)
            continue;
        int get = dfs(v, min(flow, e[id].c - e[id].f));
        if (get)
        {
            e[id].f += get;
            e[id^1].f -= get;
            return get;
        }
    }
    return 0;
}

void solve()
{
    long long  re = 0;
    while (bfs())
    {
        while (int add = dfs(s, mod))
            re += add;
    }
    cout << re;
}

int main()
{
    //freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    nhap();
    solve();
    return 0;
}
