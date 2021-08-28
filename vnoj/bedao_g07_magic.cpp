#include<bits/stdc++.h>
using namespace std;

/// Largest Bit need to use is 30
const int LB = 30, mod = 1e9+7; 
int n,k,cur;
long long ans, pw[LB], inv[LB], f[LB+1][LB+1];
long long calc(int mask,int res) {
    if (k==0) {
        return 0;
    }
    for (int i = 0; i <= LB; i++) {
        for (int j = 0; j <= LB; j++) {
            f[i][j] = 0;
        }
    }
    long long tmp = pw[res];
    int top = 31 - __builtin_clz(mask);
    for (int i=top;i>=0;--i) {
        f[1][i] = pw[res];
    }
    for (int st = 2;st<=top+1 && st<=k ;++st) {
        for (int i=top+1-st;i>=0;--i) {
            if (((mask>>i)&1) || (i<res)) {
                f[st][i] = f[st-1][i+1] * pw[i] % mod;
                (f[st][i] *= inv[st-2])%=mod;
                if (i<res) {
                    (f[st][i] *= inv[1])%=mod;
                }
            }
            (f[st][i] += f[st][i+1]) %= mod;
        }
        (tmp+=f[st][0]) %= mod;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pw[0] = inv[0] = 1;
    for (int i=1;i<LB;++i) {
        pw[i] = pw[i-1]*2%mod;
        inv[i] = inv[i-1]*(mod+1)/2%mod;
    }
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> k;
        ++n; k=__lg(k);
        ans = 1;
        cur = 0;
        for (int i=LB-1;i>=0;--i) {
            if (n>>i&1) {
                if (cur==0) {
                    for (int j=0;j<i;++j) {
                        (ans+=calc(1<<j,j)) %= mod;
                    }
                } else {
                    (ans+=calc(cur,i)) %= mod;
                }
                cur ^= (1<<i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

///DPT O(tc*(logN))