#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int res = 0,mx = 0;
        vector<int> a(1,0);
        int num = 0,K,Size = 0;
        cin >> K;
        string N;
        cin >> N;
        N=N+'0';
        for (int i=0;i<(int)N.size();++i) {
            if (N[i]=='0' && N[i-1]=='1') {
                ++Size;
                a.push_back(num);
                num = 0;
            }
            if (N[i]=='1') ++num;
        }
        for (int i=1;i<=Size;++i) {
            while (a[i]-K>=0) {
                res ^= a[i]-K;
                mx = max(mx,a[i]-K); 
                a[i]-=K;
            }
        }
        if ((mx<=1)!=(res==0)) cout << 2; else cout << 1;
        cout << '\n';
    }
    return 0;
}