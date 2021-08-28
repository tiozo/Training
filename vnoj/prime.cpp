///Olympic tin hoc Chuyen KHTN
#include<bits/stdc++.h>
using namespace std;

int M,N;
long long cprime=0;
long long sum=0;
const int maxrc=1500;
const int maxval=1e7;
vector<bool> prime(maxval+1,true);
vector<vector<int> > a(maxrc+1, vector<int> (maxrc+1,0));

void SOE(int n)
{
    prime[0]=false;
    prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
         if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve(int r) {
    for (int i=1;i<=M;++i) {
        if (prime[a[r][i]]==true) {
            sum+=a[r][i];
            ++cprime;
        }
        int number=a[r][i];
        int d=1;
        int range=i+5;
        if (range>M) {
            range=M;
        }
        for (int j=i+1;j<=range;++j) {
            number*=10;
            number+=a[r][j];
            if (prime[number]==true) {
                sum+=number;
                ++cprime;
            }
        }
        if (a[r][i]!=0) {
            number=a[r][i];
            d=1;
            range=r+5;
            if (range>N) {
                range=N;
            }
            for (int j=r+1;j<=range;++j) {
                number*=10;
                number+=a[j][i];
                if (prime[number]==true) {
                    sum+=number;
                    ++cprime;
                }
            }
        }
        if (a[r][i]!=0 && r!=N && i!=M) {
            number=a[r][i];
            d=1;
            range=M-i+1;
            int r1=r,i1=i;
            for (int j=2;j<=range;++j) {
                ++r1;++i1;
                number*=10;
                number+=a[r1][i1];
                if (prime[number]==true) {
                    sum+=number;
                    ++cprime;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.inp","r",stdin);
    cin >> N >> M;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
        }
    }
    SOE(1e7);
    for (int i=1;i<=N;++i) {
        solve(i);
    }

    cout << cprime << ' ' << sum;
    return 0;
}
