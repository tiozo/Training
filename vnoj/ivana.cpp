#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N; vector<int> a(2*N+1);
    vector<vector<int>> f(N+1,vector<int>(2*N+1,0));
    vector<int> b(2*N+1);
    b[0]=0;
    int odds = 0,res = 0;
    for (int i=1;i<=N;++i) {
        cin >> a[i]; 
        a[i+N] = a[i];
        if (a[i]%2) {
            f[i][i] = 1;
            b[i] = b[i-1]+1;
        } else {
            f[i][i] = 0;
            b[i] = b[i-1];
        }
    }
    for (int i=N+1;i<=2*N;++i) {
        b[i]= b[i-N] + b[N];
    }
    for (int i=1;i<=N-2;++i) {
        for (int j=1;j<=N-1;++j) {
            f[j][i+j]=max(-f[j+1][i+j],-f[j][i+j-1])+b[i+j]-b[j-1];
        }
        f[N][N+i]=max(-f[1][i],-f[N][N+i-1])+b[N+i]-b[N-1];
    }
    for (int i=1;i<=N;++i) {
        if (b[N]-f[i][i+N-2]>b[N]/2) res++;
    }
    cout << res;
    return 0;
}

/*
    8
    4 10 5 2 9 8 1 7
    test always sure that Ivana always win
    Ivana always take the odds digit to take advance 
    5 2 9 8 1
*/