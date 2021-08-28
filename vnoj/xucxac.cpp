#include<bits/stdc++.h>
using namespace std;

class uv {
public:
    int u,v,front,top,rear;
    long long val;
};

class cmp {
public:
    bool operator() (uv &a,uv &b) const{
        return a.val > b.val;
    }
};

class graph {
private:
    typedef vector<long long> vll;
    typedef vector<vll> vvll;
    typedef vector<vvll> vvvll;
    typedef vector<vvvll> vvvvll;
    typedef vector<vvvvll> vvvvvll;
    vector<vector<int>> g;
    vvvvvll F;
    uv E;
    int N,M,res=0;
    uv go1(uv u) {
        if (u.u == 1) return u;
        uv v;
        v.u = u.u-1;
        v.v = u.v;
        v.front = 7-u.top;
        v.top = u.front;
        v.rear = u.rear;
        int tmp = 7-u.front;
        v.val = u.val+tmp*g[v.u][v.v];
        return v;
    }
    uv go2(uv u) {
        if (u.v==M) return u;
        uv v;
        v.u = u.u;
        v.v = u.v+1;
        v.front = u.front;
        v.top = 7-u.rear;
        v.rear = u.top;
        int tmp = u.rear;
        v.val = u.val+tmp*g[v.u][v.v];
        return v;
    }
    uv go3(uv u) {
        if (u.u == N) return u;
        uv v;
        v.u = u.u+1;
        v.v = u.v;
        v.front = u.top;
        v.top = 7-u.front;
        v.rear = u.rear;
        int tmp = u.front;
        v.val = u.val+tmp*g[v.u][v.v];
        return v;
    }
    uv go4(uv u) {
        if (u.v==1) return u;
        uv v;
        v.u = u.u;
        v.v = u.v-1;
        v.front = u.front;
        v.top = u.rear;
        v.rear = 7-u.top;
        int tmp = 7-u.rear;
        v.val = u.val+tmp*g[v.u][v.v];
        return v;
    }
public: 
    graph (vector<vector<int>> &a,int W,int H) {
        vvvvvll empty(W+1,vvvvll (H+1,vvvll (7,vvll (7,vll (7,100000000000000000LL)))));
        swap(empty,F);
        swap(a,g);
        N=W;
        M=H;
    }
    void dijkstra(uv s) {
        priority_queue<uv,vector<uv>,cmp> pq;
        pq.push(s);
        F[s.u][s.v][s.front][s.top][s.rear] = s.val;
        while (!pq.empty()) {
            uv u = pq.top();
            pq.pop();
            if (u.val!=F[u.u][u.v][u.front][u.top][u.rear]) {
                continue;
            }
            if (u.u == E.u && u.v == E.v) {
                res = u.val;
                return;
            }
            uv v=go1(u);
            if (v.val < F[v.u][v.v][v.front][v.top][v.rear]) {
                F[v.u][v.v][v.front][v.top][v.rear] = v.val;
                pq.push(v);
            }
            v=go2(u);
            if (v.val < F[v.u][v.v][v.front][v.top][v.rear]) {
                F[v.u][v.v][v.front][v.top][v.rear] = v.val;
                pq.push(v);
            }
            v=go3(u);
            if (v.val < F[v.u][v.v][v.front][v.top][v.rear]) {
                F[v.u][v.v][v.front][v.top][v.rear] = v.val;
                pq.push(v);
            }
            v=go4(u);
            if (v.val < F[v.u][v.v][v.front][v.top][v.rear]) {
                F[v.u][v.v][v.front][v.top][v.rear] = v.val;
                pq.push(v);
            }
        }
    }
    void solve(uv S,uv _E) {
        S.top = 2;
        S.front = 1;
        S.rear = 3;
        S.val = 5*g[S.u][S.v];
        swap(_E,E);
        dijkstra(S);
        cout << res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    uv S,E;
    vector<vector<int>> a(55,vector<int> (55,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
        }
    }
    cin >> S.u >> S.v >> E.u >> E.v;
    graph g(a,N,M);
    g.solve(S,E);
    return 0;
}