#include<bits/stdc++.h>
using namespace std;
#define oo 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; bool check = false;
    long long sum=0,prefix=-oo;
    long long suffix=oo;
    long long Mx,Mn,x; cin >> N;
    cin >> x;
    sum += x;
    if (x>0) check = true;
    prefix = max(prefix,sum);
    suffix = min(suffix,sum);
    Mx = Mn = x;
    for (int i=2;i<=N;++i) {
        cin >> x;
        if (x>0) check = true;
        sum += x;
        prefix = max(prefix,sum-Mn);
        suffix = min(suffix,sum-Mx);
        Mx = max(Mx,sum);
        Mn = min(Mn,sum);
    }
    if (!check) cout << prefix;
    else {
        prefix = max(prefix,sum-suffix);
        cout << prefix;
    }
    return 0;
}

/* explanation 
    vi bai toan yeu cau rang day la tong lon nhat lien tuc
    de thay tinh chat khi cong so am vao thi se giam di gia tri tong ban dau
    nen dung 2 bien rieng biet de luu lai doan co gia tri nho nhat va lon nhat.
    neu co ton tai so am, chi can bo di doan co tong nho nhat.
*/