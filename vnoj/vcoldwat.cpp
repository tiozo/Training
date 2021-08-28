#include<bits/stdc++.h>
using namespace std;

class queues{
private:
    int l,h;
    vector<int> a;
public:
    queues (int size) {
        a.resize(size+1,0);
    }
    void init() {
        l = 0;
        h = 0;
    }
    bool empty() {
        return l==h;
    }
    int size() {
        return h-l;
    }
    void push( int x ) { 
        a[h++] = x; 
    }
    int front() {
        return a[l];
    }
    void pop() {
        ++l;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,C;
    cin >> N >> C;
    queues q(N);
    vector<vector<int>> g(N+1,vector<int> (2,0));
    vector<int> F(N+1,0);
    for (int i=1;i<=C;++i) {
        int u; ///node 
        cin >> u;
        cin >> g[u][0] >> g[u][1];
    }
    q.init(); q.push(1);
    for (int cnt = 1;q.empty() == false;++cnt) {
        for (int i=0, n =q.size();i<n;++i) {
            F[q.front()] = cnt;
            if (g[q.front()][0] != 0) {
                q.push(g[q.front()][0]);
                q.push(g[q.front()][1]);
            }
            q.pop();
        }
    }
    for (int i=1;i<=N;++i) {
        cout << F[i] << '\n';
    }
    return 0;
}