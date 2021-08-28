#include"permeow2.h"
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5100;
const int oo = (int)1e9+7;
const int MOD = (int)1e9+7;

int dp[MAXN][MAXN];

int count_permutation(vector<int> p) {
    int N = p.size();
    for (int x = 1;x<=N;++x) {
        dp[0][x] = 1;
    }
    for (int r=1;r<=N;++r) {
        int maxP = -oo, minP = oo;
        for (int l = r; l>=1;--l) {
            maxP = max(maxP,p[l-1]);
            minP = min(minP,p[l-1]);
            dp[r][maxP] = (dp[r][maxP]+dp[l-1][minP])%MOD;
        }
        for (int x = N;x>=1;--x) {
            dp[r][x] = (dp[r][x] + dp[r][x+1]) % MOD;
        }
    }
    return dp[N][1];
}