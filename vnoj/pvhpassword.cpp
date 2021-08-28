#include<bits/stdc++.h>
using namespace std;

const int limit = 25;
vector<int> a(27,0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    string s;
    cin >> s >> a[1];
    for (int i=2;i<=26;++i) {
        a[i] = (a[i-1]+1)%26;
    }
    int res = 0;
    for (int i=0;i<s.size();++i) {
        res += a[s[i]-96];
    }
    cout << res;
    return 0;
}