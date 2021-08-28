#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.txt","r",stdin);
    #endif
    int t;
    int n;
    long long x;
    cin >> t;
    for (int i=1;i<=t;++i) {
        cin >> n >> x;
        vector<long long>a(n+1,0);
        for (int i1=1;i1<=n;++i1) {
            cin >> a[i1];
        }
        bool sta=true;
        for (int i1=1;i1<a.size()&&sta==true;++i1) {
            if (a[i1]%x==0) {
                for (int j=1;j<=x;++j)
                    a.push_back(a[i1]/x);
            } else sta=false;
        }
        long long Sum=0;
        for (int i1=1;i1<a.size();++i1) {
            Sum+=a[i1];
        }
        cout << Sum << '\n';
        a.clear();
    }
    return 0;
}
