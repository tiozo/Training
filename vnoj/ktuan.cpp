#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9;

int main() {
    int N,res,sign;
    cin >> N;
    vector<int> F(N+1,0);
    F[0] = 1;
    F[1] = 1;
    for (int i=2;i<=N;++i) {
        res = 0;
        sign = 1;
        for (int t=1;;++t) {
            int k = t*(3*t-1)/2;
            if (k>i) break;
            res = (res+sign*F[i-k])%mod;
            if (res<0) res+=mod;
            k+=t;
            if (k>i) break;
            res = (res+sign*F[i-k])%mod;
            if (res<0) res+=mod;
            sign = -sign;
        }
        F[i] = res;
    }
    cout << (N==0?0:F[N]);
    return 0;
}