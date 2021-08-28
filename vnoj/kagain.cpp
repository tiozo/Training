#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N+1),left(N+1),right(N+1);
        for (int i=0;i<N;++i) cin >> a[i];
        a[N] = INT_MIN;
        stack<int> s;
        for (int i=0;i<=N;++i) {
            left[i] = i;
            while (!s.empty() && a[s.top()]>a[i]) {
                right[s.top()] = i-1;
                left[i] = left[s.top()];
                s.pop();
            }
            s.push(i);
        }
        int res = 0,resL,resR; 
        for (int i=0;i<N;++i) {
            if ((right[i]-left[i]+1)*a[i]>res) {
                res = (right[i]-left[i]+1)*a[i];
                resL= left[i];
                resR= right[i];
            }
        }
        resL++;
        resR++;
        cout << res << ' ' << resL << ' ' << resR << '\n';
    }
    return 0;
}