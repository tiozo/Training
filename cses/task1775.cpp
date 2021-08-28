#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()
int main() {
    string s;
    cin >> s;
    int c[26] = {}, c1=0;
    for (char d:s) {
        ++c[d-'A'];
    }
    for (int i=0;i<26;++i) {
        c1+=c[i]&1;
    }
    if (c1>1) cout << "NO SOLUTION";
    else {
        string t;
        for (int i=0;i<26;++i) {
            if (c[i]&1^1) {
                for (int j=0;j<c[i]/2;++j) {
                    t += (char)('A'+i);
                }
            }
        }
        cout << t;
        for (int i=0;i<26;++i) {
            if (c[i]&1) {
                for (int j=0;j<c[i];++j) {
                    cout << char('A'+i);
                }
            }
        }
        reverse(all(t));
        cout << t;
    }
    return 0;
}