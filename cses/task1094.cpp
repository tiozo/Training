#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=0; cin >> n;
    long long c = 0;
    vector<int> a(n);
    for (int &a:a) cin >> a;
    for (int i=1;i<n;++i) {
        if (a[i-1]>a[i]) {
            c += a[i-1]-a[i]; a[i]=a[i-1];
        }
    }
    cout << c;
    return 0;
}
