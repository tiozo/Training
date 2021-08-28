#include<bits/stdc++.h>
using namespace std;


struct bit{
    int ai;
    int hi;
    int index;
};

bool cmp(bit left,bit right) {
    if (left.ai==right.ai) {
        return left.hi<right.hi;
    }
    return left.ai<right.ai;
}

const int MAXVAL=1e5;
void update(vector<int>&t,int p) {
    for (int i=p;i<=MAXVAL;i+=i&-i) {
        ++t[i];
    }
}

int Count(vector<int>&t,int p) {
    int res=0;
    for (int i=p;i;i-=i&-i) {
        res+=t[i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> ans(n+1,0);
    vector<bit> a(n+1,{0,0,0});
    vector<int> t(MAXVAL+1,0);

    int ai,hi;
    for (int i=1;i<=n;++i) {
        cin >> a[i].ai >> a[i].hi;
        a[i].index = i;
    }
    sort(a.begin(),a.end(),cmp);

    for (int i=1;i<=n;++i) {
        if (i!=1&&a[i].hi==a[i-1].hi && a[i].ai == a[i-1].ai) {
            ans[a[i].index]=ans[a[i-1].index];
        } else ans[a[i].index]=Count(t,a[i].hi);
        update(t,a[i].hi);
    }
    for (int i=1;i<=n;++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
