#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> a(N+1),b(N+1);
        vector<pair<int,int>>p(1,{0,0});
        for (int i=1;i<=N;++i) {
            cin >> a[i];
        }
        for (int i=1;i<=N;++i) {
            cin >> b[i];
            if (a[i]!=b[i]) p.emplace_back(i,a[i]-b[i]);
        }
        bool printed=0;
        if (p.size()>1) {
            vector<pair<int,int>> ans;
            for (int i=1;i<p.size();++i) {
                for (int j=1;j<=p[p.size()-1].first;++j) {
                    if (p[i].first!=j && p[i].second!=0 && a[p[i].first]!=b[p[i].first]) {
                        if (p[i].second>0) {
                            p[i].second--;
                            a[p[i].first] -= 1;
                            a[j] += 1;
                            ans.emplace_back(p[i].first,j);
                        } else if (p[i].second<0) {
                            p[i].second++;
                            a[p[i].first] += 1;
                            a[j] -= 1;
                            ans.emplace_back(p[i].first,j);
                        }
                    }
                    if (p[i].second==0 || (a[p[i].first]==b[j] && p[i].first==j)) break;
                }
            }
            for (int i=1;i<p.size();++i)
                if (a[p[i].first]!=b[p[i].first]) cout << -1 << '\n', printed = 1;
            if (!printed) {
                cout << ans.size() << "\n";
                for (int i=0;i<ans.size();++i) {
                    cout << ans[i].first << ' ' << ans[i].second << '\n';
                }
            }
        } else cout << 0 << '\n';
    }
    return 0;
}