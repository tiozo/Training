#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string s,t;
    for (int i=1;i<=N;++i) s+=to_string(i);
    t=to_string(N);
    int pos = s.find(t);
    cout << pos+1;
    return 0;
}