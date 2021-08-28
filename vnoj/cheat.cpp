#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<int> prev(N+2),next(N+2);
    for (int i=1;i<=N;++i) {
        prev[i] = i+1; next[i] = i-1;
    }
    int last = 0;
    for (int i=0;i<N;++i) {
        int v; cin>>v;
        if (v!=next[last] && v<last) {puts("YES"); return 0;}
        next[prev[v]] = next[v];
        prev[next[v]] = prev[v];
        last = v;
    }
    puts("NO");
    return 0;
}