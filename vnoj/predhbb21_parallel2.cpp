#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,N;
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> a >> b;
        cout << ((a<=1 && b<=2)||(a<=2 && b<=1) ? "Yes\n" : "No\n");
    }
    return 0;
}