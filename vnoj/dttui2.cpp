#include<bits/stdc++.h>
using namespace std;

struct pack {
    int w,v,a;
};

const int maxn = 1000;
int f[maxn+1][maxn+1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M,res = 0;
    cin >> N >> M;
    vector<pack> a(N+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i].w >> a[i].v >> a[i].a;
    }
    f[0][0] = 0;
    for (int j=1;j<=M;++j) {
        f[0][j] = -1;
    }
    int maximal = 0;
    for (int i=1;i<=N;++i) {
        maximal = 0;
        for (int j=1;j<=M;++j) {
            if (f[i-1][j]>=0)
                f[i][j] = 0;
            else if (f[i][j-a[i].w]>=0 && f[i][j-a[i].w]<a[i].a) {
                f[i][j] = f[i][j-a[i].w] + 1;
            } else {
                f[i][j] = -1;
            }
            maximal = max(maximal,f[i][j]);
        }
        //cout << maximal << ' ' << a[i].v << '\n';  
        res += a[i].v * maximal;
    }
    cout << res;
    return 0; 
}