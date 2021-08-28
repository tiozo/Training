#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int N,a,b,u,v;
ii c[33];
map<ii,int> m1,m2;

void back(map<ii,int> &m, int begin, int end) {
    if (begin==end) ++m[ii(a,b)];
    else {
        for (int mul = 0;mul<2;++mul) {
            a+=mul*c[begin].first; b+=mul*c[begin].second;
            back(m,begin+1,end);
            a-=mul*c[begin].first; b-=mul*c[begin].second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=0;i<N;++i) cin >> c[i].first >> c[i].second;
    cin >> u >> v;
    back(m1,0,N/2);
    back(m2,N/2,N);
    long long res = 0;
    for (auto i:m1) {
        ii f = ii(u-i.first.first, v-i.first.second);
        if (m2.count(f)) res += (long long) i.second*m2[f];
    }
    cout << res;
    return 0;
}