#include<bits/stdc++.h>
using namespace std;

vector<int> prime,lpf;
void eratos(int n) {
    prime.assign(1,2);
    lpf.assign(n+1,2);
    for (int  x = 3;x<=n;x+=2) {
        if (lpf[x] ==2) prime.push_back(lpf[x]=x);
        for (int i=0;i<prime.size() && prime[i] <=lpf[x] && prime[i]*x<=n;++i) {
            lpf[prime[i]*x] = prime[i];
        }
    }
}

bool isPrime(int x) {
    return (x>1) && (lpf[x]==x);
}

int main() { 
    eratos(1e7);
    int n;
    cin >> n;
    for (int p:prime) {
        if (isPrime(p*2-1)) {
            if (--n==0) {
                cout << p << ' ' << p << ' ' << p*2-1 << '\n';
                return 0;
            }
        }
        if (isPrime(p*2+1)) {
            if (--n == 0) {
                cout << p << ' ' << p << ' ' << p*2+1 << '\n';
                return 0;
            }
        }
    }
    return 0;
}