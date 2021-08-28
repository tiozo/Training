#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> f(100001,0);
    vector<int> ans(100001,0);
    f[1]=1;
    ans[1]=1;
    for (int i=2;i<=100000;++i) {
        f[i]=f[i/2]+(i%2)*(f[i/2+1]);
        ans[i] = f[i] > ans[i-1] ? f[i] : ans[i-1];
    }
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << ans[N] << '\n';
    }
    return 0;
}