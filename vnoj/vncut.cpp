#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b; int ans = 0;
    cin >> a >> b;
    while (a*b>0) {
        if (a>1) a=a*0.5; else
        b=b*0.5;
        ans++;
    }
    cout << ans;
    return 0;
}