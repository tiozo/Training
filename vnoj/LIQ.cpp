#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int N;
    cin >> N;
    vector<int> a(1001,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    vector<long long> F(1001,0);
    for (int i=1;i<=N;++i) {
        long long Max=0;
        for (int j=1;j<=i;++j) {
            if (a[i]>a[j]&&Max<F[j])
                Max=F[j];
        }
        F[i]=Max+1;
    } long long m=0;
    for (int i=1;i<=N;++i)
        m=max(F[i],m);
    cout << m;
    return 0;
}
