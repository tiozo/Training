#include<bits/stdc++.h>
using namespace std;

int N;
int cnt = 0;
int s[257];
int a[9][10001];
long long f[257][10001];

inline long long getIthBit(int N,int col) {
    long long val = 0;
    for (int i=1;i<=8;++i) {
        if ((N>>(i-1))&1) val += a[i][col];
    }
    return val;
}

long long dpBitMask() {
    memset(f,0,sizeof f);
    for (int i=0;i<256;++i) {
        bool ok = 1;
        for (int k=0;k<7 && ok;++k){
            ok = (i&3<<k) != (3<<k);
        }
        if (ok) { s[cnt++]=i;};
    }
    for (int i=0;i<=cnt;++i) f[s[i]][1] = getIthBit(s[i],1);
    for (int j=2;j<=N;++j) {
        for (int i=0;i<cnt;++i) {
            long long x = getIthBit(s[i],j);
            f[s[i]][j] = x;
            for (int k=0;k<cnt;++k) {
                if (!(s[i] & s[k])) {
                    f[s[i]][j] = max(f[s[k]][j-1]+x,f[s[i]][j]);
                }
            }
        }
    }
    long long res = f[1][N];
    for (int i=0;i<cnt;++i) {
        res = max(f[s[i]][N],res);
    }
    int res2= a[1][1];
    for (int i=1;i<=8;++i) {
        for (int j=1;j<=N;++j) {
            res2=max(res2,a[i][j]);
        }
    }
    return res2<0 ? res2 : res;
}

int main() {
    cin >> N;
    for (int i=1;i<=8;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    cout << dpBitMask();
    return 0;
}


/*
*/