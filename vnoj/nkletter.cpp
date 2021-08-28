#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int N1 = s1.size();
    int res = N1;
    int N2 = s2.size();
    for (int i=0;i<N1;++i) {
        int t = 0;
        for (int j=i;j<N1;++j) {
            if (s1[j]!=s2[j-i]) {
                t = 1;
                break;
            }
        }
        if (!t) {
            res = i;
            break;
        }
    }
    cout << res+N2;
    return 0;
}