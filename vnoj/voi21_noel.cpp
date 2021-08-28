#include<bits/stdc++.h>
using namespace std;

int N,d;

int solve(vector<int> a,int bound) {
    int ans = 0;
    vector<vector<int>> f(2*N+1,vector<int>(2*N+1,0));
    f[0][0] = 1;
    //for (int i=0;i<=N;++i) f[0][i] = 1;
    for (int i=1;i<=bound;++i) {
        for (int j=bound+1;j<=2*N;++j) {
            if (abs(a[i]-a[j])<=d) f[i][j] = f[i-1][j-1] + 1;
            else if (abs(a[i]-a[j])>d) f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    for (int i=1;i<=2*N;++i) {
        for (int j=1;j<=2*N;++j) {
            ans = max(ans,f[i][j]);
        }
    }
    return ans;
}

int main() {
    //freopen("input.inp","r",stdin);
    int ans=0; cin >> N >> d; 
    vector<int> a(2*N+1,0);
    for (int i=1;i<=2*N;++i) {
        cin >> a[i];
    }
    //for (int i=0;i<=N;++i) cout << f[1][i] << ' ';
    int bound = 2,D=1;
    while (D<=N) {
        ans = max(ans,solve(a,bound));
        ++bound; ++D;
        //cout << bound << '\n';
    }
    //cout << bound << '\n';
    cout << ans;
    return 0;
}