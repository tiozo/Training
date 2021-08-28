#include<bits/stdc++.h>
using namespace std;

const int maxlabel=20000;
vector<int> lds(maxlabel+1,0);
void LDS(vector<int> &a,int N) {
    vector<int> x(N+2,INT_MAX);
    x[0]=INT_MIN; int maxlen=0;
    for (int i=N;i>=1;--i) {
        int p = lower_bound(x.begin(),x.begin()+maxlen+1,a[i]) - x.begin();
        lds[i]=p;
        maxlen=max(p,maxlen);
        x[p]=min(x[p],a[i]);
    }
}

int main() {
    int T,N;
    cin >> T;
    while (T--) {
        cin >> N;
        N*=2;
        vector<int> a(N+1,0);
        for (int i=1;i<=N;++i) {
            cin >> a[i];
        }
        LDS(a,N);
        int res=0;
        for (int i=1;i<=N;++i) {
            res=max(res,lds[i]);
        }
        cout << res << '\n';
    }
    return 0;
}
