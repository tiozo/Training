#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    set<int> s;
    int N,v;
    while (true) {
        cin >> N;
        if (!N) return 0;
        switch (N) {
            case 1: {
                cin >> v;
                s.insert(v);
                break;
            }
            case 2: {
                cin >> v;
                if (s.find(v)!=s.end()) s.erase(s.find(v));
                break;
            }
            case 3: {
                if (s.size() != 0)
                    cout << *s.begin() << '\n';
                else cout << "empty\n";
                break;
            }
            case 4: {
                if (s.size()==0) cout << "empty\n";
                else {cout << *s.rbegin() << '\n';}
                break;
            }
            case 5: {
                cin >> v;
                if (s.size()==0) cout << "empty\n";
                else {
                    auto it = s.upper_bound(v);
                    if (it==s.end()) cout << "no\n";
                    else cout << *it << '\n';
                }
                break;
            }
            case 6: {
                cin >> v;
                if (s.size()==0) cout << "empty\n";
                else {
                    auto it = s.lower_bound(v);
                    if (it==s.end()) cout << "no\n"; else
                    cout << *it << '\n';
                }
                break;
            }
            case 7: {
                cin >> v;
                if (s.size()==0) cout << "empty\n";
                else {
                    auto it = s.lower_bound(v);
                    if (it==s.end()) --it;
                    while (it!=s.begin()) {
                        if (*it<v) break;
                        --it;
                    }
                    if (*it<v) cout << *it << '\n';
                    else cout << "no\n";
                }
                break;
            }
            case 8: {
                cin >> v;
                if (s.size()==0) cout << "empty\n";
                else {
                    auto it = s.lower_bound(v);
                    if (it==s.end()) --it;
                    while (it!=s.begin()) {
                        if (*it<=v) break;
                        --it;
                    }
                    if (*it<=v) cout << *it << '\n';
                    else cout << "no\n";
                }
                break;
            }
        }
    }
    return 0;
}