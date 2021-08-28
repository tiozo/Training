#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int spf[maxn];
void sieve(int n) {
    for (int i=1;i<=n;++i) {
        spf[i] = i;
    }
    for (int p=2;p*p<=n;++p) {
        if (spf[p]==p) {
            for (int i=p*p;i<=n;i+=p) {
                if (spf[i]==i) spf[i]=p;
            }
        }
    }
}

void solve() {
    int x; cin >> x;
    int ans = 1;
    while (x!=1) {
        int y = spf[x];
        int c = 1;
        while (x%y==0) {
            c++; x/=y;
        }
        ans*=c;
    }
    cout << ans << '\n';
}

int main() {
    sieve(1e6);
    int n; cin >> n;
    while (n--) {
        solve();
        //cout << '\n';
    }
    return 0;
}