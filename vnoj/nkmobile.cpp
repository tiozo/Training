#include<bits/stdc++.h>
using namespace std;

class _2DBIT {
private:
    vector<vector<int> > T;
public:
    _2DBIT(int size) {
        T.resize(size+1);
        for (int i=0;i<=size;++i) {
            T[i].resize(size+1,0);
        }
    }
    void update(int size,int x,int y,int val) {
        for (int i=x; i<=size; i+=i&-i) {
            for (int j = y; j<=size; j+=j&-j) {
                T[i][j] += val;
            }
        }
    }
    int sum(int size,int x,int y) {
        int res=0;
        for (int i=x; i; i-=i&-i) {
            for (int j = y; j; j-=j&-j) {
                res += T[i][j];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int control,S;
    cin >> control >> S;
    _2DBIT tree(S);
    while (1) {
        cin >> control;
        switch (control){
            case 1: {
                int x,y,a;
                cin >> x >> y >> a;
                tree.update(S,++x,++y,a);
                break;
            }
            case 2: {
                int l,b,r,t;
                cin >> l >> b >> r >> t;
                ++l; ++b; ++r; ++t;
                cout << tree.sum(S,r,t)-tree.sum(S,r,b-1)-tree.sum(S,l-1,t)+tree.sum(S,l-1,b-1) << '\n';
                break;
            }
        }
        if (control == 3) {
            break;
        }
    } 
    return 0;
}