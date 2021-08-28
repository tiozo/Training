#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (true) {
        cin >> s; if (s=="[END]") return 0;
        else {
            int N; cin >> N;
            if (N%5==0 || N%5==2) cout << "Hanako"; else cout << "Taro";
            cout << '\n';
        }
    }
    return 0;
}
/*
1 % 5 == 1
2 % 5 == 2
3 % 5 == 3
4 % 5 == 4
5 % 5 == 0
*/ 