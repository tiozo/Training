#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        while(s[0]=='0') s.erase(s.begin());
        if (s.size()==0) {
            cout << -1 << '\n';
            continue;
        }
        while (s[s.size()-1]=='0') s.erase(s.begin()+s.size()-1);
        int res = 0;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='1' && s[i+1]=='0') {
                while (s[i+1]!='1') {
                    ++i; ++res;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}