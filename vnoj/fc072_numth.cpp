#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.inp","r",stdin);
    set<long long,greater<>> pq;
    long long k,x; cin >> k;
    while (cin >> x) {
        pq.insert(x);
    }
    while (--k) {
        pq.erase(pq.begin());
    }
    cout << *pq.begin();
    return 0;
}