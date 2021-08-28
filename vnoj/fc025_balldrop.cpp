#include<bits/stdc++.h>
using namespace std;

const int maxn = 64;
long long f[100][maxn];
void set_val() {
    for (int i=0;i<100;++i) {
        f[i][0] = 1;
    }
    for (int i=0;i<maxn;++i) {
        f[0][i] = 1;
    }    
    for (int i=1;i<100;++i) {
        for (int j=1;j<maxn;++j) {
            f[i][j] = f[i][j-1]+f[i-1][j-1];
        }
    }
}

int main() {
    //freopen("output.out","w",stdout);
    long long M;
    int N,res = 0; cin >> N >> M;
    set_val();
    for (int i=0;i<maxn;++i) {
        M=M-f[N-1][i];
        if (M<=0 && i<63) {
            res = i; break;
        } else if (i>=63) {
            cout << "More than 63 trials needed.";
            return 0;
        }
    }
    if (res==63) 
    cout << res;
    else cout << ++res;
    return 0;
}