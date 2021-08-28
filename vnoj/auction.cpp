#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> a(M+1,0);
    for (int i=1;i<=M;++i) {
        cin >> a[i];
    }
    int res = 0,price = 0;
    sort(a.begin()+1,a.end());
    for (int i=M;i>=M-(min(N,M))+1;--i) {
        if (res < (M-i+1)*a[i]) {
            res = (M-i+1)*a[i];
            price = a[i];
        }
    }
    cout << price << ' ' << res << '\n';
    return 0;
}