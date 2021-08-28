#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int N,x; cin >> N >> x;
        double long r1=0; double long r2=0;
        vector<double long> a(N+1,0);
        for (int i=1;i<=N;++i) {
            cin >> a[i];
            r1+=(double long)a[i];
            r2+=(double long)ceil(a[i]/x);
        }
        r1 = (double long)ceil(r1/x);
        cout << (long long)r1 << ' ' << (long long)r2 << '\n';
    }
    return 0;
}