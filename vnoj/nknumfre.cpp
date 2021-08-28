#include<iostream>
#include<cmath>
using namespace std;

int rev(int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n%10;
        n/=10;
    }
    return res;
}

int gcd(int a,int b) {
    return (b==0) ? a : gcd(b,a%b);
}

int main() {
    int a,b,res = 0;
    cin >> a >> b;
    for (;a<=b;++a) {
        if (gcd(a,rev(a))==1) ++res;
    }
    cout << res;
    return 0;
}