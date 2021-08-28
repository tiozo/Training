#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10, S = 5000 + 10;
int f[N][S], s, p10[4] = {1,10,100,1000};
char a[N];

int main() {
    scanf("%s",a+1);
    char *buf = strchr(a+1,'=');
    s = atoi(buf+1);
    *buf = 0;
    memset(f,'0',sizeof f); f[0][0] = -1;
    int l = strlen(a+1);
    for (int i=1;i<=l;++i) {
        for (int j=0;j<=s;++j) {
            if (a[i] == '0') f[i][j] = f[i-1][j] + (i==l);
            int tmp = 0;
            for (int k=0;k<4&&k<i;++k) {
                tmp += p10[k]*(a[i-k]-'0');
                if (tmp<=j) f[i][j] = min(f[i][j],f[i-k-1][j-tmp]+1);
                else break;
            }
            //cout << tmp << '\n';
        }
    }
    printf("%d\n",f[l][s]);
    return 0;
}