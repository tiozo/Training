//#include<felltrees.h>
#include<bits/stdc++.h>
using namespace std;

/*
    O(qn^2)
vector<int> fell_trees(int n,int q,vector<int> x,vector<int>h,vector<int>l,vector<int>r) {
    vector<int> ans(q,0);
    for (int i=0;i<q;++i) {
        int left_lim = (l[i]==0) ? x[0] : x[l[i]-1];
        int right_lim = (r[i]==n-1) ? x[n-1] : x[r[i]+1];
        vector<int> A,B;
        for (int j=l[i];j<=r[i];++j) {
            A.emplace_back(j);
        }
        while (!A.empty()) {
            bool ok = false;
            B.clear();
            for (int j=0;j<(int)A.size();++j) {
                int id = A[j];
                if ((x[id]-h[id]>left_lim && (B.empty() || x[id] - h[id] >= x[B.back()])) || 
                    (x[id]+h[id]<=right_lim && (j==(int)A.size()-1 || x[id] + h[id] <= x[A[j+1]]))) {
                    ok = true;
                    ++ans[i];
                } else {
                    B.emplace_back(id);
                }
            }
            if (!ok) break;
            A.swap(B);
        }
    }
    return ans;
}*/


/*
    O(qn)
vector<int> fell_trees(int n,int q,vector<int> x,vector<int>h,vector<int>l,vector<int>r) {
    vector<int> ans(q,0);
    for (int i=0;i<q;++i) {
        int left_lim = (l[i]==0) ? x[0] : x[l[i]-1];
        int right_lim = (r[i]==n-1) ? x[n-1] : x[r[i]+1];
        vector<int> st;
        for (int j=l[i];j<=r[i];++j) {
            st.emplace_back(j);
            while (!st.empty()) {
                int id = st.back(); st.pop_back();
                if ((x[id]-h[id]>=left_lim && (st.empty() || x[id] - h[id] >= x[st.back()])) || 
                    (x[id]+h[id]<=right_lim && (j==r[i]|| x[id] + h[id] <= x[j+1]))) {
                    ++ans[i];
                } else {
                    st.emplace_back(id);
                    break;
                }
            }
        }
    }
    return ans;
}
*/

//O((n+q)log(n))//
int N;
vector<int> lt,rt,st,a,b,fen,ans;
vector<vector<int>> part;

void upgrade(int p,int v) {
    for (; p < N; p = p | (p + 1)) {
        fen[p] += v;
    }
}

int get(int p) {
    int r = 0;
    for (; p >= 0; p = (p & (p + 1)) - 1) {
        r += fen[p];
    }
    return r;
} 

void bs(vector<int> &a,vector<int> &x,vector<int>&h) {
    for (int i=0;i<N;++i) {
        a[i] = -1;
        lt[i] = 0;
        rt[i] = N-1;
    }
    while (true) {
        bool ok = false;
        for (int i=0;i<N;++i) {
            if (lt[i]<=rt[i]) {
                part[(lt[i]+rt[i])>>1].emplace_back(i);
                ok = true; 
            }
        }
        if (!ok) break;
        for (int md=0;md<N;++md) {
            st.clear();
            for (int i:part[md]) {
                if (i<md) {
                    rt[i] = md - 1;
                    continue;
                }
                while (!st.empty()) {
                    int j = st.back();
                    if (x[j]+h[j]<=x[i]) {
                        st.pop_back();
                    } else {
                        break;
                    }
                }
                int k = st.empty() ? x[max(md-1,0)] : x[st.back()];
                if (x[i] - h[i]>=k) {
                    a[i] = md;
                    lt[i] = md + 1;
                } else {
                    rt[i] = md - 1;
                    st.emplace_back(i);
                }
            }
            part[md].clear();
        }
    }
}

vector<int> fell_trees(int n,int q,vector<int> x,vector<int> h,vector<int> l,vector<int> r) {
    N = n;
    lt.resize(N);
    rt.resize(N);
    st.resize(N);
    a.resize(N);
    b.resize(N);
    fen.resize(N);
    part.resize(N);
    ans.resize(q);
    bs(a,x,h);
    for (int i=0;i<N;++i) {
        x[i] = -x[i];
    }
    reverse(x.begin(),x.end());
    reverse(h.begin(),h.end());
    bs(b,x,h);
    reverse(b.begin(),b.end());
    for (int i=0;i<N;++i) {
        b[i] = N-1-b[i];
    }
    vector<pair<pair<int,int>,int>> e, queries;
    for (int i=0;i<N;++i) {
        e.push_back({{a[i],i},+1});
        e.push_back({{i,b[i]},+1});
        e.push_back({{a[i],b[i]},-1});
    }
    for (int i=0;i<q;++i) {
        queries.push_back({{l[i],r[i]},i});
    }
    sort(e.rbegin(),e.rend());
    sort(queries.rbegin(),queries.rend());
    int j = 0;
    for (auto w:queries) {
        while (j<(int)e.size() && e[j].first.first >= w.first.first) {
            upgrade(e[j].first.second,e[j].second);
            ++j;
        }
        ans[w.second] = get(w.first.second);
    }
    return ans;
}