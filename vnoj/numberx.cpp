#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    else return gcd(b,a%b);
}
int main()
{
    long long a,b;
    cin >> a >> b;
    long long k = gcd(a,b);
    long long c = (a/k)-1;
    long long x = b*c-a;
    cout << x;
    return 0;
}
