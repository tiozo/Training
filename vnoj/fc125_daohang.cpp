#include<bits/stdc++.h>
using namespace std;

int c,t,u,v,vis[2000001], leftKid;
vector<int> a[2000001], mother;
stack<int> s;

void check() {
    if (c-(int)mother.size()==2*leftKid) {
        cout << mother.size() << ' ' << leftKid << '\n';
        for (auto m:mother) cout << (m+1) << ' ';
        cout << '\n';
        for (int i=0;i<c;++i) if (vis[i]==0) cout << (i+1) << ' ';
        cout << '\n';
        for (int i=0;i<c;++i) if (vis[i]==2) cout << (i+1) << ' '; 
        cout << '\n';
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    for (int i=0;i<t;++i) {
        cin >> u >> v;
        a[--u].push_back(--v);
        a[v].push_back(u);
    }
    check();
    s.push(0);
    while (!s.empty()) {
        int u = s.top(); s.pop();
        if (vis[u]==2) continue;
        if (++vis[u]==2) {
            mother.pop_back();
            leftKid++;
            check();
        } else {
            s.push(u);
            mother.push_back(u);
            check();
            for (auto next:a[u]) if (vis[next]==0) s.push(next);        
        }
    }
    return 0;
}