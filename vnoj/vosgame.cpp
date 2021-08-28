#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int genie_win=0,aladin_win=0;
        for (int i=1;i<=n;++i) {
            int x; cin >> x;
            if (x%3!=0 && x%2==0) ++aladin_win; else ++genie_win;
        }
        //cout << aladin_win << ' ' << genie_win << ' ';
        if ((genie_win<=n/2)!=(n%2==0)) cout << "Genie"; else cout << "Aladdin";
        cout << '\n'; 
    }
    return 0;
}

/* 
    if a[i] == 1 then aladin always win
    if a[i]%2 == 0 && a[i]%3 != 0then second player always win else first player win
    [][x][][o][][x] x win
    [x][o][x][o][x][][o][][x][][o][x] x win
    [][x][o][][x][o][x][o] o win
    overall x win
    if so_map %2 == 0 && genie_win > aladin_win genie win
*/