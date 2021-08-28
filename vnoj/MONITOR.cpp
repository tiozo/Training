#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define el endl
typedef long long ll;

struct id {
    ll val;
    ll index;
};

bool cmp(id left,id right) {
    if (left.val==right.val) {
        return left.index<right.index;
    }
    return left.val<right.val;
}

int main() {
    freopen("input.inp","r",stdin);
    int n;
    vector<id> a(1,{0,0});
    cin >> n;
    ll tmp;
    for (int i=1;i<=n;++i) {
        cin >> tmp;
        a.pb({tmp,i});
    }
    sort(a.begin(),a.end(),cmp);
    id maxid;
    maxid.val=0;
    maxid.index=0;
    for (int i=1;i<=n;++i) {
        ll tmp; int j=i+1;
        while (a[i].val==a[j].val) {
            tmp=a[j].index-a[i].index+1;
            if (j<n)
            ++j;
        }
        if (maxid.val<tmp) {
            maxid.val=max(maxid.val,tmp);
            maxid.index=a[i].val;
        }
    }
    cout << maxid.index << el << maxid.val;
    return 0;
}
