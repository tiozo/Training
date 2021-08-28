#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using Tri = array<int,3>;
const int mod = 1e9+7;

struct Data {
    int v; 
    explicit operator int() const {
        return v;
    }
    Data() {v=0;}
    Data(long long _v): v(_v%mod) { v+= (v<0)*mod; }
};

Data& operator += (Data&a,Data b) {
    if ((a.v+=b.v)>=mod) a.v-=mod;
    return a;
}
Data& operator -= (Data&a,Data b) {
    if ((a.v-=b.v)<0) a.v+=mod;
    return a;
}
Data operator * (Data a,Data b) {return Data((long long)a.v*b.v);}
Data& operator *= (Data&a,Data b) {
    return a = a*b;
}
Data operator + (Data a,Data b){return a+=b;}
Data operator - (Data a,Data b){return a-=b;}

vector<Data> f[100][100][100];
int N; 
vector<pii> points;

pii& operator -= (pii &a,const pii &b) {
    a.first -= b.first, a.second -= b.second;
    return a;
}

int cross(pii a,pii b,pii c) {
    b-=a; c-=a;
    return b.first*c.second-b.second*c.first;
}

inline int area(Tri a) {
    return abs(cross(points[a[0]],points[a[1]],points[a[2]]));
}

bool inside(Tri a,int b) {
    int sum = 0;
    for (int i=0;i<3;++i) {
        swap(a[i],b);
        sum+=area(a);
        swap(a[i],b);
    }
    sum-=area(a); assert(sum>=0);
    return sum == 0;
}

inline void ad(vector<Data> &v,int id,Data val) {
    while((int)v.size()<=id) v.push_back(0);
    v[id] += val;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N; points.resize(N);
    for (auto &e:points) cin >> e.first >> e.second;
    vector<Tri> triangle;
    for (int i=0;i<N;++i) {
        for (int j=i+1;j<N;++j) {
            for (int k=j+1;k<N;++k) {
                triangle.push_back({i,j,k});
            }
        }
    }
    sort(triangle.begin(),triangle.end(),[&](Tri a,Tri b) {
        return area(a) < area(b);
    });
    Data ans = 0;
    for (auto&t:triangle) {
        int tot_inside = 0;
        vector<Tri> nex;
        for (int i=0;i<N;++i) {
            if (inside(t,i)) ++tot_inside;
            else {
                for (int j=0;j<3;++j) {
                    auto new_t = t; new_t[j] = i;
                    sort(new_t.begin(),new_t.end());
                    if (inside(new_t,t[j])) nex.push_back(new_t);
                }
            }
        }
        tot_inside -= 3;
        assert(tot_inside>=0);
        f[t[0]][t[1]][t[2]].resize(1+tot_inside);
        f[t[0]][t[1]][t[2]][0] = 1;
        for (int i=0;i<=tot_inside;++i) {
            auto v=f[t[0]][t[1]][t[2]][i];
            if (i<tot_inside) ad(f[t[0]][t[1]][t[2]],1+i,(tot_inside-i)*v);
            for (Tri u:nex) ad(f[u[0]][u[1]][u[2]],1+i,v);
        }
        if (tot_inside==N-3) ans += f[t[0]][t[1]][t[2]][tot_inside];
    }
    cout << (ans*6).v << '\n';
    return 0;
}