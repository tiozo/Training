#include<bits/stdc++.h>
using namespace std;

#define CLOSE 0
#define OPEN 1
/*
struct Data {
    int L,R;
    Data() {}
    Data(int l,int r): L(l), R(r) {}
    bool operator < (const Data &a) const {
        return L != a.L ? L < a.L : R < a.R;
    }
    bool operator > (const Data &a) const {
        return L != a.L ? L > a.L : R > a.R;
    }
};
*/
const int maxn = 2e5 + 5;
int L[maxn], R[maxn];
int N;
int M;
int f[maxn][1 << 8];
vector<tuple<int, int, int> > endpoints;
#define OPEN 1
#define CLOSE 0

int get_mask(const map<int,bool> &intervals) {
    int mask = 0;
    for (auto x:intervals) {
        mask <<= 1;
        mask |= x.second;
    }
    return mask;
}

int calc(int i,map<int,bool> &intervals) {
    if (i>=M-1) 
        return 0;
    int mask = get_mask(intervals);
    bool parity = __builtin_parity(mask);
    int &res = f[i][mask];
    if (res != -1) return res;
    res = 0;
   // auto [val, typ, id] = endpoints[i];
    auto val = get<0>(endpoints[i]);
    auto typ = get<1>(endpoints[i]);
    auto id = get<2>(endpoints[i]);
    if (typ == CLOSE) {
        bool save = 0;
        if (intervals[id])
            parity ^= 1, save = 1;
        intervals.erase(id);
        res = calc(i + 1, intervals) + parity * (get<0>(endpoints[i + 1]) - val); 
        intervals[id] = save;
        return res;
    }
    intervals[id] = 1;
    parity ^= 1;
    res = calc(i + 1, intervals) + parity * (get<0>(endpoints[i + 1]) - val);
    parity ^= 1;
    intervals[id] = 0;
    res = max(res, calc(i + 1, intervals) + parity * (get<0>(endpoints[i + 1]) - val));
    intervals.erase(id);
    return res;
}

int main() {
    /*#ifdef DELL 
        freopen("input.inp","r",stdin);
    #endif*/
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> L[i] >> R[i];
        ++R[i];
        //cout << a[i].L << ' ' << a[i].R << '\n';
    }
    for (int i=1;i<=N;++i) {
        endpoints.push_back({L[i],OPEN,i});
    }
    for (int i=1;i<=N;++i) {
        endpoints.push_back({R[i],CLOSE,i});
    }
    sort(endpoints.begin(),endpoints.end());
    M = endpoints.size();
    //cout << get<0>(endpoints[1]) << ' ';
    map<int,bool> tmp;
    memset(f,255,sizeof(f));
    cout << calc(0,tmp) << '\n';
    return 0;
}