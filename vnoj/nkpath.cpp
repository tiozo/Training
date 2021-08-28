#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

const int MOD=1e9;

int main() {
    int M,N;
    cin >> M >> N;
    vector<vi > a(M+1,vi (N+1,0));
    for (int i=1;i<=M;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    vector<vi > F(M+1,vi (N+1,0));
    for (int i=1;i<=M;++i) {
        F[i][1]=1;
    }
    for (int i=1;i<=M;++i) {
        for (int j=1;j<=N;++j) {
            for (int x=1;x<=i;++x) {
                for (int y=1;y<=j;++y) {
                    if (y < N && x+y<i+j  && gcd(a[x][y],a[i][j])!=1)
                        F[i][j]=(F[i][j]+F[x][y])%MOD;
                }
            }
        }
    }
    int sum=0;
    for (int i=1;i<=M;++i) {
        sum=(sum+F[i][N])%MOD;
    }
    cout << sum;
    return 0;
}
