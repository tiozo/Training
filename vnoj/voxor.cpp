#include<bits/stdc++.h>
using namespace std;

struct trie {
    int child[2],con,fin;
};  

int flip[50],n,cnt;
trie a[2000005];

void insert(char *s) {
    int now = 0;
    for (int i=0;i<32;i++) {
        int k = s[i] - '0';
        if (!a[now].child[k]) a[now].child[k] = ++cnt;
        now = a[now].child[k];
        a[now].con++;
    }
    a[now].con--;
    a[now].fin++;
}

void update(int x) {
    for (int i=32;i>=1;i--) {
        flip[i]=(flip[i]+((x>>(i-1))&1))%2;
    }
}

int get(int k)
{
    int res=0; int now=0;
    for (int i=32; i>=1; i--)
    {
        if (a[now].child[1]) {
            if (!flip[i]) {
                int tmp=a[now].child[1];
                if (k-a[tmp].con-a[tmp].fin<=0) {
                    now=tmp;
                    k-=a[tmp].fin;
                    res=(res<<1)|1;
                } else {
                    k-=a[tmp].con+a[tmp].fin;
                    tmp=a[now].child[0];
                    now=tmp;
                    k-=a[tmp].fin;
                    res=res<<1;
                }
            } else {
                int tmp=a[now].child[0];
                if (k-a[tmp].con-a[tmp].fin<=0) {
                    now=tmp;
                    k-=a[tmp].fin;
                    res=res<<1|1;
                } else {
                    k-=a[tmp].con+a[tmp].fin;
                    tmp=a[now].child[1];
                    now=tmp;
                    k-=a[tmp].fin;
                    res=(res<<1);
                }
            }
        } else {
            int tmp=a[now].child[0];
            now=tmp;
            k-=a[tmp].fin;
            if (!flip[i]) {
                res=res<<1;
            } else res=(res<<1)|1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef _DELL  
        freopen("input.inp","r",stdin);
    #endif
    int N,Q; cin >> N >> Q;
    for (int i=1;i<=N;++i) {
        int x; cin >> x;
        char s[33];
        for (int j=32;j>=1;j--) {
            s[32-j] = char(((x>>(j-1))&1)+'0');
        }
        insert(s);
    }
    while (Q--) {
        char s[10];
        int x; cin >> s >> x;
        if (s[0]=='X') {
            update(x);
        } else {
            int k = get(x);
            cout << k << '\n';
        }
    }
    return 0;
}