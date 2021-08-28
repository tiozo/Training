#include<bits/stdc++.h>
using namespace std;

const int mod = 1e5+3;

int main() {
    int N;
    long long M,presum = 0,res = 0; cin >> N >> M;
    vector<long long> a(N+1);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        //presum += a[i];
    }
    /*vector<vector<int>> f(N+1,vector<int>(N+1,0));
    for (int i=0;i<N;++i) {
        f[i][0] = a[i];
        int tmp = M;
        for (int j=i;j<N;++j) {
            if (tmp>=a[i]) {
                f[i][j] = tmp - a[i];
                tmp -= a[j];
            } else {
                f[i][j] =
                tmp = 0;
            }
        }
    }*/
    res = M-a[1];
    //cout << res << ' ';
    cout << a[2]-res+1;
    return 0;
}

/*
    3
    1 3
    1 có 2 state có và không có
    thằng số 3 có 2 state đủ và thiếu
    vị chi là 2 cách chia {1,2} {1,1}
    3 
    1 3 1
    1 có 2 state được phát và không được
    3 có 3 state được phát và thiếu 1 và thiếu 2
    1 có 2 state được phát và không được.
    vị chi là {1,1,1} {1,2,0} {0,2,1} {0,3,0} 4 cách 
    4 5
    1 2 2 3
    1 có 2 state được phát và không
    2 có 3 state được phát và thiểu và không
    2 có 3 state được phát thiếu và không
    3 có 3 state được phát thiểu và không
    vị chi là {1,1,1,2} {1,2,1,1} {1,1,2,1} {1,0,2,2} {1,2,0,2} {}
    [][][][][]
    f[i][j]
    g[i][j] 
    nếu M >= N thì có nghĩa là đã có 1 cách phát
    M < N thì có 
    4 5 
    1 2 2 3
    xét cặp 1-2 
    1 có 2 trạng thái phát và ko đc
    2 có 2 trạng thái phát đủ phát thiếu và không được
    {1,2} {1,1} {1,0} {0,2} {0,1} {0,0}

    5
    2 4
    1 có các trường hợp sau 0 1 2
    2 có các trường hợp sau 0 1 2 3 4
    vì bài toán hướng đến việc phát cho toàn bộ N học sinh, song có thể có học sinh không có chiếc nào thì => phát cho nhiều học sinh hết mức có thể và với mỗi cách phát nhiều nhất đó thì có bao nhiêu cách giống nhau.


    2 15
    10 12
    
    10 5
    9 6 
    8 7
    7 8
    6 9
    5 10
    4 11
    3 12


    2 3
    1 3

    1 2
    0 3
*/