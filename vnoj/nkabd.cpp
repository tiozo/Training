#include<bits/stdc++.h>
using namespace std;

int prefixsum[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=1e5;++i) {
        for (int j=i+i;j<=1e5;j+=i) {
            prefixsum[j] += i;
        }
    }
    int a,b,res=0;
    cin >> a >> b;
    for (int i=a;i<=b;++i) {
        res += prefixsum[i] > i;
    }
    cout << res;
    return 0;
}