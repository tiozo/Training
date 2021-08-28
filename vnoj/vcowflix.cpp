#include<bits/stdc++.h>
using namespace std;

const int maxC=5000;

int main() {
    int C,N;
    cin >> C >> N;
    vector<int> W(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> W[i];
    }
    vector<int> F(maxC+1,0);
    F[0]=1;
    for (int i=1;i<=N;++i) {
        for (int j=C;j>=W[i];j--) {
            F[j] = F[j] | F[j-W[i]];
        }
    }
    for (int i=C;i>=1;--i) {
        if (F[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
