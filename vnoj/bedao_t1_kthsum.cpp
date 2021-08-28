#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
const long long oo = 1e14+7;
vector<int> t(maxn,0);
void update(int p,int val) {
    for (int i=p;i<=1e5;i+=i&-i) {
        t[i] += val;
    }
}

int get(int p) {
    int res = 0;
    for (int i=p;i;i-=i&-i) {
        res += t[i];
    }
    return res;
}

static vector<long long> compress;
vector<pair<long long,int>> prefix(1,{0,0});
long long f(long long val,int n) {
    long long cnt = 0;
    vector<int> empty(maxn,0); swap(empty,t);
    int j=1;
    for (int i=1;i<=n;++i) {
        while (j<=n && prefix[i].first-prefix[j].first>=val) {
            update(prefix[j++].second,1);
        }
        cnt += get(prefix[i].second);
        if (prefix[i].first>=val) ++cnt;
    }
    return cnt;
}

inline long long div_floor2(long long x) {
	if (x >= 0) return x / 2;
	return -((-x + 1) / 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; long long K; cin >> N >> K;
    vector<long long> a(N);
    for (int i=1;i<=N;++i) {
        int x; cin >> x;
        prefix.emplace_back(prefix.back().first+x,i);
    }
    sort(prefix.begin()+1,prefix.end());
    long long l = -oo, r = oo;
    while (l<r) {
        long long mid = div_floor2(l+r);
        long long cur = f(mid,N);
        if (cur < K) {
            r = mid;
        } else l = mid + 1;
    }
    cout << l-1;
    return 0;
}

/*
    5 6
    1 5 4 7 9 
*/