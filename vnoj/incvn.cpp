#include<bits/stdc++.h>
using namespace std;

const int MOD=5000000;
const int maxlabel=100000;
vector<int> T(maxlabel+1,0);

void update(int label,int val) {
    for (int i=label;i<=maxlabel;i+=i&-i) {
        T[i]=(T[i]+val)%MOD;
    }
}

int querry(int label) {
    long long res=0;
    for (int i=label;i>0; i-=i&-i) {
        res+=T[i];
    }
    return res%MOD;
}

int main() {
    int N,K;
    long long ans=0;
    cin >> N >> K;
    vector<int> a(N+1,0);
    vector<int> inc(N+1,1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        ++a[i];
    }
    for (int l=2;l<=K;++l) {
        fill(T.begin(),T.end(),0);
        for (int i=1;i<=N;++i) {
            update(a[i],inc[i]);
            inc[i]=querry(a[i]-1);
        }
    }
    for (int i=1;i<=N;++i) {
        ans+=inc[i];
    }
    cout << int(ans%MOD);
    return 0;
}
