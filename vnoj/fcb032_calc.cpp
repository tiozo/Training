#include<iostream>
using namespace std;

int a[3];
char check() {
    for (int i:a) {
        for (int j:a) {
            for (int k:a) {
                if (i+j==k) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> a[0] >> a[1] >> a[2]) {
        if (check()) cout << "yes\n"; else cout << "no\n";
    }
}