#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<long long> F(11);
    F[0]=F[1]=1;
    for (int i=2;i<=10;++i) {
        long long c=1;
        for (int j=1;j<=i;++j) {
            c=c*(i-j+1)/j;
            F[i]+=c*F[i-j];
        }
    }
    while (cin >> n && n!=-1) {
        cout << F[n] << '\n';
    }
    return 0;
}
