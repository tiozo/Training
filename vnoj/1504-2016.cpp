#include <bits/stdc++.h>
using namespace std;

struct data {
    int x;
    int y;
};

bool cmp(data left,data right) {
    if (left.x==right.x)
        return left.y<right.y;
    return left.x<right.x;
}

int main() {
    freopen("input.inp","r",stdin);
    int N,M;
    cin >> N >> M;
    int N1=0;
    vector<data> grass(N+1,{-1,-1});
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            char charac;
            cin >> charac;
            if (charac=='#') {
                ++N1;
                grass[N1].x=i;
                grass[N1].y=j;
            }
        }
    }
    sort(grass.begin(),grass.end(),cmp);
    int res=0;
    for (int i=1;i<=N1;++i) {
        if ((grass[i-1].x+1==grass[i].x && grass[i-1].y==grass[i].y) || (grass[i-1].x==grass[i].x && grass[i-1].y+1==grass[i].y) ) {
            ++res;
        }
    }
    cout << res;
    return 0;
}

