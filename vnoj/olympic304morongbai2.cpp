#include<bits/stdc++.h>
using namespace std;

bool printed = false, cant=false;
priority_queue<int,vector<int>,greater<>> pq;
map<pair<int,int>,bool> m;
void divide(int a,int b,int step) {
    if (a==b) {
        pq.push(step);
        return;
    }
    if (m[{a,b}]) {
        return;
    }
    if (printed) return;
    //cout << a << ' ' << b << '\n';
    m[{a,b}] = true;
    if (a<b) swap(a,b);
    if (a%2==0) divide(a*1/2,b,step+1);
    if (a%3==0) divide(a*1/3,b,step+1);
    if (a%5==0) divide(a*1/5,b,step+1);
    if (a%2!=0 && a%3!=0 && a%5!=0) {
        return;
    }
}

int main() {
    //srand(1e9);
    //cout << rand() << ' ' << rand() << '\n';
    int a,b; cin >> a >> b;
    divide(a,b,0);
    if (pq.size()==0) cout << "-1\n"; 
    else cout << pq.top() << '\n';
    return 0;
}