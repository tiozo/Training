#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,k;
    cin >> N >> k;
    queue<int> q; q.push(N);
    int res = 0;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        if ((tmp+k)%2 || tmp<=k) ++ res;
        else {
            q.push((tmp+k)/2); q.push((tmp-k)/2);
        }
    }
    cout << res;
    return 0;
}