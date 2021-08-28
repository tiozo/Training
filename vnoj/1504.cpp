#include<bits/stdc++.h>
using namespace std;

const int oo=1e9;
const int maxval=2*1e5;
vector<int> dis1(maxval+1,0),dis2(maxval+1,0),cnt1(maxval+1,0),cnt2(maxval+1,0),trace1(maxval+1,0),trace2(maxval+1,0);

int counter(vector<int>&dis1,vector<int>&cnt1,vector<int>&dis2,vector<int>&cnt2,vector<int>&trace1,vector<int>&trace2,int N) {
    int res=0;
    for (int u=1;u<=N;++u) {
        for (int v=1;v<=N;++v) {
            if (trace1[u]==trace2[v] && trace2[u]==trace1[v] && u!=v) {
                ++res;
                cout << trace1[u] << ' ' << trace1[v] << ' ' << trace2[u] << ' ' << trace2[v] << '\n';
            }
        }
    }
    return res;
}

int minDistance(vector<int>&dist, vector<bool> &sptSet,int N)
{
    int min = INT_MAX, min_index;

    for (int v = 1; v <= N; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(vector<vector<int> > maps, int src,int N)
{
    vector<int>dist(N+1,oo);
    vector<int>trace(N+1,0);
    vector<int>cnt(N+1,0);
    vector<bool> sptSet(N+1,false);
    dist[src] = 0;
    for (int count = 1; count <=N ; count++) {
        int u = minDistance(dist, sptSet,N);
        sptSet[u] = true;
        for (int v = 1; v <= N; v++)
            if (!sptSet[v] && maps[u][v] && dist[u] != INT_MAX
                && dist[u] + maps[u][v] < dist[v]) {
                dist[v] = dist[u] + maps[u][v];
                trace[v]=u;
            } else if (!sptSet[v] && maps[u][v] && dist[u] != INT_MAX
                && dist[u] + maps[u][v] == dist[v])
                ++cnt[v];
    }
    if (src==1) {
        dis1=dist;
        trace1=trace;
        cnt1=cnt;
    } else {
        dis2=dist;
        trace2=trace;
        cnt2=cnt;
    }
}

int main() {
    freopen("input.inp","r",stdin);
    int N,M;
    cin >> N >> M;
    vector<vector<int> > maps(N+1,vector<int> (N+1,0));
    for (int i=1;i<=M;++i) {
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        cin >> maps[tmp1][tmp2];
        maps[tmp2][tmp1]=maps[tmp1][tmp2];
    }
    dijkstra(maps,1,N);
    dijkstra(maps,N,N);
    cout << counter(dis1,dis2,cnt1,cnt2,trace1,trace2,N);
    return 0;
}
