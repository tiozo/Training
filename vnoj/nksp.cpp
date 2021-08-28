#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> S;
    N=S.size();
    vector<vector<int> > F(N+1,vector<int> (N+1,0));
    for (int i=0;i<N;++i) {
        F[i][i]=1;
    }
    for (int i=0;i+1<N;++i) F[i][i+1] = S[i] == S[i+1];
    for (int i=N-1;i>=0;--i) {
        for (int j=i+2;j<N;++j) {
            F[i][j]= S[i] == S[j] && F[i+1][j-1];
            for (int p=i+1;!F[i][j] && p+1<j ; ++p) {
                F[i][j] |= F[i][p] && F[p+1][j];
            }
        }
    }
    int res=0;
    for (int i=0;i<N;++i) {
        for (int j=i+1;j<N;++j) {
            if (F[i][j]) ++res;
        }
    }
    cout << res;
    return 0;
}
