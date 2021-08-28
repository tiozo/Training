#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<int,int> m;
    for (int i=1;i<=N;++i) {
        int x,y; cin >> x >> y;
        map[x] = y;
    }
    return 0;
}