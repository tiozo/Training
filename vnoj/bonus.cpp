#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,k,maxval = 0;
    cin >> N >> k;
    vector<vector<int> > a(N+1,vector<int> (N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            int x;
            cin >> x;
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + x;
            if (i>=k && j>=k) maxval = max(maxval,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
        }
    }
    cout << maxval;
    return 0;
}
