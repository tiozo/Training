#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define el '\n'

struct bit{
    int val;
    int index;
};

bool cmpBIT(bit left,bit right) {
    return (left.val<right.val);
}

const int MAXVAL=1e5;
void update(vector<int>&t,int p) {
    for (int i=p;i<=MAXVAL;i+=i&-i) {
        t[i]+=1;
    }
}

int Count(vector<int>&t,int p) {
    int res=0;
    for (int i=p;i;i-=i&-i) {
        res+=t[i];
    }
    return res;
}

int main() {
    int n,m;
    cin >> n;
    vector<int> a(1);
    vector<int> t(MAXVAL+1,0);
    vector<bit>b(1,{0,0});
    for (int i=1,tmp;i<=n;++i) {
        cin >> tmp;
        a.pb(tmp);
        b.pb({a[i],i});
    }
    sort(b.begin(),b.end(),cmpBIT);
    int tmp=b[0].val;
    for (int i=1;i<=n;++i) {
        if (b[i].val==tmp)  {
            tmp=b[i].val;
            b[i].val=b[i-1].val;
        }else {
            tmp=b[i].val;
            b[i].val=b[i-1].val+1;
        }
        a[b[i].index]=b[i].val;
    }
    for (int i=1;i<=n;++i) {
        cout << Count(t,a[i]-1) << el;
        update(t,a[i]);
    }

    return 0;
}
