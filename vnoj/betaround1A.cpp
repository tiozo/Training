#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a,n,m; cin >> n >> m >> a;
    cout << ((m+a-1)/a)*((n+a-1)/a);
    return 0;
}