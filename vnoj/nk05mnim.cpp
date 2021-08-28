#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int N,res=0,mx=0; cin >> N;
        for (int i=1;i<=N;++i) {
            int tmp; cin >> tmp;
            res ^= tmp;
            mx = max(mx,tmp);
        }
        if ((mx<=1)!=(res==0)) cout << -1; else cout << 1;
        cout << '\n';
    }  
    return 0;
}