#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int N=3;
    vi S(N+1,0);
    int Fsize=0;
    for (int i=1;i<=N;++i) {
        cin >> S[i];
        Fsize+=S[i];
    }
    int time=0,result;
    vi F(Fsize+1,0);
    for (int i=3;i<=S[1]+S[2]+S[3];++i) {
        F[i]=0;
        for (int i1=1;i1<=S[1];++i1) {
            for (int i2=1;i2<=S[2];++i2) {
                for (int i3=1;i3<=S[3];++i3) {
                    if (i==i1+i2+i3) {
                        ++F[i];
                    }
                }
            }
        }
        if (time<F[i]) {
            time=F[i];
            result=i;
        }
    }
    cout << result;
    return 0;
}
