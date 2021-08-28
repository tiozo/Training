#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int dem = 0;
    for (int i=4;;++i) {
        int tmp = i;
        while (tmp>0) {
            ++dem;
            tmp/=10;
        }
        if (dem==n) {
            cout << i << '\n';
            return 0;
        } else if (dem>n) {
            return 0;
        }
    }
    return 0;
}

/*
explain: 4 5 6 7 8 9 1 0 1 1
*/