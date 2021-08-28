#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N,mx=0; cin >> N;
    vector<int> a(N+1);
    vector<int> prefix(N+1);
    vector<int> suffix(N+1);
    prefix[0] = 0;
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        mx = max(mx,a[i]);
        prefix[i] = mx;   
    }
    mx = 0;
    for (int i=N;i>=1;--i) {
        mx = max(mx,a[i]);
        suffix[i] = mx;
    }
    long long sum = 0;
    for (int i=1;i<=N;++i) {
        sum += min(prefix[i],suffix[i])-a[i];
        cout << min(prefix[i],suffix[i])-a[i] << ' ';
    }
    cout << sum;
    return 0;
}