#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> c(n+1,0);
    for (int i=1;i<n;++i) {
        int x; cin >> x;
        c[x] = 1;
    }
    for (int i=1;i<=n;++i) {
        if (!c[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}