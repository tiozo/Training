#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,K; cin >> N >> K;
    for (int i=1;i<N-K;++i) {
        cout << i << " ";
    }
    for (int i=0;i<=K;++i) {
        cout << ((i&1)?(N-i/2) : (N-K+i/2)) << " \n"[i==K];
    }
    return 0;
}