#include<bits/stdc++.h>
using namespace std;

struct BITMap {
	map<int,int> M;
	inline bool find(int x,int y) {
		auto lb = M.lower_bound(x); 
		if (lb==M.begin()) return false;
		lb--;
		if (lb->second<y) return true;
		else return false;
	}
	inline void add(int x,int y) {
		auto lb = M.lower_bound(x);
		auto i2 = lb;
		while (i2!=M.end()&& i2->second>=y) {
			i2++;
		}
		M.erase(lb,i2);
		M.insert({x,y});
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	int N; cin >> N;
	vector<BITMap> a(N);
	int L = 1;
	for (int i=1;i<=N;++i) {
		int x,y; cin >> x >> y;
		int l=0;
		int u=L;
		int m=0;
		while (u>l) {
			m = (l+u+1)/2;
			if (a[m].find(x,y))
				l = m;
			else u = m-1;
		}
		if (L<=l) L = l+1;
		a[l+1].add(x,y);
	} 
	cout << L;
	//return 0;
}