#include <bits/stdc++.h>
#define maxn 1004
//#define Task ""
#define vt vector
#define pb push_back
#define pii pair <int, int>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define mod 1000000007

using namespace std;
int n, cnt;
string a;
string f[maxn][maxn];

void nhap()
{
    cin >> a;
    n = a.size();
    a = ' ' + a;
}

bool make(string &a, string &b)
{
    int l1 = a.length(), l2 = b.length(), ok = 0;
    if (l1 >= l2) b.insert(0, l1-l2, '0');
    else a.insert(0, l2-l1, '0'), ok = 1;
    return ok;
}

string sum(string a, string b)
{
    string s = "";
    make(a,b);
    int l = a.size();
    int carry = 0;
    for (int i = l-1; i > -1; i--)
    {
        carry = a[i] + b[i] - 96 + carry;
        s = char(carry%10+'0') + s;
        carry /= 10;
    }
    if (carry) s = char(carry + '0') + s;
    return s;
}

string sub (string a, string b)
{
    string s = "";
    int ok = make(a,b);
    if (ok) swap(a, b);
    int l = a.size();
    int carry = 0, pp = 0;
    for (int i = l-1; i > -1; i--)
    {
        pp = 0;
        carry = a[i] - b[i] - carry;
        if (carry < 0) carry += 10, pp = 1;
        s = char (carry+'0') + s;
        carry = pp;
    }
    while(s[0] == '0') s.erase(0, 1);
    if (ok) s = '-' + s;
    return s;
}

void solve()
{
    for (int i = 1; i <= n; i++)
        f[i][i] = '1';

    for (int i = n; i >= 1; i--)
        for (int j = i+1; j <= n; j++)
            if (a[i] == a[j]) f[i][j] = sum(f[i+1][j], sum(f[i][j-1], "1"));
                else f[i][j] = sub(sum(f[i+1][j], f[i][j-1]), f[i+1][j-1]);
    cout << f[1][n];
}

int main()
{
    //freopen(".in", "r", stdin);
    nhap();
    solve();
    return 0;
}
