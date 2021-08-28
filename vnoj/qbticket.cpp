#include<bits/stdc++.h>
using namespace std;

const int oo=1e18;

int main() {
    vector<int> L(4,0),C(4,0),p(4,0);
    cin >> L[1] >> L[2] >> L[3] >> C[1] >> C[2] >> C[3];
    int N,s,f;
    cin >> N >> s >> f;
    if (s>f) swap(s,f);
    vector<long long> a(N+1,0);
    for (int i=2;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=3;++i) {
        p[i]=s;
    }
    vector<long long> F(N+1);
    for (int i=s+1;i<=f;++i) {
        F[i]=oo;
        for (int j=3;j>=1;--j) {
            while (a[i]-a[p[j]] > L[j]) ++p[j];
            F[i]=min(F[i],F[p[j]]+C[j]);
            p[j-1]=p[j];
        }
    }
    cout << F[f];
    return 0;
}
