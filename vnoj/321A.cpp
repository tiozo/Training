#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,res=1;
    cin >> N;
    vector<int> a(N+1,0);
    vector<int> b(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    vector<int> F(N+1,0);
    int k=1;
    for (int i=1;i<N;i=i+k) {
        F[i]=1;
        int tmp=a[i];
        for (int j=i+1;j<=N;++j) {
            if (tmp<=a[j] && b[j]==0) {
                b[j]=1;
                tmp=a[j];
                ++F[i];
            } else if (tmp>a[j]) {
                break;
            }
        }
        res=max(res,F[i]);
        k=F[i];
    }
    cout << res;
    return 0;
}
