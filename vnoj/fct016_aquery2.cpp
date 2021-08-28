#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> a(N);
    for (auto &a:a) cin >> a.first >> a.second;
    long long k; cin >> k;
    sort(a.begin(),a.end());
    long long sum = 0;
    for (auto &a:a) {
        sum += a.second;
        if (sum>=k) {
            cout << a.first;
            break;
        }
    }
    return 0;
}