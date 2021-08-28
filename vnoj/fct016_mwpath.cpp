#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> ii;
typedef pair<long long,ii> iii;

struct Edge
{
	long long u, v, c;
	Edge(){}
	Edge(long long u, long long v, long long c) : u(u), v(v), c(c){}
}E[500001];

int top = 0;

int n, m, k, s, t;
bool spe[100001];
set<ii> adj[100001][2];

long long ans = 1e18;
long long d[500001][2];

void dijkstra()
{
	for (int i=0;i<=m;++i)
		for (int j=0;j<=1;++j)
			d[i][j] = 1e18;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	for (auto val : adj[s][spe[s]])
	{
		long long id = val.second;
		d[id][spe[s]] = E[id].c;
		pq.push(iii(E[id].c, ii(id, spe[s])));
	}
	while(!pq.empty())
	{
		long long cost = pq.top().first;
		long long id = pq.top().second.first;
		long long cnt = pq.top().second.second;
		pq.pop();
		if (cost != d[id][cnt]) continue;

		long long u = E[id].v;
		if (u == t && (cnt == 1 || (cnt == 0 && spe[t])))
			ans = min(ans, cost);

		set<ii>::iterator it = adj[u][cnt + spe[u]].lower_bound(ii((E[id].c + 1)/2, -1));
		while((it != adj[u][cnt + spe[u]].end()) && (E[id].c*2 >= (*it).first))
		{
			long long ncost = (*it).first, nid = (*it).second;
			if (d[nid][cnt + spe[u]] > ncost + d[id][cnt])
			{
				d[nid][cnt + spe[u]] = ncost + d[id][cnt];
				pq.push(iii(d[nid][cnt + spe[u]], ii(nid, cnt + spe[u])));
			} 
			it = adj[u][cnt + spe[u]].erase(it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	long long u, v, c;
	for (int i=1;i<=m;++i)
	{
		cin >> u >> v >> c;
		E[++top] = Edge(u, v, c);
		adj[u][0].insert(ii(c, top));
	}        
	cin >> k;
	for (int i=1;i<=k;++i)
	{
		long long x; cin >> x;
		spe[x] = true;
	}
	for (int i=1;i<=m;++i)
		if (!spe[E[i].v])
			adj[E[i].u][1].insert(ii(E[i].c, i));	
	cin >> s >> t;
	dijkstra();
	if (ans == 1e18) cout << -1;
	else cout << ans;
}