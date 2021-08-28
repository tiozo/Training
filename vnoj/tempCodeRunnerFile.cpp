#include<bits/stdc++.h>
using namespace std;

struct bit {
    const int maxn = 1e6;
    vector<int> t{maxn+10,0};
    void update(int p,int val) {
        for (int i=p;i<=maxn;i+=i&-i) {
            t[i] += val;
        }
    }
    int get(int p) {
        int res = 0;
        for (int i=p;i;i-=i&-i) {
            res += t[i];
        }
        return res;
    }
};  

bit solver;
int main() {
    string s; cin >> s;
    int len = 0;
    for (int i=0;i<s.length();++i) {
        if (s[i]=='7') ++len; else len = 0;
        if (len<1) continue;
        solver.update(len+1,-1);
        solver.update(1,1);
    }
    for (int i=0;i<s.length();++i) {
        int t = solver.get(i);
        if (t<1) return;
        cout << i << ' ' << t << '\n';
    }
    return 0;
}