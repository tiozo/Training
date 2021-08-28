#include<bits/stdc++.h>
using namespace std;

#define inf 1e9+5
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

int N,M;
pair<int,int> P;
string s[22];
vector<pair<int,int>> a(25);
vector<pair<int,int>> moveset{{0,1},{0,-1},{1,0},{-1,0}};

bool thoaman(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M && s[r][c] != 'x');
}

int BFS(pair<int,int> start,pair<int,int> End) {
    queue<pair<int,int>> q;
    vector<vector<int>> check(25,vector<int>(25,-1));
    q.push(start);
    check[start.first][start.second] = 0;
    while (!q.empty()) {
        auto tmp = q.front(); 
        int u = tmp.first, v=tmp.second; q.pop();
        if (tmp == End) return check[u][v];
        for (auto move:moveset) {
            int x = u + move.first, y = v + move.second;
            if (thoaman(x,y) && check[x][y]==-1) {
                check[x][y] = check[u][v] + 1;
                q.push({x,y});
            } 
        }
    }
    return inf;
}

int main() {
    while (true) {
        int run = 0; cin >> M >> N;
        if (N==0 && M==0) break;
        for (int i=0;i<N;++i) {
            cin >> s[i];
            for (int j=0;j<M;++j) {
                if (s[i][j]=='o') P = {i,j};
                else if (s[i][j]=='*') a[run++] = {i,j};
            }
        }
        vector<vector<int>> f1(15,vector<int>(15,0));
        vector<vector<int>> f((1<<12)+1,vector<int>(15,inf));
        vector<int> d(15,0);
        for (int i=0;i<run;++i) {d[i] = BFS(P,a[i]);}
        for (int i=0;i<run;++i) for (int j=0;j<run;++j) if (i!=j) f1[i][j] = BFS(a[i],a[j]);
        int res = inf;
        for (int i=1;i<=(1<<run)-1;++i) for (int j=0;j<run;++j) if (getbit(i,j)) {
            if (cntbit(i)==1) {
                f[i][j] = d[j];
                continue;
            }
            for (int k=0;k<run;++k) if (getbit(i,k)) {
                f[i][j] = min(f[i][j],f[i-(1<<j)][k]+f1[k][j]);
            }
            if (i==(1<<run)-1) res = min(res,f[i][j]);
            //cout << f[i][j] << ' ';
        }
        //cout << endl;
        if (res>=inf) res = -1;
        cout << res << '\n';
    }
    return 0;
}