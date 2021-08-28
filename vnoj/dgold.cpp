#include<bits/stdc++.h>
using namespace std;

const int N = 24, Maxval = 5*1e6+100;
int a[N], n;
pair<int,int> c1[Maxval],c2[Maxval];

void backtrack(int l,int r,pair<int,int> res[], int &c,int w1=0,int w2=0) {
    if (l==r) res[c++] = {w1-w2,w1+w2};
    else {
        backtrack(l+1,r,res,c,w1,w2);
        backtrack(l+1,r,res,c,w1+a[l],w2);
        backtrack(l+1,r,res,c,w1,w2+a[l]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> a[i];
    }
    int n1=0,n2=0;
    backtrack(0,n/2,c1,n1); backtrack(n/2,n,c2,n2);
    sort(c1,c1+n1); sort(c2,c2+n2);
    int res = 0;
    for (int i=0,j=n2-1;i<n1;++i) {
        while (j>0&& c1[i].first+c2[j].first>0) --j;
        if (c1[i].first+c2[j].first==0) {
            res = max(res,c1[i].second+c2[j].second);
        }
    }
    cout << res/2;
    return 0;
}