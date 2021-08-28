#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int R,C;
    cin >> R >> C;
    queue<pair<int,int> > q;
    pair<int,int> End;
    vector<vector<int> > a(R+1, vector<int> (C+1,0));
    vector<vector<bool> > mark(R+1,vector<bool> (C+1,0));
    for (int i=1;i<=R;++i) {
        for (int j=1;j<=C;++j) {
            char ch;
            cin >> ch; 
            a[i][j] = (ch == '*');
            if (ch=='B') q.push(pair<int,int>(i,j));
            if (ch=='C') End = make_pair(i,j);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        int length = q.size();
        for (int loop = 0; loop < length; loop++ ) {
            int i = q.front().first, j=q.front().second; q.pop();
            for (int k=0;k<4;k++) {
                int x = i+dx[k]; int y=j+dy[k];
                if (x<1 || x>R || y<1 || y>C || mark[x][y]==true ||a[x][y] == 1) continue;
                mark[x][y] = true;
                if (x==End.first && y==End.second) {
                    cout << cnt;
                    return 0;
                }
                q.push(pair<int,int>(x,y));
            }
        }
    }
    return 0;
}