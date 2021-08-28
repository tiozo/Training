#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,x,y=0,Max=0;
    cin >> N;
    vector<int> a(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> x;
        if (i>1)
            a[i-1]=x-y;
        y=x;
    }
    --N;
    vector<vi > F(N+1,vi(N+1,0));
    for (int i=1;i<=N-4;++i) {
        for (int j=i+4;j<=N;++j) {
            if(a[i] == a[j]) {
                  F[i][j] = min(F[i-1][j-1]+1,j-i-1);
            } else F[i][j]=0;
            Max=max(Max,F[i][j]);
        }
    }
    if (Max>=4)
        cout << Max+1;
    else cout << 0;
    return 0;
}
