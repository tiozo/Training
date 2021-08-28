#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n,d;
int a[N+1];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> d;
        for (int i=1;i<=d;++i) cin >> a[i];
        for (int i=d+1;i<=d+1;++i) {
            int x = 0;
            for (int j = i - 1; j >= i - d; --j)
                x ^= a[j];
            a[i] = x;
        }
        int one = 0;
        for (int i=1;i<=d+1;++i) one^=a[i]==1;
        int loop = d+1;
        int cnt = n/loop;
        if (!cnt%2) one = 0;
        int mod = n%loop;
        if (mod) {
            for (int i=1;i<=mod;++i) 
                one ^= a[i]==1;
        }
        cout << one << '\n';
    }
    return 0;
}