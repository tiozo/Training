#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> a(3*N+1);
    for (int i=1;i<=3*N;++i) {
        cin >> a[i];
    }
    long long sum = 0;
    vector<long long> fl(3*N+1),fr(3*N+1);
    priority_queue<int,vector<int>,greater<>> pql;
    for (int i=1;i<=3*N;++i) {
        sum +=a[i];
        pql.push(a[i]);
        if (pql.size()>N) {
            sum-=pql.top();
            pql.pop();
        }
        fl[i] = sum;
    }
    sum = 0;
    priority_queue<int,vector<int>,less<>> pqr;
    for (int i=3*N;i>=1;--i) {
        sum +=a[i];
        pqr.push(a[i]);
        if (pqr.size()>N) {
            sum-=pqr.top();
            pqr.pop();
        }
        fr[i] = sum;
    }
    long long ans = -1e18;
    for (int i=N;i<=2*N;++i) {
        ans = max(ans,fl[i]-fr[i+1]);
    }
    cout << ans;
    return 0;
}