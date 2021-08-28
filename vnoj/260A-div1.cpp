#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,v=1;
    cin >> N;
    vector<int> a(N+1,0);
    vector<int> b(N+1,0);
    vector<int> presum(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i=1;i<=N;++i) {
        if (a[i]!=a[i-1] && i>1) ++v;
        presum[v]+=a[i];
        b[v]=a[i];
    }
    b.resize(v);
    presum.resize(v);
    vector<int> F(v+1,0);
    F[1]=presum[1];
    for (int i=2;i<=v;++i) {
        F[i]=max(F[i-1],F[i-2]+presum[i]);
    }
    cout << F[v];
    return 0;
}

///  0 1 2 3 4 5 6
///      |
///  0 1
/// F[i]=
/// minh co 2 thao tac la buoc va xoa
/// neu xoa thi F[i]=a[k] a[k-1] -> a[k+1]=0
/// neu buoc thi F[i]=F[i-1]+a[k];
