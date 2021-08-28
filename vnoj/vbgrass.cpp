#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moveset = {{-1,0},{0,-1},{1,0},{0,1}};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,res=0; cin >> r >> c;
    vector<string> a(r+1);
    for (int i=1;i<=r;++i) cin >> a[i];
    for (int i=1;i<=r;++i) {
        for (int j=0;j<c;++j) {
            if (a[i][j]=='#') {
                ++res;
                stack<pair<int,int>> s;
                s.push({i,j});
                while (!s.empty()) {
                    int u = s.top().first, v = s.top().second; s.pop();
                    for (auto &move:moveset) {
                        int x = u + move.first, y = v + move.second;
                        if (x>0 && y>=0 && x<=r && y<c && a[x][y]=='#') {
                            a[x][y] = '.';
                            s.push({x,y});
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}