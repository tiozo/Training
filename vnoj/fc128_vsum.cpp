#include<bits/stdc++.h>
using namespace std;

vector<int> f = {0,2,1,2,0,2,1,2,0,2,1};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    cout << f[N];
    return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
1 -> 2 maybe even maybe odd
2 -> 1 and 2 or any close will be odd 
3 -> 2 may have 2 odd then it will be even maybe had 2 even then it odd 
4 -> 0 certainly even 
5 -> 2 
6 -> 1
7 -> 2 
8 -> 0
9 -> 2
10 -> 1*/
