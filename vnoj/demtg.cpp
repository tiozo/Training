#include<iostream>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    long long ans = 0,step = 2;
    for (int i=1;i<=N;++i) {
        ans += step++;
    }
    ++ans;
    ans = ans*2+ans*(M-1);
    cout << ans;
    return 0;
}