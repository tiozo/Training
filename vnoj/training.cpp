#include<bits/stdc++.h>
using namespace std;

signed int main() {
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("training.inp","r",stdin);
    freopen("training.out","w",stdout);
    int N,M;
    cin >> N >> M;
    vector<int> a(N+1);
    vector<pair<int,int> > c(N+1);
    vector<int> b(M+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        c[i] = make_pair(a[i],i);
    }
    sort(c.begin()+1,c.end());
    for (int j=1;j<=M;++j) {
        cin >> b[j];
    }
    sort(b.begin()+1,b.end());
    int carry = 0,contin = 0;
    for (int i=1;i<=N;++i) {
        if (i==1)
            for (int j=1;j<=M;++j) {
                if (c[i].first>=b[j]) {
                    c[i].first += b[j];
                    carry += b[j];
                    contin = j+1;
                } else break;
            }
        else {
            c[i].first += carry;
            for (int j=contin;j<=M;++j) {
                if (c[i].first>=b[j]) {
                    carry += b[j];
                    c[i].first +=b[j];
                    contin = j+1;
                } else break;
            }
        }
        if (!contin) contin = 1;
    }
    for (int i=1;i<=N;++i)
        a[c[i].second] = c[i].first;
    for (int i=1;i<=N;++i) {
        cout << a[i] << ' ';
    }
}