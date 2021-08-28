#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<int> a(N+1);
    vector<int> f(N+1);
    vector<int> prefix(30,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=N;++i) {
        if (i==1) {
            f[i] = 1;
        } else {
            for (int j=0;j<30;++j) {
                if (((a[i]>>j)&1)) {
                    f[i] = (f[i]+prefix[j]) % mod;
                }
            }
        }
        for (int j=0;j<30;++j) {
            if ((a[i]>>j)&1) {
                prefix[j] = (prefix[j]+f[i]) % mod;
            }
        }
    }
    cout << f[N];
    return 0;
}