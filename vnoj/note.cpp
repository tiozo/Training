#include<bits/stdc++.h>
using namespace std;

bool check(int N,int M) {
    int mid = 1 << (N-1);
    return M == mid ? 1 : M < mid ? !check(N-1,mid-M) : check(N-1,M-mid);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    while (cin >> N >> M) {
        if (N==0 && M==0) break;
        cout << (check(N,M)==1 ? "D" : "U" ) << '\n';
    }
    return 0;
}