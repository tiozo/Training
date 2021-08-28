#include<bits/stdc++.h>
using namespace std;

int N,sumMax=0;
vector<vector<int>> f;
vector<vector<int>> a;
int getIthBit(int N,int index) {
    return (N>>index)&1;
}

int turnoff(int N,int index) { 
    return N&~(1<<index);
}

int DPBitMask() {
    int first = 1,last = (1<<N)-1;
	f = vector<vector<int>>(N+1,vector<int>(last+1,1e9));
	for (int i=1;i<=N;++i) f[i][1<<(i-1)] = 0;
    for (int mask=first;mask<=last;++mask) {
        vector<int> b(1,0); int k = 0;
		for (int i=1;i<=N;++i) {
			if (getIthBit(mask,i-1)) {
				++k; b.push_back(i);
			}
		}
		for (int i=1;i<=k;++i) {
			int u = b[i];
			int premask = turnoff(mask,b[i]-1);
			for (int j=1;j<=k;++j) {
				if (i!=j && f[b[j]][premask]+a[b[j]][u]<f[u][mask])
					f[u][mask] = f[b[j]][premask] + a[b[j]][u];
			}
		}
    }
	int res = 1e9;
	for (int i=1;i<=N;++i) {
		res = min(f[i][last],res);
	}
    return res;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> N;
    a = vector<vector<int>>(N+1,vector<int>(N+1,0));
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            cin >> a[i][j];
        }
    }
    f.resize((1<<(N+1)));
    cout << DPBitMask();
    return 0;
}