#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n;
    while (n!=1) {
        if (n%2==0) n/=2;
        else n=n*3+1;
        cout << n << ' ';
    }
    return 0;
}