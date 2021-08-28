#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
const int base = 37;
const int MOD = 1e9+7;
long long a[maxn],t[maxn],hasha[maxn],Pow[maxn];

long long gett(long long i,long long j) {
    return (((hasha[j]-hasha[i-1]*Pow[j-i+1])%MOD)+MOD)%MOD;
}

int main() {
    string s; cin >> s;
    int N = s.size();
    s=" "+s;
    Pow[0] = 1;
    for (int i=1;i<=N;++i) {
        Pow[i] = (Pow[i-1]*base)%MOD;
    }
    for (int i=1;i<=N;++i) {
        hasha[i] = (hasha[i-1]*base+s[i]-'a'+1)%MOD;
    }
    for (int i=1;i<=N;++i) {
        long long l=1,r=N-i+1,k=0;
        while (l<=r) {
            long long mid = (l+r)/2;
            if (gett(1,mid)==gett(i,i+mid-1)) {
                k = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        a[1]++; a[k+1]--;
    }
    for (int i=1;i<=N;++i) {
        t[i] = t[i-1] + a[i];
    }
    for (int i=1;i<=N;++i) {
        cout << t[i] << ' ';
    }
    return 0;
}