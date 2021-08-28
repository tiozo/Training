///BS + DSU 
#include<bits/stdc++.h>
using namespace std;

class dsu {
private:
    vector<int> par,rank;
public: 
    dsu (int size):par(size+1), rank(size+1,0) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return u == par[u] ? u : par[u]  = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u);
        v = find(v);
        if (u==v) return false;
        if (rank[u]==rank[v]) rank[u]++;
        if (rank[u] > rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};
int N,K;

int cnt(vector<vector<int>> &a,int limit) {
    dsu sett(N);
    int cc = N;
    for (int i=1;i<=N;++i) {
        for (int j=i+1;j<=N;++j) {
            if (a[i][j]<limit)
            if (sett.join(i,j)) cc--;
        }
    }
    return cc;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    int L = 0, R = 32767,res = 0;
    while (L<=R) {
        int mid = (L+R)>>1;
        if (cnt(a,mid)>=K) {
            res = mid;
            L = mid + 1;
        } else R = mid - 1;
    }
    cout << res;
    return 0;
}