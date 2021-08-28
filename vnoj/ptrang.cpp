#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int N,L;
    cin >> N >> L;
    int Max=0;
    vector<int> a(N+1,0);
    vector<int> F(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        F[i]=L;
        int t=L;
        int j=i;
        while (j!=0) {
            t=t-a[j];
            if (t<0) break;
            Max=max(t,F[j-1]);
            if (Max<F[i]) {
                F[i]=Max;
            }
            j--;
        }
    }
    cout << F[N];
    return 0;
}
