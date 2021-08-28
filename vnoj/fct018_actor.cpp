#include<bits/stdc++.h>
using namespace std;

int main() {
    int r; cin >> r;
    int tc; cin >> tc;
    while (tc--) {
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int ans;
        if (r==1) {
            int max_unqualify = (n-a) + (n-b) + (n-c);
            ans = max(0,n-max_unqualify); 
        } else {
            ans = min({a,b,c});
        }
        cout << ans << '\n';
    }
    return 0;
}