#include<bits/stdc++.h>
using namespace std;

struct Data {
    long long val,index;
    Data() {};
    Data(int val,int index): val(val), index(index) {}
    bool operator < (const Data &a) const {
        return val != a.val ? val < a.val : index < a.index;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int N; cin >> N;
        vector<Data> a(N,{0,0});
        for (int i=0;i<N;++i) {
            cin >> a[i].val;
            a[i].index = i;
        }
        sort(a.begin(),a.end());
        //for (Data &a:a) cout << a.val << ' ';
        long long cur = a[0].val;
        long long ans = 0;
        long long sumOfPassed = 0;
        for (int i=0;i<N;++i) {
            if (a[i].val != cur) {
                sumOfPassed=a[i].index+1;
                cur=a[i].val;
            } else {
                ans += sumOfPassed*(N-a[i].index);
                sumOfPassed+=a[i].index+1;
            }
        }
        cout << ans << '\n'; 
    }
    return 0;
}