#include<bits/stdc++.h>
using namespace std;

struct uvc {
    int x,y;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<uvc> a(N+1,{0,0});
    for (int i=1;i<=N;++i) {
        cin >> a[i].x >> a[i].y;
    }
    vector<int> F(N+1,0);
    for (int i=1;i<=N;++i) {
        if (i%2==0) F[i/2]=F[i/2-1]+a[i].x;
        for (int j=(i-1) >> 1; j>=1;--j) {
            F[j] = min(F[j-1]+a[i].x,F[j]+a[i].y);
        }
        F[0] = F[0]+a[i].y;
    }
    cout << F[N>>1];
    return 0;
}