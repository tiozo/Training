#include<bits/stdc++.h>
using namespace std;

const int maxjob=200;
int N;
vector<vector<int> > C(maxjob+1, vector<int> (maxjob+1,0));
vector<int> my,vs;
bool dfs(int s,int limit) {
    for (int v=1;v<=N;++v)
        if (!vs[v] && C[s][v]<=limit) {
            vs[v] = 1;
            if (my[v] == -1 || dfs(my[v],limit)) return my[v] = s,true; 
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vs.resize(N+1);
    my.resize(N+1);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> C[i][j];
        }
    }
    int L = 0, R=1e9;
    while (L<R) {
        fill(my.begin(),my.end(),-1);
        int mid = (L+R) >> 1; bool ok = true;
        for (int i=1;fill(vs.begin(),vs.end(),0),i<=N && ok;++i) {
            ok &= dfs(i,mid);
        }
        if (ok) R = mid; else L = mid+1;
    }
    cout << L;
    return 0;
}