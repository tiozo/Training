#include<bits/stdc++.h>
using namespace std;

int pow_m(int a,int N) {
    if(!N) return 1;
    int res = pow_m(a,N/2);
    return N%2 ? res*res * a % 29 : res*res%29;
}

int main() {
    int x;
    while (cin >> x && x!=0) {
        cout << ((pow_m(2,x+x+1)-1)*(pow_m(3,x+1)-1)*(pow_m(2,29-2))*(pow_m(167,x+1)-1)*(pow_m(166,29-2)))%29;
        cout << '\n';
    }
    return 0;
}