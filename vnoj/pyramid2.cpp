#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; string s;
    cin >> N >> s;
    int res = 0, delay = 0, cnt = 0,i;
    for (i=0;i<N && s[i] == '<';++i) {}
    for (;i<N;++i) {
        if (s[i] == '<') {
            res = max(res,delay++ + cnt);
        } else {
            ++cnt;
            if (delay > 0) --delay;
        }
    }
    cout << res;
    return 0;
}