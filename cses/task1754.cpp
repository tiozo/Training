#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b; cin >> a >> b;
    long long res = 1;
    cout << ((a+b)%3==0&&2*a>=b&&2*b>=a?"YES\n":"No\n");
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}