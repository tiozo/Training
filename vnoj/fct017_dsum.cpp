#include<bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0;
    string s; cin >> s;
    for (int i=0;i<s.length();++i) {
        sum += (s[i]-48);
    }
    cout << sum;
    return 0;
}