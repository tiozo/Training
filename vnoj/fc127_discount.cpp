#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+9;
const int K = 1e5+5;
vector<long long> s(K);

long long power(long long a,int N) {
    long long tmp = a, ans =1;
    while (N>0) {
        if (N&1) ans = ans * tmp % MOD;
        tmp = tmp * tmp % MOD;
        N>>=1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        long long N,a,b,k;
        cin >> N >> a >> b >> k;
        for (int i=0;i<k;++i) cin >> s[i];
        long long A = 0;
        for (int i=0;i<k;++i) A=(A+s[i]*power(a,N-i)%MOD*power(b,i)%MOD+MOD)%MOD;
        long long B = 0;
        long long x = power(b*power(a,MOD-2)%MOD,k);
        long long p = (power(x,(N+1)/k)-1+MOD)%MOD;
        long long q = power((x-1+MOD)%MOD,MOD-2);
        B = q > 0 ? p*q % MOD : (N+1)/k;
        cout << A*B%MOD << '\n';
    }
    return 0;
}