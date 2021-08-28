#include<bits/stdc++.h>
using namespace std;

int main() {
    int M,N; cin >> M >> N;
    vector<string> s(M);
    for (auto &e:s) {
        cin >> e;
    }
    for (int i=1;i<=M;++i) {
        bool filled = false;
        string tmp; cin >> tmp;
        for (auto &e:s) {
            if (filled) break;
            for (int j=0;j<N;++j) {
                if (e[j]!='0') 
            }
        }
    }
    for (auto &e:s) {
        cout << e << '\n';
    }
    return 0;
}