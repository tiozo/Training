#include<bits/stdc++.h>
using namespace std;

vector<int> LED(10);
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    LED[0] = 6; LED[1] = 2; LED [2] = 5; LED[3] = 5; LED[4] = 4; LED[5] = 5; LED[6] = 6; LED[7] = 3; LED[8] = 7; LED[9] = 6;
    int N,M; cin >> N >> M;
    vector<int> code(M);
    for (int &a:code) cin >> a;
    vector<int> trace(N+1,0);
    vector<int> f(N+1,0);
    f[0] = 0;
    for (int i=1;i<=N;++i) {
        f[i] = -1e9;
        for (int &j:code) {
            if (i==N && j==0 && N!=LED[0]) continue;
            if (i-LED[j]>=0 && f[i]<=f[i-LED[j]]+1) {
                f[i] = f[i-LED[j]]+1;
                trace[i] = j;
            }
        }
    }
    while (N) {
        cout << trace[N];
        N-=LED[trace[N]];
    }
    return 0;
}