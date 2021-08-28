#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,a,b,c;
    cin >> N >> a >> b >> c;
    vector<int> F(N+1,-1e10); F[0]=0;
    for (int i=a;i<=N;++i) F[i]=max(F[i],F[i-a]+1);
    for (int i=b;i<=N;++i) F[i]=max(F[i],F[i-b]+1);
    for (int i=c;i<=N;++i) F[i]=max(F[i],F[i-c]+1);
    cout << F[N];
    return 0;
}
