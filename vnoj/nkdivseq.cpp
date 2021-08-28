#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N,t=0,i = 0,a;
    cin >> N;
    while (N) {
        i++;
        for (int j=1;j<=i;++j) {
            if (!N) break;
            else {
                if (j==1) {
                    a = t % i;
                    t += i-a;
                } else {
                    t+=i;
                }
            N--;
            }
        }
    }
    cout << t;
    return 0;
}   