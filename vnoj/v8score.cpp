#include<bits/stdc++.h>
using namespace std;

int S,K,N,found=0;
const int maxelement=200;
vector<vector<int> > a(maxelement+1,vector<int> (maxelement+1,0));
vector<int> X(maxelement+1,0),C(maxelement+1,0);
vector<vector<int> > F(maxelement+1,vector<int> (maxelement+1,0));

int main() {
    cin >> S >> K >> N;
    for (int i=0;i<N;++i) {
        for (int j=0;j<K;++j) {
            cin >> a[j][i];
        }
    }
    for (int i=0;i<=K;++i) {
        for (int j=0;j<=S;++j) {
            if (i==0 && j==0) F[i][j]=0;
            else if (i==0 || j==0) F[i][j]=INT_MAX;
            else {
                F[i][j]=INT_MAX;
                for (int x=0;x<N;++x) {
                    if( a[i-1][x] < F[i][j] && a[i-1][x] <= j && F[i-1][j-a[i-1][x]] <= a[i-1][x] )
                        F[i][j] = a[i-1][x];
                }

            }
        }
    }
    if( F[K][S] == INT_MAX ) puts("NO");
	else {
		cout << "YES\n";
		stack<int> st;
		while( S > 0 ) {
			st.push(F[K][S]);
			S -= F[K--][S];
		}
		while (st.empty()==0) {
            cout << st.top() << ' ';
            st.pop();
		}
	}
    return 0;
}
