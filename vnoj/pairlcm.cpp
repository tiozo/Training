#include<bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
    long long res = 0;
    int N; cin >> N;
    for (int i=1;i<=sqrt(N);++i) {
        int a = i;
        int a1 = N/i;
        res = max(res,lcm(a,N-a));
        res = max(res,lcm(a1,N-a1));
    }
    cout << res;
    return 0;
}