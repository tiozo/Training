#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p(1,0);
    int i = 1;
    while (p.size()<=1000) {
        string s = to_string(i);
        if (i%3==0 || *s.rbegin()=='3') {
            ++i;
            continue;
        }
        //if (s.find('3')==s.size()) continue;
        p.push_back(i);
        i++;
        //cout << s << '\n';
    }
    string s = "13";
    //cout << (*s.rbegin()=='3') << '\n';
    int tc; cin >> tc;
    while (tc--) {
        int k; cin >> k;
        //--k;
        cout << p[k] << '\n';
    }
    return 0;
}