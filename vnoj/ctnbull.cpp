#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<long> a(N+1,0);
    a[0]=1;
    for (int i=1;i<=N;++i) {
        a[i]=(i>=K+1?a[i-1]+a[i-K-1]:(a[i-1]+1))%2111992;
    }
    cout << a[N];
    return 0;
}
