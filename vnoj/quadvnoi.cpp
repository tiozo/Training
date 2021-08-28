#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> d(2501,0);
    int N,kq=0;
    cin >> N;
    int gh = (N/2) + (N%2);
    for (int i=2;i<=2500;++i) {
        for (int j=1;j<=i-1;++j) {
            if (j<gh && i-j<gh) ++d[i]; 
        }
    }
    for (int i=2;i<=N-2;++i) {
        kq+=d[i]*d[N-i];
    }
    cout << kq;
    return 0;
}