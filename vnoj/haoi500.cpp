#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,K;
int a[1000000+1];

int calc(int l,int r)
{
    l=(l+N)%N;
    r=(r+N)%N;
    return a[r]-a[l-1]+(l>r?a[N-1]:0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll sumD = 0,best = 0;
    cin >> N >> K;
    for (int i=1;i<=K;++i) {
        int tmp;
        cin >> tmp;
        a[--tmp]++;
        sumD+=min(tmp,N-tmp);
    }
    vector<int> F;
    F.push_back(1);
    best = sumD;
    /// gọi a[i] là khoảng từ máy số 1 đến máy thứ i
    for (int i=1;i<N;++i) {
        a[i]+=a[i-1];
    }
    for (int i=1;i<N;i++) {
        /// tổng khoảng cách các máy các máy trong vòng N về nữa vòng phía trái và nữa vòng phía phải
        sumD += calc(i-N/2,i-1)-calc(i,i+N/2-1);
        if (sumD==best) F.push_back(i+1);
        if (sumD<best) {
            best=sumD;
            F.assign(1,i+1);
        }
    }
    cout << best << '\n' << F.size() << '\n';
    for (int &F:F) cout << F << ' ';
    return 0;
}
/*
 Phòng thi có kích thước rất lớn những lại chỉ có một số thí sinh tham gia cuộc thi này thậm chí vấn đề còn trở nên phức tạp hơn khi có thể có nhiều thí sinh cùng thi trên một máy 
 (kiểu như thi đồng đội). Khoảng cách giữa 2 máy tính được định nghĩa là khoảng cách để đi từ máy này đến máy kia (tính theo đường ngắn hơn). 
 Nói cách khác, khoảng cách giữa hai máy u và v là min(|u−v|,N−|u−v|).
*/