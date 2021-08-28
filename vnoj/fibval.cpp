#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x{1, 2, 3, 5, 1, 6, 7, 6, 6, 5, 4, 2, 6, 1, 7, 1, 1, 2, 3, 5, 1, 6, 7, 6, 6, 5, 4, 2, 6, 1, 7, 1, 1, 2, 3, 5, 1, 6, 7, 6, 6, 5, 4, 2, 6, 1, 7, 1};
    int N,k; cin >> k;
    while (k--) {
        int u,v; cin >> u >> v;
        N=v-u;
        if (N>30) cout << ((N+1)/16)*16 << '\n';
        else {
            int t = (u-1)%16;
            bool flag = true;
            for (int i=t;i<t+N;++i) {
                if (x[i]==x[i+1]) {
                    cout << "2\n";
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "-1\n";
        }
    }
    return 0;
}