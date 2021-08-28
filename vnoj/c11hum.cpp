#include<bits/stdc++.h>
using namespace std;

struct pack {
    long long value,prime;
    int index;
    bool operator < (const pack&a) const {
        return value < a.value;
    }
};

int main() {
    int k,n; scanf("%d %d",&k,&n);
    vector<pack> p(k);
    for (pack &e:p) {
        scanf("%lld",&e.prime);
        e.value = e.prime;
        e.index = -1;
    }
    vector<long long> res;
    while (n--) {
        auto i = min_element(p.begin(),p.end());
        res.push_back(i->value);
        for (pack &p:p) if (p.value == res.back()) {
            p.value = p.prime * res[++p.index];
        }
    }
    printf("%lld",res.back());
    return 0;
}