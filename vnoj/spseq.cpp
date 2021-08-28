#include<bits/stdc++.h>
using namespace std;

const int maxval=100000;
vector<int> lis(maxval,0),lds(maxval,0);

void LIS(vector<int> &a,int N) {
    vector<int> x(N+1,INT_MAX);
    x[0]=INT_MIN;
    int maxlen=0;
    vector<int>::iterator it;
    for (int i=0;i<N;++i) {
        int p=lower_bound(x.begin(),x.begin()+maxlen+1,a[i]) - x.begin();
        lis[i]=p;
        maxlen = max(maxlen, p);
        x[p] = min(x[p], a[i]);
    }
}

void LDS(vector<int> &a,int N) {
    vector<int> x(N+1,INT_MAX);
    x[0]=INT_MIN;
    int maxlen=0;
    vector<int>::iterator it;
    for (int i=N-1;i>=0;--i) {
        int p=lower_bound(x.begin(),x.begin()+maxlen+1,a[i]) - x.begin();
        lds[i]=p;
        maxlen = max(maxlen, p);
        x[p] = min(x[p], a[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int N;
    cin >> N;
    vector<int> a(N,0);
    for (int i=0;i<N;++i) {
        cin >> a[i];
    }
    LIS(a,N);
    LDS(a,N);
    int res = 0;
	for(int i = 0; i <N ; ++i) {
        res=max(res,2*min(lis[i],lds[i])-1);
	}
    cout << res;
    return 0;
}
