#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define el '\n'

struct fractor{
    int tu;
    int mau;
};

int main() {
    int n,w;
    cin >> n >> w;
    vector<fractor> a;
    a.pb({0,0});
    for (int i=1;i<=n;++i) {
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        a.pb({tmp1,tmp2});
    }
    int st,ed;
    int Max=1;
    int res=0;
    for (int i=1;i<n;++i) {
        if (a[i].tu/a[i].mau<=a[i+1].tu/a[i+1].mau) {
            ++Max;
        } else Max=1;
        if (Max>res) {
            st=i-Max+2;
            ed=i+1;
            res=Max;
        }
    }
    if (w==0)
    cout << res;
    else {
        if (st>1 && ed<n) {
            if (a[st-1].mau/a[st-1].tu < a[st].tu/a[st].mau || a[ed].tu/a[ed].mau<a[ed+1].mau/a[ed+1].tu) ++res;
        }
        if (st==1 && ed>n) {
            if (a[ed+1].mau/a[ed+1].tu>a[ed].tu/a[ed].mau) ++res;
        }
        cout << res;
    }
    return 0;
}
