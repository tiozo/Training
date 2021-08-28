#include<bits/stdc++.h>
using namespace std;

int n;
const int oo = 1000000007;
const int MAXN = 100005;
int a[MAXN];
int task1() {
    int res = 0;
    bool allNeg = true;
    for (int i=0;i<n;++i) {
        if (a[i]>=0) {
            allNeg = false;
            res += a[i];
        }
    }
    if (allNeg) res = *max_element(a,a+n);
    return res;
}

int task2() {
    int sum = 0, res = -oo;
    for (int i=0;i<n;++i) {
        sum = sum + a[i];
        res = max(sum,res);
        sum = max(sum,0);
    }
    return res;
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i=0;i<n;++i) {
            cin >> a[i];
        }
        cout << task1() << ' ' << task2() << '\n';
    }
    return 0;
}