#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N+1,vector<int> (N+1,0));
    vector<vector<int>> prefix(N+1,vector<int> (N+1,0));
    vector<vector<int>> surfix(N+1,vector<int> (N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
            surfix[i][j] = surfix[i-1][j] + surfix[i][j-1] - surfix[i-1][j-1] + a[i][j];
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + ((i+j)%2?a[i][j]:0);
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        cout << abs(surfix[x][y] - surfix[a-1][y] - surfix[x][b-1] + surfix[a-1][b-1]-2*(prefix[x][y]-prefix[a-1][y]-prefix[x][b-1]+prefix[a-1][b-1]));
        cout << '\n';
    }
    return 0;
}