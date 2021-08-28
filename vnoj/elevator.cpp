#include<bits/stdc++.h>
using namespace std;

struct data {
    int h; //height
    int a; // limit
    int c; // contain
};

bool cmp(data l, data r) {
    if (l.a==r.a) {
        return l.h<r.h;
    }
    return l.a<r.a;
}

int main() {
    int N;
    cin >> N;
    vector<data> e(N+1,{0,0,0});
    for (int i=1;i<=N;++i) {
        cin >> e[i].h >> e[i].a >> e[i].c;
    }
    long long res=0;
    sort(e.begin(),e.end(),cmp);
    vector<vector<long long> > F(405,vector<long long> (40005,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=e[i].a;++j) {
            for (int t=0;t<=e[i].c;++t) {
                if (j>=t*e[i].h && j-t*e[i].h<=e[i-1].a) {
                    F[i][j]=max(F[i][j],F[i-1][j-t*e[i].h]+t*e[i].h);
                    res=max(res,F[i][j]);
                }
            }
        }
    }
    cout << res;
    return 0;
}
