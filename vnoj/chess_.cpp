#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int res = 0,mx = 3;
        if (N%2==0) res = 0; else res = 3;
        if (res) cout << "White"; else cout << "Black";
        cout << '\n';
    }
    return 0;
}