#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b) {
    return abs(a.first.second-a.second.second) < abs(b.first.second - b.second.second);
}
int N;
bool check1[111][1511];
bool check2[111][1511];
set<pair<pair<int,int>,pair<int,int>>,decltype(cmp)*> s(cmp);
void dp(vector<int>&a,int id,int team1,int weight1,int team2,int weight2) {
    if (team1+team2>N && id>N) return;
    if (check1[team1][weight1] && check2[team2][weight2]) return;
    check1[team1][weight1] = true; check2[team2][weight2] = true;
    if ((team1-1==team2 || team2-1==team1) && team1+team2==N)
        s.insert({{team1,weight1},{team2,weight2}});
    //cout << team1 << ' ' << weight1 << ' ' << team2 << ' ' << weight2 << '\n';
    dp(a,id+1,team1+1,weight1+a[id],team2,weight2);
    dp(a,id+1,team1,weight1,team2+1,weight2+a[id]);
}

int main() {
    cin >> N;
    vector<int> a(N);
    for (int &a:a) cin >> a;
    memset(check1,false,sizeof check1);
    memset(check2,false,sizeof check2);
    dp(a,0,0,0,0,0);
    /// first = thanh vien, second = weight;
    for (auto e:s) {
        cout << e.first.first << ' ' << e.first.second << ' ' << e.second.first << ' ' << e.second.second << '\n';
        //break;
    }
    return 0;
}
/*
5
30
70
20
50
40
*/