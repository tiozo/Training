#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    int a,b,c,d;
    while (tc--) {
        cin >> a >> b >> c;
        //if (a<b) swap(a,b);
        int dis = abs(a-b);
        int tmp = 1+abs(a-b);
        if (tmp<c || (dis==1 && (a>2 || b>2))) {
            cout << "-1\n";
            continue;
        }
        bool check = false;
        for (int i=1;i<=tmp;++i) {
            if (i==a && i+dis==b) {
                check = true;
                break;
            }
            if (i==b && i+dis==a) {
                check = true;
                break;
            }
        }
        if (!check) {
            cout << "-1\n";
            continue;
        }
        if (c<tmp) c+=dis; else c-=dis;
        cout << c << '\n';
    }
    return 0;
}