#include<bits/stdc++.h>
using namespace std;
#define p first
#define k second

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long N;
    cin >> N;
    vector<pair<long,long> > a(N+1,{0,0});
    vector<long> F(N+1,0);
    for (long i=1;i<=N;++i) {
        cin >> a[i].p >> a[i].k;
    }
    sort(a.begin(),a.end());
    int Max=0;
    F[1]=a[1].k-a[1].p;
    for (long i=2;i<=N;++i) {
        Max=0;
        F[i]=a[i].k-a[i].p;
        for (int j=1;j<i;++j) {
            if (a[j].k<=a[i].p && F[j]>Max) {
                Max=F[j];
            }
        }
        F[i]+=Max;
    }
    long res=0;
    for (long i=1;i<=N;++i) {
        res=max(res,F[i]);
    }
    cout << res;
    return 0;
}
