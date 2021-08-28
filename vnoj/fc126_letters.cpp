#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string s; cin >> s;
    //vector<int> f(N,0);
    if (s[0]=='?') s[0] = 'a';
    if (s[N-1]=='?') s[N-1] = 'b';
    --N;
    cout << s[N]-s[0];
    return 0;
}