#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
struct Point {
    int x, y;
    void rotate() {
        *this = {x - y, x + y};
    }
};
struct Event {
    int x, y, type;
    bool operator < (const Event& oth) const {
        if (x != oth.x) return x < oth.x;
        return type < oth.type;
    }
};
int m, n;
int s, t;
Point ps[maxN];
Point pt[maxN];
struct FenwickTree {
    int n;
    vector<int> fen;
    FenwickTree(int n) : n(n), fen(n + 5) {}
    FenwickTree() {}
    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            fen[i] += v;
    }
    int get(int i) {
        int res = 0;
        for (; i; i -= i & -i)
            res += fen[i];
        return res;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} fen;
long long count(Point a, Point b) {
    long long res = 0;
    for (int x = a.x; x <= b.x; x++) {
        int ly = max({a.y, 2 - x, 2 + x});
        int ry = min({b.y, m * 2 - x, n * 2 + x});
        if ((x - ly) % 2) ly++;
        if ((x - ry) % 2) ry--;
        res += max(0, (ry - ly) / 2 + 1);
    }
    return res;
}
long long check(int len) {
    vector<Event> vec;
    for (int i = 1; i <= s; i++) {
        vec.push_back({ps[i].x - len, ps[i].y, 0});
        vec.push_back({ps[i].x + len, ps[i].y, 2});
    }
    for (int i = 1; i <= t; i++)
        vec.push_back({pt[i].x, pt[i].y, 1});
    sort(vec.begin(), vec.end());

    fen = FenwickTree(m + n);

    Point a = Point{1 - n, 2};
    Point b = Point{m - 1, m + n};

    for (Event& e : vec) {
        if (e.type == 0) fen.update(e.y, 1);
        else if (e.type == 2) fen.update(e.y, -1);
        else if (!fen.get(max(2, e.y - len), min(m + n, e.y + len))) {
            a.x = max(a.x, e.x - len);
            a.y = max(a.y, e.y - len);
            b.x = min(b.x, e.x + len);
            b.y = min(b.y, e.y + len);
        }
    }

    return count(a, b);
}
int bin(int l, int r) {
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (check(mid) > 0) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    cin >> s >> t;
    for (int i = 1; i <= s; i++) {
        cin >> ps[i].x >> ps[i].y;
        ps[i].rotate();
    }
    for (int i = 1; i <= t; i++) {
        cin >> pt[i].x >> pt[i].y;
        pt[i].rotate();
    }
    int ans = bin(0, m + n);
    cout << ans << ' ' << check(ans);
}


2
4 0 1 3 2 3
1 0 1 0 1 1
2 0 1 1 3 3
0 1 1 1 1 1
0 0 1 1 0 1