#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    char type; cin >> type;
    int res1 = 0,res2 = -1e6;
    vector<int> f(1,0);
    for (int i=-1000000;i<=0;++i) {
        if (i%33==0) {
            while (i<=0) {
                i+=33;
                f.push_back(i);
            }
            break;
        }
    }
    for (int i=33;i<=1000000;i+=33) {
        f.push_back(i);
    }
    for (int i=1;i<=f.size()-1;++i) {
        string tmp = to_string(f[i]);
        if (s.find(tmp)!=string::npos) {
            ++res1;
            res2 = max(res2,f[i]);
        }
    }
    if (type=='1') cout << res1;
    else {
        if (res2 == -1e6) cout << -1;
        else cout << res2;
    }
    return 0;
}