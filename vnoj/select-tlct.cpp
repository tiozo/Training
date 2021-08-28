#include<bits/stdc++.h>
using namespace std;

int N,sumMax=0;
vector<int> f;
vector<vector<int>> a;
int getIthBit(int N,int index) {
    return (N>>index)&1;
}

int turnoff(int N,int index) { 
    return N&~(1<<index);
}

int getMax(int mask) {
    vector<int> b(1,0); int k = 0;
    for (int j=1;j<=N;++j) {
        if (getIthBit(mask,j-1)) {
            ++k;
            b.push_back(j);
        }
    }
    int Max = 0,premask;
    for (int j=1;j<=k;++j) {
        premask = turnoff(mask,b[j]-1);
        Max = max(f[premask] + a[k][b[j]],Max);
    }
    return Max;
}

void DPBitMask() {
    f[0] = 0;
    int first = 1,last = (1<<N)-1;
    for (int i=first;i<=last;++i) {
        f[i] = getMax(i);
    }
    sumMax = f[last];
}

int main() {
    cin >> N;
    a = vector<vector<int>>(N+1,vector<int>(N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    f.resize((1<<(N+1)));
    DPBitMask();
    cout << sumMax;
    return 0;
}