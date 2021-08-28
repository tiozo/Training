
#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> s(9,0);
vector<vector<int>> a;
vector<vector<int>> f;

int getIthBit(int N,int col) {
    int val = 0;
    for (int i=1;i<=4;++i) {
        if ((N>>(i-1))&1) val += a[i][col];
    }
    return val;
}

int dpBitMask() {
    f = vector<vector<int>>(9,vector<int>(N+1));
    for (int i=1;i<=8;++i) f[i][0] = 0;
    s[1] = 0; s[5] = 5;
    s[2] = 1; s[6] = 8;
    s[3] = 2; s[7] = 9;
    s[4] = 4; s[8] = 10;
    for (int j=1;j<=N;++j) {
        for (int i=1;i<=8;++i) {
            int mask = s[i];
            int x = getIthBit(mask,j);
            f[i][j] = INT_MIN;
            for (int k=1;k<=8;++k) {
                if (!(mask & s[k]) && f[k][j-1]+x>f[i][j]) {
                    f[i][j] = f[k][j-1]+x;
                }
            }
        }
    }
    int res = INT_MIN;
    for (int i=1;i<=8;++i) {
        res = max(f[i][N],res);
    }
    int res2= INT_MIN;
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=N;++j) {
            res2=max(res2,a[i][j]);
        }
    }
    return res2<0 ? res2 : res;
}

int main() {
    cin >> N;
    a = vector<vector<int>>(5,vector<int> (N+1,0));
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    cout << dpBitMask();
    return 0;
}