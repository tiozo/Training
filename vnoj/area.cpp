#include<bits/stdc++.h>
using namespace std;

struct Data {
    int x,l,r,type;
};

struct segment {
    int cnt,length;
};  

const int N = 30010;
int n,m,k;
long long ans;
data a[N];
segment t[4*N];

bool cmp(Data u,Data v) {
    return u.x!=v.x ? u.x<v.x : u.type < v.type;
}

void upd(int l,int r,int id,int u,int v,int type) {
    if (u>v || r<u || v<l) return;
    if (u<=l && r<=v) {
        
    }
}

int main() {

    return 0;
}