#include<bits/stdc++.h>
using namespace std;

int check(int k) {
    int N = (int)sqrt(2*k);
    //cout << N << ' ';
    if (N*(N+1)/2==k) {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,seq = 0, res = 0; cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;++i)  {
        cin >> a[i];
        if (check(a[i])) {
            if (a[i]>=a[i-1]) {
                ++seq;
            } else seq = 1;
        } else seq = 0;
        res = max(res,seq);
        //cout << check(a[i]) << ' ';
    }
    cout << res;
    return 0;
}