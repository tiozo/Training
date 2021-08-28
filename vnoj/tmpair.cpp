#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,res = 0; cin >> N;
    for (int i=1;i<=sqrt(N);++i) {
        if (N%i>0) continue;
        int a1 = i;
        int a2 = N/i;
        if (a1>1) {
            res += 1+(a1>2);
        }
        if (a1!=a2) {
            res+=2;
        }
    }
    /*for (int i=1;i<N;++i) {
        if ((N-i)%i==0 || i%(N-i)==0) res+=1;
        //cout << N-i << ' ' << i << '\n';
    }*/
    cout << res;
    return 0;
}

/* res is an odd number 

2 1
2 2 1
3 2 1 1
*/
const int a = 1000000;
const int e = 1e6;