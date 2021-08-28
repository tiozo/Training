#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,C; cin >> N >> C;
    map<int,int> diff;
    vector<int> p(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> p[i];
        if (p[i]!=i) {
            diff[i] = p[i];
        }
    }
    for (int i=1;i<=C;++i) {
        int x,y; cin >> x >> y;
        swap(p[x],p[y]);
        if (p[x]!=x) diff[x] = p[x]; else diff.erase(x);
        if (p[y]!=y) diff[y] = p[y]; else diff.erase(y);
        cout << diff.size()-1 << '\n';
    }
    return 0;
}