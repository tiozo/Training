#include<bits/stdc++.h>
using namespace std;

class graph {
private:
    vector<vector<int>> g;
    vector<vector<int>> P;
    vector<int> num;
    vector<int> low;
    vector<int> tin;
    vector<int> tout;
    vector<int> block;
    queue<int> q;
    int N,timer = 0;
    bool valid = false;
public:
    void DFS(int p,int u) {
        tin[u] = ++timer;
        num[u] = ++num[0];
        low[u] = N+1;
        P[u][0] = p;
        for (int i=1;i<=20;++i) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
        for (auto v:g[u]) {
            if (v==p) continue;
            if (num[v]) {
                low[u] = min(low[u],num[v]);
            } else {
                DFS(u,v);
                low[u] = min(low[u],low[v]);
            }
        }
        tout[u] = ++timer;
    }
    bool isDecendent(int v,int u) {
        return (tin[u]<=tin[v] && tout[v]<=tout[u]); 
    }
    int findParent(int p,int v) {
        for (int i=20;i>=0;--i) {
            int u = P[v][i];
            if (u>0 && u!=p && isDecendent(u,p)) {
                v = u;
            }
        }
        return v;
    }
    bool Q1(int A,int B,int G1,int G2) {
        if (num[G1] > num[G2]) swap(G1,G2);
        if (P[G2][0] != G1) return true;
        if (low[G2]<=num[G1]) return true;
        if (isDecendent(A,G2)==isDecendent(B,G2)) return true;
        return false;
    }
    bool Q2(int A,int B,int C) {
        if (num[A]>num[B]) swap(A,B);
        if (P[B][0]==A) return true;
        if (isDecendent(B,A)) {
            if (isDecendent(C,A) && isDecendent(B,C)) {
                B = findParent(C,B);
                if (low[B]<num[C]) return true;
                return false;
            }
            return true;
        }
        if (isDecendent(C,A)||isDecendent(C,B)) return true;
        if (isDecendent(A,C)&&isDecendent(B,C)) {
            A = findParent(C,A);
            B = findParent(C,B);
            if (A==B) return true;
            if (low[A]<num[C] && low[B]<num[C]) return true;
            return false;
        }
        if (isDecendent(A,C)||isDecendent(B,C)) {
            if (isDecendent(B,C)) swap(A,B);
            A = findParent(C,A);
            if (low[A] < num[C]) return true;
            return false;
        }
        return true;
    }
    void solve(vector<vector<int>> &a,int _N,int E) {
        swap(a,g);
        swap(_N,N);
        num.resize(N+1);
        low.resize(N+1,0);
        tin.resize(N+1,0);
        tout.resize(N+1,0);
        vector<vector<int>> emp1(N+1,vector<int> (21));
        swap(emp1,P);
        DFS(0,1);
        int Q;
        cin >> Q;
        while (Q--) {
            int type;
            cin >> type; 
            if (type==1) {
                int A,B,G1,G2;
                cin >> A >> B >> G1 >> G2;
                if (Q1(A,B,G1,G2)) {
                    puts("yes");
                } else puts("no");
            } else {
                int A,B,C;
                cin >> A >> B >> C;
                if (Q2(A,B,C)) {
                    puts("yes");
                } else puts("no");
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,E;
    cin >> N >> E;
    vector<vector<int>> a(N+1);
    graph g;
    for (int i=1;i<=E;++i) {
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    g.solve(a,N,E);
    return 0;
}