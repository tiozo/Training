#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M,K; cin >> N >> M >> K;
    int res = M;
    vector<string> samples(K+1);
    string s,s1; cin >> s;
    s1 = s; s+=s1;
    for (int i=1;i<=K;++i) {
        cin >> samples[i];
    }
    for (int j=1;j<=K;++j) {
        for (int i=0;i<N;++i) {
            int tmp = 0;
            for (int i1=i,i2=0;i2<M && tmp<res; tmp += samples[j][i2++] != s[i1++]);
            res = tmp;
        }
    }
    cout << res;
    return 0;
}

/*
    possible way is by a N^2 solution
    we are sure that M=N in the bad case if not perhaps it is O(M*N*K)
    khoảng cách Hamming giữa một gen mẫu và gen lạ là "số nhỏ nhất" trong 
    "số các khoảng cách Hamming" giữa gen mẫu và những đoạn gen gồm 
    m nuclêôtit liên tiếp theo chiều kim đồng hồ trong gen lạ.
*/