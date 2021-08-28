#include<bits/stdc++.h>
using namespace std;

vector<bool> Prime(200005,1);
void SOE(int N) {
    Prime[0]=0;
    Prime[1]=0;
    for (int p=2;p*p<=N;++p) {
        if (Prime[p]) {
             for (int i = p * p; i <= N; i += p)
                Prime[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b;
    cin >> a >> b;
    SOE(b);
    for (int i=a;i<=b;++i) {
        if (Prime[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}
