#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,KQ = 0; cin >> N;
    vector<vector<int>> a(401,vector<int>(401,0));
    for (int i=1;i<=N;++i) {
        int u,v,c; cin >> u >> v >> c;
        a[u+200][v+200] = c;
    }
    for (int i=0;i<=400;++i) {
        for (int j=i+1;j<=400;++j) {
            int r1 = 0, r2 =0;
            for (int k=0;k<=400;++k) {
                if ((a[i][k]==1 && a[j][k]==4) || (a[i][k]==4 && a[j][k]==1)) ++r1;
                if ((a[i][k]==2 && a[j][k]==3) || (a[i][k]==3 && a[j][k]==2)) ++r2;
            }
            KQ += r1*r2;
            r1 = r2 = 0;
            for (int k=0;k<=400;++k) {
                if ((a[i][k]==1 && a[j][k]==2) || (a[i][k]==2 && a[j][k]==1)) ++r1;
                if ((a[i][k]==4 && a[j][k]==3) || (a[i][k]==3 && a[j][k]==4)) ++r2;
            }
            KQ += r1*r2;
            r1 = r2 = 0;
            for (int k=0;k<=400;++k) {
                if ((a[i][k]==1 && a[j][k]==3) || (a[i][k]==3 && a[j][k]==1)) ++r1;
                if ((a[i][k]==4 && a[j][k]==2) || (a[i][k]==2 && a[j][k]==4)) ++r2;
            }
            KQ += r1*r2;
        }
    }
    cout << KQ;
    return 0;
}