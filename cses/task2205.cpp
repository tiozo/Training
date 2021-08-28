#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(), p.end()
int main() {
    int n; cin >> n;
    vector<int> a((1<<n)+1,0);
    for (int i=0;i<n;++i) {
        cout << 0;
    }
    cout << '\n';
    a[0] = 1;
    int x = 0;
    for (int i=1;i<(1<<n);++i) {
        for (int j=0;j<n;++j) {
            int y = x^(1<<j);
            if (!a[y]) {
                x = y;
                a[y] = 1;
                string s;
                while (y) {
                    if (y&1) s+='1';
                    else s+='0';
                    y>>=1;
                }
                reverse(all(s));
                for (int i=0;i<n-s.size();++i) {
                    cout << 0;
                }
                cout << s << '\n';
                break;
            }
        }
    }
    return 0;
}