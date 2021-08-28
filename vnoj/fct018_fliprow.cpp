#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N+1][N+1], color[N+1];
int n,m;
vector<pair<int,int>> graph[N+1];
map<int,vector<pair<int,int>>> numMap;
bool conflict; 

void addEdge(int u, int v, int type) {
    graph[u].push_back(make_pair(v, type));
    graph[v].push_back(make_pair(u, type));
}

void DFS(int u, int c) {
    color[u] = c;
    for(auto e: graph[u]) {
        int v = e.first, type = e.second;
        int expect = c ^ type;
        if (color[v] == -1)
            DFS(v, expect);
        else if (color[v] != expect)
            conflict = true;
    }
}

bool solve() {
    if (m%2==1) {
        set<int> s;
        for (int i=0;i<n;++i) {
            s.insert(a[i][m/2]);
        }
        if (s.size()<n) return false;
    }
    for (int j=0;j<m/2;++j) {
        for (int i=0;i<n;++i) {
            numMap[a[i][j]].push_back({i,0});
            numMap[a[i][m-j-1]].push_back({i,1});
        }
        for(auto e: numMap) {
            int x = e.first;
            vector<pair<int,int>> pos = e.second;

            if (pos.size() > 2)
                return false;
            else if (pos.size() == 2) {
                int type = (pos[0].second == pos[1].second);
                addEdge(pos[0].first, pos[1].first, type);
            }
        }
        numMap.clear();
    }
    for(int u = 0; u < n; ++u)
            color[u] = -1;
        conflict = false;
    for(int u = 0; u < n; ++u) {
        if (color[u] == -1) {
            DFS(u, 0);
            if (conflict)
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin >> a[i][j];
        }
    }
    if (!solve()) cout << "No";
    else {
        cout << "Yes\n";
        vector<int> ans;
        for (int i=0;i<n;++i) {
            if (color[i] == 1) {
                ans.push_back(i);
            }
        }
        cout << ans.size() << '\n';
        for (int i=0;i<ans.size();++i) {
            cout << ans[i]+1;
            if (i<(int)ans.size()-1) {
                cout << ' ';
            } else cout << "";
        }
    }
    return 0;
}