#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;

main() {
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int m,n;
    cin >> m >> n;
    vector<vi > a(m+2,vi(n+2,0));
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) {
            cin >> a[i][j];
        }
    }
    vector<vi > F(m+2,vi(n+2,0));
    for (int i=1;i<=n;++i) {
        F[0][i]=-10000; F[m+1][i]=-10000;
    }
    for (int i=1;i<=m;++i) {
        F[i][1]=a[i][1];
    }
    int tmp=0;
    for (int j=2;j<=n;++j) {
        for (int i=1;i<=m;++i) {
            tmp=max(F[i][j-1],F[i-1][j-1]);
            tmp=max(tmp,F[i+1][j-1]);
            F[i][j]=tmp+a[i][j];
        }
    }
    int t=-10000;
    for (int i=1;i<=m;++i)
        t=max(t,F[i][n]);
    cout << t;
}
