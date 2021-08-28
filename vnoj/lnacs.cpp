#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> F(N+3,vector<int> (M+3));
    vector<int> a(N+1);
    vector<int> b(M+1);
    for (int i=1;i<=N;++i) cin >> a[i];
    for (int j=1;j<=M;++j) cin >> b[j];
    ++N; ++M;
    for (int i=1;i<=N+1;++i) {
        for (int j=1;j<=M+1;++j) {
            if (i==1 || j==1) F[i][j] = 0; else 
            if (i==2 || j==2) F[i][j] = a[i-1] == b[j-1] ? 1 : F[i-1][j] > F[i][j-1] ? F[i-1][j] : F[i][j-1];
            else F[i][j] = a[i-1]==b[j-1] ? F[i-2][j-2]+1 : F[i-1][j] > F[i][j-1] ? F[i-1][j] : F[i][j-1];
        }
    }
    cout << F[N][M];
    return 0;
}

/*
    F[i][j] là độ dài dãy còn giống nhau dài nhất của a và b tại phần tử thứ i và j 
    F[i][j] = 1 khi mà phần tử đầu của dãy b giống dãy a nếu không thì gán phần tử dài nhất trước đó của dãy C
    vào F[i][j] hiện tại
    F[i][j] = F[i-2][j-2]+1 khi a và b giống nhau không thực hiện lại như trên.
*/