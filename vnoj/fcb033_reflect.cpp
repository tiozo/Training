#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; 
    double long l,d,x,theta,EXP = 1e-9, pi = acos(-1);
    cin >> N;
    while (N--) {
        cin >> l >> d >> x >> theta;
        if (fabs(theta-90)<=EXP) {
            cout << 0 << '\n';
            continue;
        }
        if (theta>90) {
            theta = 180 - theta;
            x = d-x;
        }
        theta = theta * pi / 180;
        double long a = tan(theta) * x;
        double long b = tan(theta) * d;
        if (l<a) cout << 0 << '\n';
        else {
            int cnt = (l-a)/b;
            cout << cnt + 1 << '\n';
        }
    }
    return 0;
}