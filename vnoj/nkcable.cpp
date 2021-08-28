#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N+1,0); L[N]=1e6;
    for (int i=1;i<N;++i) {
        cin >> L[i];
    }
    vector<int> F(N+1,0);
    F[1]=L[1];
    for (int i=2;i<=N;++i) {
        F[i]=min(F[i-1]+L[i],F[i-2]+L[i-1]);
    }
    cout << F[N];
    return 0;
}
