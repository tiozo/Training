#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const long long maxc = 1e18;
int N; 
long long st[maxn+1],New[maxn+1],x[maxn+1],e[maxn+1],W[maxn+1],f[maxn+1];
pair<long long,long long> t[4*maxn+1];

inline int find(long long x) {
    int l = 1, r = N;
    while (l<r) {
        int mid = (l+r)>>1;
        if (st[mid]<x) l = mid+1;
        else r = mid;
    }
    return l;
}

inline long long calc(pair<long long,long long> d,long long x) {
    return (d.first*x+d.second);
}

inline void update(int k,int l,int r,int i,int j,pair<long long,long long> val) {
    if (l>j || r<i) return;
    auto mid = (l+r)>>1;
    if (i<=l && r<=j) {
        if (calc(t[k],st[l])>=calc(val,st[l]) && calc(t[k],st[r])>=calc(val,st[r])) {
            return;
        } 
        if (calc(t[k],st[l])<=calc(val,st[l]) && calc(t[k],st[r])<=calc(val,st[r])) {
            t[k] = val;
            return;
        } 
        if (calc(t[k],st[l])>=calc(val,st[l]) && calc(t[k],st[mid])>=calc(val,st[mid])) {
            update(k*2+1,mid+1,r,i,j,val);
            return;
        } 
        if (calc(t[k],st[l])<=calc(val,st[l]) && calc(t[k],st[mid])<=calc(val,st[mid])) {
            update(k*2+1,mid+1,r,i,j,t[k]);
            t[k] = val;
            return;
        }
        if (calc(t[k],st[mid+1])>=calc(val,st[mid+1]) && calc(t[k],st[r])>=calc(val,st[r])) {
            update(k*2,l,mid,i,j,val);
            return;
        }
        if (calc(t[k],st[l])<=calc(val,st[l]) && calc(t[k],st[mid])<=calc(val,st[mid])) {
            update(k*2,l,mid,i,j,t[k]);
            t[k] = val;
            return;
        }
    }
    update(k*2,l,mid,i,j,val);
    update(k*2+1,mid+1,r,i,j,val);
}

long long query(int k,int l,int r,int i) {
    if (l>New[i] || r<New[i]) return -maxc;
    long long res = calc(t[k],x[i]);
    if (l==r) return res;
    int mid = (l+r)>>1;
    res = max(res,query(k*2,l,mid,i));
    res = max(res,query(k*2+1,mid+1,r,i));
    return res;
}

void process() {
    long long res = -maxc;
    pair<long long,long long> val1,val2;
    for (int i=1;i<=N;++i) {
        f[i] = query(1,1,N,i)+e[i];
        res = max(res,f[i]);
        val1.first = W[i];
        val1.second = f[i]-W[i]*x[i];
        update(1,1,N,1,New[i],val1);
        val2.first = -W[i];
        val2.second = f[i]+W[i]*x[i];
        update(1,1,N,New[i],N,val2);
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> x[i] >> W[i] >> e[i];
        st[i] = x[i];
    }
    sort(st+1,st+1+N);
    for (int i=1;i<=N;++i) {
        New[i] = find(x[i]);
    }
    process();
    //return 0;
}