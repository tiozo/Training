#include<bits/stdc++.h>
using namespace std;

#define mask(i) (1ll<<(i))
#define bit(i,x) (((i) >> (x)) & 1ll)
using ll =  long long;
using pii = pair<int,int>;
const int mod = 1e9+7;
const long long oo = 1e9+7;
const int maxn = 1e6;

template<class T> bool omin(T &a, const T &b) {
        return b < a ? a = b, 1 : 0;
}
template<class T> bool omax(T &a, const T &b) {
        return a < b ? a = b, 1 : 0;
}

int n;
vector<pii> cards[maxn], needs[maxn];
vector<array<long long,3>> valid_plays[maxn];

void solve() {
    cin >> n;
    for (int i=1;i<=n;++i) {
        int k; cin >> k;
        cards[i].assign(k,{0,0});
        for (int j=0;j<k;++j) {
            cin >> cards[i][j].first >> cards[i][j].second;
        }
    }
    for (int i=1;i<=n;++i) {
        sort(cards[i].begin(),cards[i].end(),[&](pii a,pii b) {
            return a.second > b.second;
        });
        vector<int> cnt(4,0);
        for (auto e:cards[i]) {
            if (cnt[e.first]*e.first+e.first<=3) {
                needs[i].push_back(e);
            }
            ++cnt[e.first];
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<mask(needs[i].size());++j) {
            int cost = 0, ma = 0;
            long long dame = 0;
            for (int k=0;k<(int)needs[i].size();++k) {
                if ((j>>k)&1) {
                    cost += needs[i][k].first;
                    dame += needs[i][k].second;
                    omax(ma,needs[i][k].second);
                }
            }
            if (cost<=3) {
                valid_plays[i].push_back({__builtin_popcount(j), dame, ma});
            }
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll> (11,-1));
    dp[0][0] = 0;
    for (int i=0;i<n;++i) for (int j=0;j<=10;++j) if (dp[i][j]>-1) {
        for (auto e:valid_plays[i+1]) {
            int next_num = j+e[0];
            if (next_num<10) 
                omax(dp[i+1][next_num],dp[i][j]+e[1]);
            else 
                omax(dp[i+1][next_num%10],dp[i][j]+e[1]+e[2]);
        }
    }
    cout << *max_element(dp[n].begin(),dp[n].end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}