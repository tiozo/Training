#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int N; cin >> N;
        vector<int> a(N+1);
        vector<int> ans(N+1,-1);
        vector<int> f(N+1,0);
        vector<int> last(N+1,0);
        for (int i=1;i<=N;++i) {
            cin >> a[i];
        } 
        for (int i=1;i<=N;++i) {
            f[a[i]] = max(f[a[i]],i-last[a[i]]);
            last[a[i]] = i;
        }
        for (int i=1;i<=N;++i) {
            f[i] = max(f[i],N-last[i]+1);
        }
        for (int i=1;i<=N;++i) {
            for (int j=f[i];j<=N;++j) {
                if (ans[j]==-1) ans[j] = i; else break;
            }
        }
        for (int i=1;i<=N;++i) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}