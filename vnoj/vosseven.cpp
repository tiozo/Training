#include<bits/stdc++.h>
using namespace std;
/*
struct bit {
    const int maxn = 1e6;
    vector<int> t;
    bit() {
        t.assign(maxn+1,0);
    }
    void update(int p,int val) {
        if (p<1 || p>maxn) return;
        //cout << t.size() << ' ';
        for (int i=p;i<=maxn;i+=i&-i) {
            t[i] += val;
            //cout << i << ' ';
        }
    }
    int get(int p) {
        if (p<1 || p>maxn) return 0;
        int res = 0;
        for (int i=p;i>=1;i-=i&-i) {
            res += t[i];
        }
        return res;
    }
};  
bit solver;*/
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int> prefix(s.length()+1,0);
    s = " " + s;
    int len = 0,n=0;
    for (int i=1;i<(int)s.length();++i) {
        if (s[i]=='7') {
            prefix[++len]++;
            n = max(n,len);
        } else len = 0;
    }
    for (int i=n-1;i>0;--i) prefix[i] += prefix[i+1]; 
    for (int i=1;i<=n;++i) 
        cout << i << ' ' << prefix[i] << '\n';
    return 0;
}