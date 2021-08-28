#include<bits/stdc++.h>
using namespace std;

const int maxval = 1e6;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int K,L,M;
    cin >> K >> L >> M;
    vector<int> F(maxval+1,0);
    for (int i=1;i<=maxval;++i) {
        F[i] = !(i-1>=0 ? F[i-1] : 1) || !(i-K>=0 ? F[i-K] : 1) || !(i-L>=0 ? F[i-L] : 1);
    }
    while (M--) {
        int N;
        cin >> N;
        if (N<=L || N<=K) cout << "A";
        else cout << (F[N] ? "A":"B");
    }
    return 0;
}