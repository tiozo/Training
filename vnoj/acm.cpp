#include<bits/stdc++.h>
using namespace std;

const int maxval=4*1e7;

int main() {
    int N,res=0;
    int u1=0,u2=0;
    cin >> N;
    vector<pair<int,int> > a(2*N+1,{0,0});
    for (int i=1;i<=2*N;++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    vector<int> F(2*N+1,maxval);
    F[0]=0;
    F[1]=0;
    for (int i=1;i<=2*N;++i) {
        F[i]=(min(F[i-1],F[i])+min(a[i].first,a[i].second));
    }
    cout << F[2*N];
    return 0;
}
