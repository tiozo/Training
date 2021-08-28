#include<bits/stdc++.h>
using namespace std;

template <typename Number>
Number GCD(Number u, Number v) {
    while (v != 0) {
        Number r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
    int N,coprime=0; cin >> N;
    for (int i=1;i<N;++i) {
        if (GCD<int>(i,N)==1) ++coprime;
    }
    cout << coprime << '\n';
    //cout << (N-1)+coprime;
    return 0;
}