#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,P; cin >> N >> P;
    int A,B,R; cin >> A >> B >> R;
    vector<int> vis(P,1e9+1);
    queue<pair<int,int>> q;
    q.push({(N+A)%P,1}); vis[(N+A)%P] = 1;
    q.push({(N+B)%P,1}); vis[(N+B)%P] = 1;
    q.push({(N+A+B)%P,1}); vis[(N+A+B)%P] = 1;
    while (!q.empty()) {
        int num = q.front().first, cur_step = q.front().second; 
        q.pop();
        if (num==R) {
            cout << cur_step << '\n';
            return 0;
        }
        if (cur_step+1<vis[(num+A)%P]) {
            q.push({(num+A)%P,cur_step+1});
            vis[(num+A)%P] = cur_step + 1;
        }
        if (cur_step+1<vis[(num+B)%P]) {
            q.push({(num+B)%P,cur_step+1});
            vis[(num+B)%P] = cur_step + 1;
        }
        if (cur_step+1<vis[(num+A+B)%P]) {
            q.push({(num+A+B)%P,cur_step+1});
            vis[(num+A+B)%P] = cur_step + 1;
        }
    }
    cout << -1;
    return 0;  
}