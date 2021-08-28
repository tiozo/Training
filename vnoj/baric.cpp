#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int abs(int n) {
    if (n<0) return -n;
    return n;
}

int main() {
    int N,E;
    cin >> N >> E;
    vi M(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> M[i];
    }
    int loc=0,res=0;
    vector<vi > F(N+1,vi (N+1,0));
    int tt=1e9;
    for (int i=1;i<=N;++i) {
        F[1][i]=0;
        for (int j=1;j<=N;++j) {
            F[1][i]+=2*abs(M[j]-M[i]);
        }
        if (F[1][i]<=E) {
            if (F[1][i]<tt) tt=F[1][i];
            res=1;
        }
    }
    if (res!=0) {
        cout << res << ' ' << tt;
    } else {
        vector<vi > dp(N+1,vi(N+1,0));
        for (int i=1;i<N;++i) {
            for (int j=i+1;j<=N;++j) {
                for(int k = j;k<=N;k++)
                    dp[i][j] += 2*abs(M[k]-M[j])-2*abs(M[k]-M[i]);
                for(int k = i+1;k<j;k++)
                    dp[i][j] += abs(2*M[k]-M[i]-M[j])-2*abs(M[k]-M[i]);
            }
        }
        for(int i = 2;i<=N;i++)
        {
            tt=1e9;
            for(int j = 1;j<=N;j++)
            {
                if(j<i)
                {
                    F[i][j] = 1e9;
                }
                else
                {
                    F[i][j] = 1e9;
                    for(int k = j-1;k>=i-1;k--)
                    {
                         if(F[i-1][k]+dp[k][j]<F[i][j])
                             F[i][j] = F[i-1][k]+dp[k][j];
                    }
                }
                if(F[i][j]<=E)
                {
                     if(F[i][j]<tt)
                         tt =F[i][j];
                     res = i;}
            }
            if(res!=0)
            {
                printf("%d %d",res,tt);
                break;
            }
        }
    }
    return 0;
}
