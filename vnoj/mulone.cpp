#include<bits/stdc++.h>
using namespace std;

char res [2000000];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        int memo = 0, p = N+N-2;
        for (int i=1;i<=N;++i,--p) {
            memo += i;
            res[p] = memo % 10 + 0x30;
            memo /= 10;
        }
        for (int i=N-1;i>0;--i,--p) {
            memo += i;
            res[p] = memo % 10 + 0x30;
            memo /= 10;
        }
        if (memo) cout << memo << ' ';
        res[N+N-1] = 0; cout << res << '\n';
    }
    return 0;
}