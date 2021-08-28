#include <bits/stdc++.h>
using namespace std;

const int MAXVAL=100000;
vector<int> T(MAXVAL+1,1000000002);
struct CT {
    int R1;
    int R2;
    int R3;
};

bool cmp(CT left,CT right) {
    return left.R1<right.R1;
}

void update(int p,int val) {
    for (int i=p;i<=MAXVAL;i+=i&-i) {
        T[i]=min(T[i],val);
    }
}

int get(int p) {
    int res=1000000002;
    for (int i=p;i;i-=i&-i) {
        res=min(res,T[i]);
    }
    return res;
}

void input(int n,vector<CT> &cts) {
    for (int i=1,tmp;i<=n;++i) {
        cin >> tmp;
        cts[tmp].R1=i;
    }
    for (int i=1,tmp;i<=n;++i) {
        cin >> tmp;
        cts[tmp].R2=i;
    }
    for (int i=1,tmp;i<=n;++i) {
        cin >> tmp;
        cts[tmp].R3=i;
    }
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<CT> cts(n+1,{0,0,0});
    input(n,cts);
    sort(cts.begin(),cts.end(),cmp);
    int kq=0;
    for (int i=1;i<=n;++i) {
            if (get(cts[i].R2)>cts[i].R3) {
                kq++;
            }
        update(cts[i].R2,cts[i].R3);
    }
    cout << kq;
    return 0;
}
