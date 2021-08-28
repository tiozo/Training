#include<bits/stdc++.h>
using namespace std;

#define uint unsigned int

class pack {
public: 
    uint w,v;
    bool operator < (const pack&a) const {
        return w<a.w;
    }
    bool operator > (const pack&a) const {
        return w>a.w;
    }
};

void operator += (pack &a,const pack &b) {
        a.w += b.w;
        a.v += b.v;
}

vector<pack> generate(const vector<pack> &a, uint m) {
    vector<pack> res(1<<a.size());
    int n = 0;

    for (int i=0; i < (int)res.size(); i++) {
        pack tmp = {0, 0};
        for (int k=0; k<(int)a.size(); k++) {
            if (i&(1<<k)) tmp += a[k];
        }
        if (tmp.w <= m) res[n++] = tmp;
    }

    res.resize(n);
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; uint m;
    cin >> n >> m;

    int n1 = n / 2;
    int n2 = n - n1;

    vector<pack> a(n1), b(n2);
    for (pack &x: a) cin >> x.w >> x.v;
    for (pack &x: b) cin >> x.w >> x.v;

    vector<pack> f(generate(a, m));
    vector<pack> g(generate(b, m));

    uint result = 0;
    uint max_value = 0;
    for (int i=f.size()-1, j=0; i>=0; i--) {
        while (j<(int)g.size() && f[i].w + g[j].w <= m) {
            max_value = max(max_value, g[j].v);
            j++;
        }
        result = max(result, max_value + f[i].v);
    }

    cout << result;
    return 0;
}