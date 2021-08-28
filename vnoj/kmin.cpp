#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    int m,n,k; cin >> m >> n >> k;
    vector<int> a(m),b(n),p(m+4);
    for (int &a:a) cin >> a;
    for (int &b:b) cin >> b; 
    sort(b.begin(),b.end());
    for (int i=0;i<m;++i) pq.push({a[i]+b[0],i});
    for (int i=0;i<k;++i) {
        pair<int,int> tmp = pq.top(); pq.pop();
        cout << tmp.first << '\n';
        if (p[tmp.second]<n-1) 
            pq.push({a[tmp.second]+b[++p[tmp.second]],tmp.second});
    }
    return 0;
}