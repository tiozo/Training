#include<bits/stdc++.h>
using namespace std;

struct _uv {
    int u,v;
};

class graph{
private: 
    typedef vector<_uv> vii;
    vector<int> check;
    vector<int> P;
    vector<int> ke;
    queue<int> q;
    stack<int> s;
public:
    graph(int size,int T) {
        check.resize(size+1,0);
        P.resize(size+1,0);
        ke.resize(size+1,0);
        check[T] = 1;
    }
    void make(int u) {
        ++P[u];
    } 
    void q_clear(queue<int> &q) {
        queue<int> empty;
        swap(empty,q);
    }
    void s_clear(stack<int> &q) {
        stack<int> empty;
        swap(empty,q);
    }
    void BFS(vii &g, int u) {
        q_clear(q);
        check[u] = 1;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i=P[u]+1;i<=P[u+1];++i) {
                int v = ke[i];
                if (!check[v]) {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }
    }
    void DFS(vii &g,int u) {
        s_clear(s);
        s.push(u);
        while (!s.empty()) {
            u = s.top();
            s.pop();
            if (!check[u]) {
                check[u] = 1;
            }
            for (int i=P[u]+1;i<=P[u+1];++i) {
                int v = ke[i];
                if (!check[v]) {
                    check[v] = 1;
                    s.push(v);
                }
            }
        }
    }
    void solve(vii &g,int N,int M,int T) {
        for (int i=2;i<=N+1;++i) {
            P[i] += P[i-1];
        }
        for (int i=1;i<=M;++i) {
            ke[P[g[i].u]] = g[i].v;
            P[g[i].u]--;
        }
        DFS(g,T);
        for (int i=1;i<=N;++i) {
            if (!check[i]) {
                DFS(g,i);
                check[i] = 0;
            }
        }
        int res = 0;
        for (int i=1;i<=N;++i) {
            if (!check[i]) {
                ++res;
            }
        }
        cout << res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M,T;
    cin >> N >> M >> T;
    graph g(1e4,T);
    vector<_uv> a(1e4,{0,0});
    for (int i=1;i<=M;++i) {
        cin >> a[i].v >> a[i].u;
        g.make(a[i].u);
    }
    g.solve(a,N,M,T);
    return 0;
}

/*
    xem thử số nào đã biến đổi rồi
    check[i] = 1;
    xem thử số nào chưa thì thêm nó vào biến thành T
    6 4 3
    1 2
    2 5
    4 2
    6 5
    solve:
    check 1 2 4 6 = 1
    ans 1 5 3
    how does it run?
    we see that 1 have 2 as a end point
    put 1 and 2 is already visited but not reaching T
    put 2 and 5 is already visited but not reaching T
    we also have 4 is visited and its can run to 2 which already visited above
    put 6 and 5 is visited but not reaching T
    we count that every number can run to 2 so can we see 2 as T?
    if possible the problem now shrink down to 2 to T
    but we see that 2 is to 5 so
    now problem now is 5 to 3
    we make a machine do it 5 to 3
    pop the answer out is 1 machine needed
    we also now that there is no machine pop from T back to some random number in N
    after few run we might see that 
    check [1, 3, 0, 1, 2, 1]
*/