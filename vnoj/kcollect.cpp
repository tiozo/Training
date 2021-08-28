#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 106, M = N * N, inf = 1e9;
int m, n, a[M];
char c[N][N];
vector<int> g[M]; // graph of Grid
vector<int> G[M]; // graph of DAG
int s[M]; // val of DAG
int st[M], top; // stack

void Input() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 0; i < m; ++i) cin >> c[i];
}

void GridToGraph() {
	for (int i = 0, num = 0; i < m; ++i)
		for (int j = 0; j < n; ++j, ++num) {
			if (c[i][j] == '#') continue;
			if (i + 1 < m && c[i + 1][j] != '#') g[num].emplace_back(num + n);
			if (j + 1 < n && c[i][j + 1] != '#') g[num].emplace_back(num + 1);

			if (c[i][j] == 'N') {
				if (i > 0 && c[i - 1][j] != '#') g[num].emplace_back(num - n);
			}
			else if (c[i][j] == 'W') {
				if (j > 0 && c[i][j - 1] != '#') g[num].emplace_back(num - 1);
			}
			else a[num] = c[i][j] - 48;
		}
	n *= m;
}

int label[M], cntScc; // count strong connected components
int num[M], low[M], tme;
void SCC(int u) {
	num[u] = low[u] = ++tme;
	st[++top] = u;

	for (int v : g[u]) {
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			SCC(v);
			low[u] = min(low[u], low[v]);
		}
	}

	if (num[u] == low[u]) {
		++cntScc;
		while (st[top] != u) {
			num[st[top]] = low[st[top]] = inf;
			label[st[top--]] = cntScc;
		}
		num[u] = low[u] = inf;
		label[st[top--]] = cntScc;
	}
}

void GraphToDAG() {
	for (int i = 0; i < n; ++i) label[i] = cntScc - label[i];
	for (int i = 0; i < n; ++i) {
		s[label[i]] += a[i];
		for (int v : g[i])
			if (label[v] != label[i]) G[label[i]].emplace_back(label[v]);
	}
}

bool was[M];
void TopoSort(int u) {
	if (was[u]) return;
	was[u] = true;
	for (int v : G[u]) TopoSort(v);
	st[++top] = u;
}

int dp[M];
int LongestPathOnDAG() {
	for (int i = 1, u; i <= top; ++i) {
		u = st[i];
		for (int v : G[u]) dp[u] = max(dp[u], dp[v]);
		dp[u] += s[u];
	}
	return dp[0];
}

int main() {
	Input();
	GridToGraph();
	SCC(0);
	GraphToDAG();
	TopoSort(0);
	cout << LongestPathOnDAG();
}