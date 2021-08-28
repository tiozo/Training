#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; 
    vector<int> a(N);
    for (int &a:a) cin >> a;
    vector<vector<int>> cnt(2,vector<int>((1<<20)+3,0));
    cnt[1][0] = 1;
    int x = 0;
    long long res = 0;
    for (int i=0;i<N;++i) {
        x^=a[i]; 
        res+=cnt[i%2][x];
        ++cnt[i%2][x];
    }
    cout << res;
    return 0;
}