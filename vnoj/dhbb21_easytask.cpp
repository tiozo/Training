///github 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<bool> prime;
vector<int> p;
void sieve(int n) {
    prime.resize(n+1,0);
    for (int i=2;i*i<=n;++i) {
        if (!prime[i]) {
            for (int j=i*i;j<=n;j+=i) {
                prime[j] = 1;
            }
        }
    }
    for (int i=2;i<=n;++i) {
        if (!prime[i]) p.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n; sieve(n);
    vector<int> a(n+1);
    vector<int> prefixsum(n+1,0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        prefixsum[i] = prefixsum[i-1]+a[i];
    } 
    int maxval = INT32_MIN;
    priority_queue<int,vector<int>,greater<>> pq;
    //int f_min = 0;
    for (int i=0;i<p.size();++i) {
        pq.push(prefixsum[p[i]-1]);
        maxval = max(maxval,prefixsum[p[i]]-pq.top());
    }
    cout << maxval;
    return 0;
}