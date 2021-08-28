#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6;
struct Type {
    int d,h,id;
} x[maxn+1];

int ans[maxn+1],it[maxn];

bool cmp(const Type&a,const Type&b) {
    return (a.d!=b.d?a.d<b.d:a.h>b.h);
}

void update(int id,int l,int r,int pos,int val) {
    if (pos<l || pos>r) return;
    if (l==r) {
        it[id] = max(it[id],val);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    it[id] = max(it[id*2],it[id*2+1]);
}

int query(int id,int l,int r,int u,int v) {
    if (v<l || r<u) return 0;
    if (u<=l && r<=v) {
        return it[id];
    } 
    int mid=(l+r)/2;
    return max(query(id*2,l,mid,u,v),query(id*2+1,mid+1,r,u,v));
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> x[i].d >> x[i].h;
        x[i].id=i;
    }
    sort(x+1,x+1+n,cmp);
    for (int i=1;i<=n;++i) {
        int a = x[i].d;
        int j=i;
        while (j<=n&&x[j].d==a) {
            ans[x[j].id] = query(1,1,30000,x[j].h+1,30000)+1;
            j++;
        }
        j=i;
        while (j<=n && x[j].d==a) {
            update(1,1,30000,x[j].h,ans[x[j].id]);
            j++;
        }
        i = j-1;
    }
    for (int i=1;i<=n;++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}