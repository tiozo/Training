#include<bits/stdc++.h>
using namespace std;

const int16_t maxn = 10000;
const int16_t ww = 1000;
int16_t f[maxn+1][ww+1], v[maxn+1],w[maxn+1],st[maxn+1]; 

int main() {
    int N,W;
    int16_t tc; scanf("%d",&tc);
    while (tc--) {
        scanf("%d%d",&N,&W);
        for (int16_t i=1;i<=N;++i) scanf("%d",w+i);
        for (int16_t j=1;j<=N;++j) scanf("%d",v+j);
        for (int16_t i=1;i<=N;++i) {
            for (int16_t j=w[i]-1;j>=1;--j) {
                f[i][j] = f[i-1][j];
            } 
            for (int16_t j=w[i];j<=W;++j) {
                if (f[i-1][j]<v[i]+f[i-1][j-w[i]])
                    f[i][j] = v[i]+f[i-1][j-w[i]];
                else f[i][j] = f[i-1][j];
            }
        }
        int16_t i = N, j= W, hi = 0;
        while (i&&j) {
            if (f[i][j]==f[i-1][j]) --i;
            else {
                st[hi++]= i;
                j -= w[i--];
            }
        }
        printf("%d %d\n",f[N][W],hi);
        while (hi--) printf("%d ",st[hi]);
    }
    //return 0;
}