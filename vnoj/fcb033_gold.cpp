#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+1;
int a[maxn][maxn];
vector< array<long long, 3> > x;;

bool cmp(array<long long, 3> &u, array<long long, 3> &v){
	return max(u[0], u[1]) >= max(v[0], v[1]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N,M; cin >> N >> M;
    for (int i=1;i<=N;++i) {
        long long d = 0, e = 0;
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
            if (a[i][j]>0) {
                d+=a[i][j];
            } else e-=a[i][j];
        }
        x.push_back({d,e,i});
    }
    sort(x.begin(),x.end(),cmp);
    if (N==1) {
        cout << max(x[0][0],x[0][1]) << '\n';
    } else {
        cout << max(x[0][0],x[0][1]) + max(x[1][0], x[1][1]) << '\n';
    }
    return 0;
}