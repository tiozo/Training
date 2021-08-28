#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<long long> f(N,1);
    vector<long long> a(N);
    for (long long &a:a) cin >> a;
    sort(a.begin(),a.end());
    for (int i=1;i<N;++i) { 
        for (int j=0;j<i;++j) {
            long long v = a[i]-a[j];
            if (f[j]+1>f[i]) {
                if (binary_search(a.begin(),a.begin()+j,v) || binary_search(a.begin()+j+1,a.end(),v)) {
                    f[i] = f[j] + 1;
                }
            }
        }
    }
    cout << *max_element(f.begin(),f.end());
    return 0;
}