#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5+7;
const int mod = 1e9+7;
set<int> calced[maxn];
int a[maxn], sumf[maxn], prefix[maxn];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    prefix[0] = 0;
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    map<int,int> id_th_sum;
    for (int i=0;i<=N;++i) {
        id_th_sum[prefix[i]] = i;
    }
    //calced.insert(0);
    sumf[0] = 1;
    for (int i=1;i<=N;++i) {
        int cur_sum = a[i];
        int j = i-1;
        int f = sumf[j];
        calced[i].insert(cur_sum);
        while (true) {
            if (id_th_sum.count(prefix[j]-cur_sum) && calced[j].count(cur_sum)) {
                j = id_th_sum[prefix[j]-cur_sum];
                f = (f+sumf[j]) % mod;
                cur_sum*=2;
                calced[i].insert(cur_sum);
            } else break;
        }
        sumf[i] = f;
    }
    cout << sumf[N];
    return 0;
}