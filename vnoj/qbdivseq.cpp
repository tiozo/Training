#include<bits/stdc++.h>
using namespace std;

const int maxlabel=1e5;
vector<int> lds(maxlabel+1,0);
void LDS(vector<int> &a,int N) {
    vector<int> x(N+2,INT_MAX);
    x[0]=INT_MIN; int maxlength=0;
    for (int i=N;i>=1;--i) {
        int p = lower_bound(x.begin(),x.begin()+maxlength+1,a[i]) - x.begin();
        lds[i]=p;
        maxlength = max(maxlength,p);
        x[p] = min(a[i],x[p]);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    LDS(a,N);
    int res=0;
    for (int i=N;i>=1;--i) {
        res=max(res,lds[i]);
    }
    cout << res;
    return 0;
}
