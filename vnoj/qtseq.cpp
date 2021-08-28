#include<bits/stdc++.h>
using namespace std;

const long long inf = (1ll<<62);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<long long> a(N);
    vector<long long> fmax(N,0),fmin(N,0),num_max(N),num_min(N);
    for (int i=0;i<N;++i) {
        cin >> a[i];
        if (i>0) {
            a[i] += a[i-1];
            fmax[i] = max(fmax[i-1],a[i]);
            fmin[i] = min(fmin[i-1],a[i]);
            if (a[i]>fmax[i-1]) num_max[i] = 1;
            else if (a[i]==fmax[i-1]) num_max[i] = num_max[i-1] + 1;
            else num_max[i] = num_max[i-1];
            if (a[i]<fmin[i-1]) num_min[i] = 1;
            else if (a[i]==fmin[i-1]) num_min[i] = num_min[i-1] + 1;
            else num_min[i] = num_min[i-1];
        } else {
            fmax[i] = a[i];
            fmin[i] = a[i];
            num_min[i] = 1;
            num_max[i] = 1;
        }
    }
    long long num = 0;
    long long res = -inf;
    for (int i=N-1;i>=1;--i) {
        if (abs(fmin[i-1]-a[N-1]+a[i-1]) > res) {
            res = abs(fmin[i-1]-a[N-1]+a[i-1]);
            num = num_min[i-1];
        } else {
            if (abs(fmin[i-1]-a[N-1]+a[i-1])==res) {
                num += num_min[i-1];
            }
        }
        if (fmax[i-1]==fmin[i-1]) continue;
        if (abs(fmax[i-1]-a[N-1]+a[i-1])>res) {
            res = abs(fmax[i-1]-a[N-1]+a[i-1]);
            num = num_max[i-1];
        } else {
            if (abs(fmax[i-1]-a[N-1]+a[i-1])==res) {
                num += num_max[i-1];
            }
        }
    }
    cout << res << ' ' << num;
    return 0;
}


/// [][][3][4][][] 