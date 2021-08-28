#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    long long res=0;
    cin >> N;
    if (N%2==0) {
        for (int i1=1;2*i1<N;++i1) {
            for (int i2=N/2+1;i2<N;++i2) {
                int l = max(2*i1,2*i2-N)/2;
                int r = min(2*i2,2*i1+N)/2;
                res += ll(r-l-1);
            }
        }
    } else {
        for (int i1=1;2*i1<N;++i1) {
            for (int i2=N/2+1;i2<N;++i2) {
                int l = max(2*i1,2*i2-N-1)/2;
                int r = min(2*i2,2*i1+N+1)/2;
                res += ll(r-l-1);
                cout << l << ' ' << r << endl;
            }
        }
    }
    cout << res;
    return 0;
}
