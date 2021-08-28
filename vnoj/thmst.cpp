#include<bits/stdc++.h>
using namespace std;

long long giaithua(int n)
{
    int giai_thua = 1;
    for (int i = 1; i <= n; i++)
        giai_thua *= i;
    return giai_thua;
}

int main() {
    int N;
    cin >> N;
    long long res = 0,largest = 0;
    for (int i=1;i<N;++i) {
        long long x,y,z;
        cin >> x >> y >> z;
        res += z;
        largest = max(largest,z);
    }
    if (N>2) {
        long long a,b;
        a = N-1,b=N-2;
        a = giaithua(a)/(giaithua(2)*giaithua(a-2));
        b = giaithua(b)/(giaithua(2)*giaithua(b-2));
        res+=(largest+1)*(a-b)+largest*b;
        --N;
        while (N-2>2 || N-1>2) {
            a = N-1,b=N-2;
            a = giaithua(a)/(giaithua(2)*giaithua(a-2));
            b = giaithua(b)/(giaithua(2)*giaithua(b-2));
            res+=(largest+1)*(a-b)+largest*b;
            --N;
        }
        cout << res;
    } else cout << res;
    return 0;
}