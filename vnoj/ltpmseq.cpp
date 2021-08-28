#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string,int> m;
    string res = "-1";
    int N; cin >> N;
    for (int i=1;i<=N;++i) {
        string s; cin >> s;
        m[s]++;
    }
    for (auto &a:m) {
        if (a.second%2) {
            res = a.first;
            break;
        }
    }
    cout << res;
    return 0;
}