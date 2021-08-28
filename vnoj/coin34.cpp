#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

const int maxval = 2000000000;
long long sum;
vector<int> coin(35);
map<int,int> m1,m2;

void maximize(int &a, const int &b) { if(a < b) a = b; }
void backtrack(int begin, int end, long long sum, int c, map<int, int> &m) {
    if(sum > maxval) return;
    if(begin == end) maximize(m[sum], c);
    else {
        backtrack(begin+1, end, sum, c, m);
        backtrack(begin+1, end, sum+coin[begin], c+1, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    coin[0] = 2; coin[1] = 3; coin[2] = 5;
    for (int i=3;i<34;++i) coin[i] = coin[i-1]+coin[i-2] + coin[i-3];
    backtrack(0,17,0,0,m1);
    backtrack(17,34,0,0,m2);
    int tc; cin >> tc;
    for (int t=1;t<=tc;++t) {
        int N,res=-1; cin >> N;
        for (map<int,int>::iterator it = m2.begin();it!=m2.end();++it) {
            if (it->first<=N) {
                if (m1.count(N - it->first)) {
                    maximize(res,it->second+m1[N-it->first]);
                } 
            } else break;
        } 
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}