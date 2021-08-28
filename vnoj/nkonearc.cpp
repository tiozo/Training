#include<bits/stdc++.h>
using namespace std;

struct _uv {
    int u,v;
};

class graph {
private:
    typedef vector<_uv> vii;
    queue<int> q;
    stack<int> s;
    vector<int> check; /// can be seen as output
    vector<int> in; /// input
    vector<int> P;
    vector<int> ke;
    vector<int> input;
    vector<int> output;
    int st,t,source = 0,sink = 0,scc=0,cnt = 0;
public:
    graph (int size) {
        check.resize(size+1,0);
        in.resize(size+1,0);
        P.resize(size+1,0);
        ke.resize(size+1,0);
        input.resize(size+1,0);
        output.resize(size+1,0);
    }
    void make(int u,int v) {
        input[v] = 1;
        output[u] = 1;
        ++P[v];
    }
    void reset() {
        vector<int> empty(check.size(),0);
        swap(check,empty);
    }
    void clear(int tmp) {
        switch (tmp) {
            case (1): {
                stack<int> empty;
                swap(s,empty);
                break;
            }
            case (2): {
                queue<int> empty;
                swap(q,empty);
            }
        };
    }
    void DFS(vii &g,int u) {
        clear(1);
        s.push(u);
        while (!s.empty()) {
            u=s.top();
            s.pop();
            if (!check[u]) {
                check[u] = 1;
            }
            for (int i=P[u]+1;i<=P[u+1];++i) {
                int v = ke[i];
                if(!check[v]) {
                    check[v] = 1;
                    s.push(v);
                    in[u] = 1;
                }
            }
        }
    }
    void BFS(vii &g,int u) {
        clear(2);
        q.push(u);
        check[u] = 1;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i = P[u]+1;i<=P[u+1];++i) {
                int v = ke[i];
                if (!check[v]) {
                    check[v] = 1;
                    q.push(v);
                    in[u] = 1;
                } 
            }
        }
    }
    void solve(vii &g,int N,int M) {
        reset();
        int s,t;
        for (int i=2;i<=N+1;++i) {
            P[i] += P[i-1];
        }
        for (int i=1;i<=M;++i) {
            ke[P[g[i].v]] = g[i].u;
            P[g[i].v]--;
        }
        for (int i=1;i<=N;++i) {
            if (!check[i]) {
                DFS(g,i);
                check[i] = 0;
            }
        }
        for (int i=1;i<=N;++i) {
            if (!input[i]) {
                t = i;
                ++cnt;
            }
            if (!output[i]) {
                s = i;
                ++cnt;
            }
            if (cnt == 2) {
                break;
            }
        }
        if (cnt != 2) {
            for (int i=1;i<=N;++i) {
                if (!in[i]) {
                    ++sink;
                    t = i;
                }
                if (!check[i]) {
                    ++source;
                    s = i;
                }
                if (source == 1 && sink == 1) {
                    break;
                }
            }
            if (source != 1 && sink!=1) {
                cout << "NO\n";
                return;
            } else {
                cout << "YES\n";
                cout << s << ' ' << t;
            }
        } else {
            cout << "YES\n";
            cout << s << ' ' << t;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    graph g(30000);
    vector<_uv> a(30000,{0,0});
    for (int i=1;i<=M;++i) {
        cin >> a[i].u >> a[i].v;
        g.make(a[i].u,a[i].v);
    }
    g.solve(a,N,M);
    return 0;
}

/*
    how about input?
    how to know if/whether or not an input has been declare?
    simple!

*/