#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
    int name,val;
};

class edge {
public: 
    typedef vector<node>::const_iterator iter;
    iter from,to;
    int val;
    edge (const iter &from,const iter &to): from(from), to(to) {
        val = abs(from->val - to->val);
    }
};

bool operator < (node&a,node&b) {
    return a.val < b.val;
}

bool operator > (const edge&a,const edge&b) {
    return a.val > b.val;
}

void push_edges(priority_queue<edge, vector<edge>, greater<edge>>& heap,vector<node> &a) {
    sort(a.begin(),a.end());
    a.push_back({-1,0});
    for (auto iter = a.begin();iter != a.end()-2;++iter) {
        heap.push({iter,iter+1});
    }
}

vector<int> init_set(int n) {
    vector<int> sett(n);
    for (int i=0;i<n;++i) {
        sett[i] = i;
    }
    return sett;
}

int find(vector<int> &sett,int u) {
    if (sett[u]!=u) sett[u] = find(sett,sett[u]);
    return sett[u];
}

bool join(vector<int> &sett,int u,int v) {
    u = find(sett,u);
    v = find(sett,v);
    if (u==v) return false;
    if (rand()&1) sett[u] = v;
    else sett[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(1e7);
    int N;
    cin >> N;
    vector<node> a(N),b(N),c(N);
    for (int i=0;i<N;++i) {
        cin >>a[i].val>>b[i].val>>c[i].val;
        a[i].name = b[i].name = c[i].name = i;
    }
    priority_queue<edge, vector<edge>, greater<edge>> heap;
    push_edges(heap,a);
    push_edges(heap,b);
    push_edges(heap,c);
    auto sett = init_set(N);
    long long res = 0;
    int cnt = 0;
    while (!heap.empty()) {
        if (cnt == N-1) break;
        auto e = heap.top();
        heap.pop();
        if (join(sett,e.from->name,e.to->name)) res += e.val,++cnt;
        auto next = e.to+1;
        if (next->name!=-1) heap.push({e.from,next});
    }
    cout << res;
    return 0;
}