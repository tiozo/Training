#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N,ans = 0; cin >> N;
    for (long long x=1;x<=N;x*=2) ans = max(ans,x);
    for (long long x=3;x<=N;x*=2) ans = max(ans,x);
    cout << N-ans;
    return 0;
}