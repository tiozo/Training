#include<bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
    unsigned long long int G=1,F=1; int N; cin >> N;
    if (N<=0) { cout << "impossible"; return 0; }
    for (int i=1;i<=N;++i) {
        long long x; cin >> x;
        G=G*(gcd(F,x));
        F=lcm(x,F);
    }
    //cout << G << ' ' << F;
    if (F==0 || G==0) cout << "impossible";
    else cout << G;
    return 0;
}