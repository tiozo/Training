#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i=1;i<=T;i++) {
        long long a,b;
        cin >> a >> b;
        for (int k=40;k>=1;--k) {
            long long l=0,r=(long long)(pow(b,1.0/k)+10);
            while (l<r) {
                long long m = (l+r)/2;
                long long z = 1;
                for (int s=0;s<k;++s) {
                    z*=m;
                    if (z>=a) break;
                }
                if (z>=a) r=m;
                else l = m + 1;
            }
            long long z = 1;
            for (int s=0;s<k;++s) {
                z*=l;
                if (z>b) break;
            }
            if (a<=z && z<=b) {  
               cout << "Case #" << i << ": " << k << '\n'; 
               break;
            }
        }
    }
    return 0;
}