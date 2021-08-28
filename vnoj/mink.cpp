#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T,N,K;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cin >> N >> K;
        vector<int> a(N+1,0),s(N+1,0);
        for (int i=1;i<=N;++i) {
            cin >> a[i];
        }
        int l=1,r=0;
        for (int i=1;i<=K;++i) {
            while (r!=l-1 && a[i] < a[s[r]])  {
                r--;
            }
            s[++r] = i;
        }
        cout << a[s[l]] << ' ';
        for (int i=K+1;i<=N;++i) {
            while (s[l] <= i-K && l!=r+1) l++;
            while (r!=l-1 && a[i] < a[s[r]]) r--;
            s[++r] = i;
            cout << a[s[l]] << ' ';
        }
        cout << '\n';
    }
}