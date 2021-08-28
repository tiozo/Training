///De Olympic Chuyen KHTN 2014
#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main() {
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    while (N!=0) {
        for (int i=1;i<N;++i) {
            a[i]=a[i]+a[i+1];
        }
        --N;
        for (int i=1;i<N;++i) {
            a[i]=a[i]*a[i+1];
        }
        --N;
    }
    cout << a[1]%mod;
    return 0;
}
