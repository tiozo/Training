#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,days=0;
    cin >> N;
    vector<int> dead(N+1);
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for (int i=1,ai;i<=N;++i) {
        cin >> ai;
        pq.push(pair<int,int>(ai,i));
    }
    for (;!pq.empty();pq.pop()) {
        int v = pq.top().second;
        if (dead[v] == 0) {
            dead[v] = dead[v-1] = dead[v+1] = 1;
            ++days;
        }
    }
    cout << days;
    return 0;
}