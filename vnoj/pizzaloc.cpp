#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

class res{
public:
    int gnum, a[101] = {0};
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int K,R,M,N;
    cin >> K >> R >> M;
    pair<int,int> a[21];
    pair<pair<int,int>,int> b[101];
    res f[21];
    for (int i=1;i<=M;++i) {
        cin >> a[i].x >> a[i].y;
    }
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> b[i].x.x >> b[i].x.y >> b[i].y;
    }
    for (int i=1;i<=M;++i) {
        f[i].gnum=0;
        for (int j=1;j<=N;++j) {
            if ((b[j].x.x-a[i].x)*(b[j].x.x-a[i].x)+(b[j].x.y-a[i].y)*(b[j].x.y-a[i].y)<=R*R) {
                f[i].gnum++;
                f[i].a[f[i].gnum] = j;
            }
        }
    }
    int kq=0;
    int state[101],inR[21];
    for (int i=1;i<=K;++i) inR[i] = i; 
    while (true) {
        int Max = 0;
        for (int i=1;i<=N;++i) {
            state[i] = 0;
        }
        for (int i=1;i<=K;++i) {
            for (int j=1;j<=f[inR[i]].gnum;++j) {
                if (state[f[inR[i]].a[j]]==0) {
                    state[f[inR[i]].a[j]] = 1;
                    Max += b[f[inR[i]].a[j]].y;
                }
            }
        }
        kq = max(Max,kq);
        if (inR[K]<M) {
            inR[K]++;
        } else {
            int fl = K-1;
            while (fl>0) {
                if (inR[fl]+1!=inR[fl+1]) {
                    break;
                }
                fl--;
            } 
            if (fl==0) break;
            else {
                inR[fl]++;
                for (int i=fl+1;i<=K;++i) {
                    inR[i] = inR[i-1]+1;
                }
            }
        }
    }
    cout << kq;
    return 0;  
}