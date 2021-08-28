#include<bits/stdc++.h>
using namespace std;

const int mod=14062008;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> F(N+1,0),steps(N+1,0);
    for (int i=1;i<=K;++i) {
        int tmp1;
        cin >> tmp1;
        steps[tmp1]=1;
    }
    F[0]=0;
    F[1]=1;
    for (int i=2;i<=N;++i) {
        F[i]=steps[i] ? 0 : ((F[i-1]+F[i-2])%mod);
    }
    cout << F[N];
    return 0;
}
