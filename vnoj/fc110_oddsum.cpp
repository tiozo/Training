#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N,res=0; cin >> N;
    for (int i=1;i<=N;++i) {
        int x; cin >> x;
        if (i%2==0) res+=x;
    }
    cout << res;
    return 0;
}