#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N+1,0),r(N+1,0),F(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> t[i];
    }
    for (int i=1;i<N;++i) {
        cin >> r[i];
    }
    F[1]=t[1];
    F[2]=min(t[1]+t[2],r[1]);
    for (int i=3;i<=N;++i) {
        F[i]=min(F[i-1]+t[i],F[i-2]+r[i-1]);
    }
    cout << F[N];
    return 0;
}
