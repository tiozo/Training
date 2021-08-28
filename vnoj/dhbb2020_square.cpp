#include<bits/stdc++.h>
using namespace std;
#define sz(a) a.size()
typedef long long ll;
const int LIM = 5*1e6+1;
vector<int> prime; /// prime list
vector<int> lpf;   /// Lowest prime factor, lpf[x] is smallest prime divisor of x
void sieve(int lim = LIM) /// O(n)
{
    prime.assign(1, 2);
    lpf.assign(lim + 1, 2);

    lpf[1] = 1; /// For easier calculation but can cause inf loops
    for (int i = 3; i <= lim; i += 2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i);
        for (int j = 0; j < sz(prime) && prime[j] <= lpf[i] && prime[j] * i <= lim; ++j)
            lpf[prime[j] * i] = prime[j];
    }
}

/// mask(x) is smallest positive number that mask(x) * x is a perfect square
int getMask(int x) /// O(log n)
{
    int mask = 1;
    while (x > 1) {
        int p = lpf[x], f = 0;
        do x /= p, f++; while (p == lpf[x]);
        if (f & 1) mask *= p; /// if current power is odd, we mutiple mask with current prime
    }
    return mask;
}

/// nC2 = number of ways to choose another 2 numbers
ll f(int x) { return 1LL * x * (x - 1) / 2; }
ll magic(int n) /// O(n log max(a))
{
    vector<int> cnt(n + 1, 0); /// Save the frequency of each mask
    ll res = 0;
    for (int a = 1; a <= n; ++a) /// Check all cases of a
        res += f(cnt[getMask(a)]++);

    return res;
}

int main() /// O(n log max(a))
{
    int n;
    cin >> n;
    sieve(n + 500);
    cout << magic(n);    
    //vector<int> a;
    //sz(a);
    return 0;
}
