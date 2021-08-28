#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = " abcdefghijklmnopqrstuvwxyz";
    int a;
    cin >> a;
    if (a <= s.size())
        cout << s[a];
    return 0;
}