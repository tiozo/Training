#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        vector<int> a(12);
        for (int &a:a) cin >> a;
        sort(a.begin(),a.end());
        if (!a.back()) break;
        cout << ((a[0]==a[3] && a[4]==a[7] && a[8]==a[11]) ? "yes\n" : "no\n");
    }
    return 0;
}