#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
vector<vector<int>> F(maxn+1,vector<int> (maxn+1,0));
void set_val() {
    for (int i=1;i<=maxn;++i) {
        F[1][i] = 1;
        F[i][1] = 1;
    }    
    for (int i=2;i<=maxn;++i) {
        for (int j=2;j<=maxn;++j) {
            F[i][j] = F[i][j-1]+F[i-1][j-1];
        }
    }
}

int main() {
    int T;
    cin >> T;
    set_val();
    while (T--) {
        int N,M,res;
        cin >> N >> M;
        for (int i=1;i<=maxn;++i) {
            M = M - F[N][i];
            if (M<=0) {
                res = i;
                break;
            }
        }
        cout << res << '\n';
    }
    return 0;
}

/*
    gọi F[i][j] là số lượng trứng và số lần thả tại tầng thứ i;
    biết là nó thả hết toàn bộ quả trứng ở tầng M;
    thế giờ vấn đề là làm sao để biết được số lần thả ở tầng thứ i?
    ta lấy M trừ đi F[N][i] vì cần thả số trứng đó tại tầng i đến khi nào 
    mà ta biết được độ cứng thì ta dừng lại
*/