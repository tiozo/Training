#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    int s=0;
    for (int i=0;i<n;++i) {
        cin >> a[i].first;
        a[i].second = i+1;
        s+=a[i].first;
    }
    //cout << s/k << ' ';
    for (int x=s/k;x>0;--x) {
        sort(a,a+n);
        for (int i=n-k;i<n;++i) {
            cout << a[i].second << ' ';
            --a[i].first;
        }
        cout << '\n';
    }
    return 0;
}