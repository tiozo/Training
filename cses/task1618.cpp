#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ans=0;
    for (int i=5;i<=n;i*=5) {
        ans += n/i;
    }
    cout << ans;
    return 0;
}