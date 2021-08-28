#include<bits/stdc++.h>
using namespace std;
queue<pair<pair<int,pair<int,int>>,int>> Q;
vector<pair<int,pair<int,int>>> a1;
vector<pair<pair<int,pair<int,int>>,int>> c;
int vis[10][10][10] = {0};
int main()
{
    //freopen("input.inp","r",stdin);
    int k,z,s,m,z0,s0,m0,z1,s1,m1,z2,s2,m2;
    cin >> k;
    cin >> z >> s >> m >> z0 >> s0 >> m0;
    vis[z][s][m] = 1;
    Q.push({{z,{s,m}},0});
    while(cin >> z2 >> s2 >> m2 >> z1 >> s1 >> m1)
    {
        a1.push_back({z1 - z2,{s1 - s2,m1 - m2}});
    }
    if(z>=z0 && s>=s0 && m>=m0) c.push_back({{z,{s,m}},0});
    else
    {
       while(!Q.empty())
    {
        int z = Q.front().first.first;
        int s = Q.front().first.second.first;
        int m = Q.front().first.second.second;
        int cnt = Q.front().second;
        Q.pop();
        if (z>=z0 && s>=s0 && m>=m0) c.push_back({{z,{s,m}},cnt});
        else 
            for(int i=0;i<(int)a1.size();++i)
            {
                int z1 = z + a1[i].first;
                int s1 = s + a1[i].second.first;
                int m1 = m + a1[i].second.second;
                if(z1<=4 && s1<=4 && m1<=4 && vis[z1][s1][m1]==0)
                {
                        Q.push({{z1,{s1,m1}},cnt+1});
                        //cout << z1 << ' ' << s1 << ' ' << m1 << ' ' << cnt+1 << ' ' << "pushQ" <<endl;
                        vis[z1][s1][m1] = 1;
                        //cout << endl;
                }
            }
    }
    }
    if(c.empty()) cout << -1;
    else
    {
        sort(c.begin(),c.end());
        cout << (int)c.size() << endl;
        for(int i=0;i<(int)c.size();++i)
        {
            cout << c[i].first.first << ' ' << c[i].first.second.first << ' ' << c[i].first.second.second << ' ' << c[i].second << endl;
        }
    }
    return 0;
}