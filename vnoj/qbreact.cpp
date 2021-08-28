#include<bits/stdc++.h>
using namespace std;

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int M,N,result = 0;
    cin >> M >> N;
    vector<int>h(N+1,0);
    vector<int>l(N+1,0);
    vector<int>r(N+1,0);
    for (int i=1;i<=M;++i) {
        for (int j=1;j<=N;++j) {
            int x; cin >> x;
            h[j] = (x) ? h[j] + 1 : 0; 
        }
        for (int j=1;j<=N;++j) {
            int t = j-1;
            while (t>=1 && h[t]>=h[j]) t=l[t];
            l[j] = t;
        }
        for (int j=N;j>=1;--j) {
            int t = j+1;
            while (t<=N && h[t]>=h[j]) t = r[t];
            r[j] = t;
            result = max(result,h[j] * (r[j]-l[j]-1));
        }
    }
    cout << result;
}