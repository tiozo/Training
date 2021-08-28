#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define lc id*2
#define rc id*2+1
int N,M;
vector<char> t(4*1e6+10,0);
string s; bool remind = false;

void process(int l,int r,int id) {
    if (t[lc] == '(' && t[rc] == ')') t[id] = 1;
    else if (t[lc] == 1 && t[rc] == 1) t[id] = 1;
    else if (t[lc] == 0 && t[rc] == 0) t[id] = 1;
    else if (t[lc] == ')' && t[rc] == ')') t[id] = 0;
    else if (t[lc] == '(' && t[rc] == '(') t[id] = 0;
    else if (t[lc] == 1 && (t[rc] == ')' || t[rc] == '(')) t[id] = 0;
    else if ((t[lc] ==')' || t[lc]=='(') && t[rc] == 1) t[id] = 0;
    else t[id] = t[lc] & t[rc];
}

void build(int l,int r,int id) {
    if (l>r) return;
    if (l==r && !t[id]) {
        t[id] = s[l-1]; 
        return;
    }
    build(l,mid,lc);
    build(mid+1,r,rc);
    process(l,r,id);
}

void upgrade(int l,int r,int id,int x,char val) {
    if (l>x || r<x) {
        return;
    }
    if (l==r) {
        t[id] = val;
        return;
    }
    upgrade(l,mid,lc,x,val);
    upgrade(mid+1,r,rc,x,val);
    process(l,r,id);
}

char get(int l,int r,int id,int u,int v) {
    if (l>v || r<u) {
        remind = false;
        return 1;
    }
    remind = true;
    if (l>=u && r<=v) {
        if (t[id]==1 || t[id]==0) 
        return t[id];
        return 0;
    }
    char a=get(l,mid,lc,u,v);
    if (!remind) a=2;
    remind = true;
    char b=get(mid+1,r,rc,u,v);
    if (!remind) b=2;
    if (b==2 && a==2) return 1; 
    else if (a==2 && b!=2) return b;
    else if (b==2 && a!=2) return a;
    else return (a^b);
}

int main() {
    freopen("output.out","w",stdout);
    cin >> N >> M;
    cin >> s;
    build(1,N,1);
    for (int i=1;i<=M;++i) {
        int a,b; char c;
        cin >> a >> b;
        if (!a) {
            cin >> c;
            upgrade(1,N,1,b,c);
        } else {
            int c1;
            cin >> c1;
            cout << (int)get(1,N,1,b,c1);
        }
    }
    return 0;
}