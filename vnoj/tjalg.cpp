#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int ans=0;
void dfs(vii &a,stack<int> &st,vi &visited,vi &nums,vi &low,int u) {
    nums[u] = ++nums[0];
    low[u] = 10005;
    st.push(u);
    for (auto v : a[u]) if (!visited[v]) {
        if (nums[v]) low[u] = min(low[u],nums[v]);
        else {
            dfs(a,st,visited,nums,low,v);
            low[u] = min(low[u],low[v]);
        }
    }
    if (low[u]<nums[u]) return;
    ans++;
    for (;;) {
        int k=st.top();
        st.pop();
        visited[k] =1;
        if (k==u) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    vii a(N+1);
    vi nums(N+1,0);
    vi visited(N+1,0);
    vi low(N+1);
    stack<int> st;
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
    }
    for (int i=1;i<=N;++i) {
        if (!visited[i]) dfs(a,st,visited,nums,low,i);
    }
    cout << ans;
}