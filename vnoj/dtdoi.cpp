#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long S;
    int N,Max=0,res=0;
    cin >> N >> S;
    vector<int> a(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        Max=max(a[i],Max);
    }
    while (S>10000) {
        int d=(S-10000)/Max+1;
        S-=d*Max;
        res+=d;
    }
    vector<long long> F(S+1,10000);
    F[0]=0;
    for (int i=1;i<=S;++i) {
        for (int j=1;j<=N;++j) {
            if (i>=a[j] && F[i]>F[i-a[j]]+1)
                F[i]=F[i-a[j]]+1;
        }
    }
    cout << res+F[S];
    return 0;
}
