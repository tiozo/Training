#include<bits/stdc++.h>
using namespace std;
#define H 500001
int f[H], g[H];

int main() {
    int n,h; scanf("%d %d",&n,&h);
    for (int i=0;i<n;++i) {
        int x; scanf("%d",&x);
        if (i&1) f[x]++;
        else g[x]++;
    }
    for (int i=h-1;i>=0;--i) {
        f[i] += f[i+1];
        g[i] += g[i+1];
    }
    int res = n+1, cnt = 0;
    for (int i=1;i<=h;++i) {
        int c = f[i]+g[h-i+1];
        if (res==c) cnt++;
        else if (res>c) {
            res = c;
            cnt = 1;
        }
    }
    printf("%d %d\n",res,cnt);
    return 0;
}