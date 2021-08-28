#include<bits/stdc++.h>
using namespace std;

int Size;
unsigned long long n;
vector<bool> isPrime(1e7+1,1);
vector<unsigned long long> prime;

void generate() {
    isPrime[0] = isPrime[1] = 0;
    for (int i=2;i*i<=1e7;++i) if (isPrime[i]) {
        for (int j=i+i;j<=1e7;j+=i) isPrime[j] = 0;
    }
    for (unsigned long long i=2;i<=1e7;++i) {
        if (isPrime[i]) prime.push_back(i);
    }
}

bool check(unsigned long long n,int k) {
    unsigned long long product = 1;
    for (int i=0;i<k;++i) product*=prime[i];
    return product<=n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    generate();
    unsigned long long N;
    int test,k;
    cin >> test;
    while (test--) {
        cin >> N >> k;
        unsigned long long res = 1;
        if (!check(N,k)) cout << "-1\n";
        else {
            int l = 0, h = prime.size()-k;
            while (l<h) {
                int m = (l+h+1)/2; bool ok = true;
                unsigned long long product = 1;
                for (int i=m;i<m+k;++i) 
                    if (N/product>=(unsigned long long)prime[i]) product*=prime[i];
                    else ok = false;
                if (ok) l=m; else h=m-1; 
            }
            for (int i=l;i<l+k;++i) res*=prime[i];
            cout << (unsigned long long)res << '\n';
        }
    }
    return 0;
}