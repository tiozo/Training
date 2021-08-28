#include<bits/stdc++.h>
using namespace std;

const long long limit = 1234567890;
const int maxn = 1000000;
long long res[maxn+1],d[maxn+1],d1[maxn+1];

void process(long long n,long long k) {
    if (k==0) {
        cout << min(n-1,limit+1) << '\n';
        return;
    }
    res[1]=0;
    for (long long i=2;i<=n;++i) {
        res[i] = i-1;
        for (long long j=max((long long)1,i-k);j<=i-1;++j) {
            res[i] = res[i] + res[j];
        }
        if (res[i]>limit) {
            cout << res[i] << '\n';
            return;
        }
    }
    cout << res[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n,k;
    while (cin >> n >> k) {
        if (!n) return 0;
        process(n,k);
    }
    //return 0;
}

/*
    n = 10 k = 1
    1 = 0
    2 = 1 0
    3 = 2 1 0
    4 = 3 2 1 0
    5 = 
    n = 10 k = 2 ans = 221
    1 = 0
    2 = 1 0
    3 = 2 1 0 0
    4 = 3 2 1 1 0 0 0
    5 = 4 3 2 2 1 1 1 va 5 so 0
    6 = 5 4 3 3 2 2 2 va 5 so 1 va 8 so 0
    7 = 6 5 4 4 3 3 3 va 5 so 2 va 8 so 1 va 13 so 0
    8 = 7 6 5 13 21
    9 = 8 7 6 21 55
    10= 9 8 7 7 6 6 6 
    cong thuc = (n-k)+(k he so truoc do) voi moi k
    k = 3 phải bao hàm cả 2 và 1 
    1 = 0
    2 = 1 0
    3 = 2 1 0 0
    4 = 3 2 1 1 0 0 0 0
    5 = 4 3 2 2 1 1 1 1 0 0 0 0 0 0 0
    6 = 5 4 3 3 2 2 2 2 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    7
    8
    9
    10
    k = 4
    day la bài quy hoạch cơ bản, chỉ cần tính chủ yếu là n và k bằng bao nhiêu trước khi 
    gặp 1234567890.
*/