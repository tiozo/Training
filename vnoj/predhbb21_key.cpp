#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i=1;i<=N;++i)
        {string s;
        cin >> s;
        int n = s.size();
        string t(s.rbegin(),s.rend());
        int Bst_L = 0, Bst_R = -1;
        for (int l = 0,r = 0;l<n;l=max(l,r)+1) {
            for (r = l - 1; r + 1 < n && s[r+1]==t[r+1]; ++r);
            if (Bst_R-Bst_L < r-l) {
                Bst_L = l;
                Bst_R = r;
            }
        }
        cout << s.substr(Bst_L, Bst_R - Bst_L + 1) << '\n';}
    return 0;
}