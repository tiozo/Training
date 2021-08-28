///segment tree solve bit
#include <bits/stdc++.h>
using namespace std;

int Build(int id,int l,int r,int i,int v) {
    if (i<l||r<i) {
        return;
    }
    if (l==r) {
        T[id]=v;
        return;
    }
    int m=(l+r)>>1;
    Build(id<<1,l,m);
    Build((id<<1)|1,m+1,r);
    T[id]=max(T[id<<1],T[(id<<1)|1]);
}

int get(int id,int l,int r,int u,int v) {
    if (v<l || r<u) {
        return -10000;
    }
    if (u<=l && r<=v) {
        return T[id];
    }
    int m=(l+r)>>1
    return max( get(id<<1,l,m);
    get((id<<1)|1,m+1,r););
}

int main() {
    int n;
    cin >> n;
    return 0;
}
