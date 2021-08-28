#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,K;
    cin >> N >> K;
    long long res = 0,s = 0;
    vector<int> a(N+1,0);
    vector<vector<long long>> f(N+1,vector<long long>((1<<N)+1,0));
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=N;++i) f[i][1<<(i-1)] = 1;
    for (int j=1;j<(1<<N);++j) {
        for (int i1=1;i1<=N;++i1) {
            if (j&(1<<(i1-1))) {
                for (int i2=1;i2<=N;++i2) {
                    if (j&(1<<(i2-1)) && abs(a[i2]-a[i1])>K && i1!=i2) {
                        f[i1][j] += f[i2][j^(1<<(i1-1))];
                    }
                }
            }
        }
    }
    for (int i=1;i<=N;++i) res += f[i][(1<<N)-1];
    cout << res;
    return 0;
}