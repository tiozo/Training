#include<bits/stdc++.h>
using namespace std;

const int maxval=100000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int N,t;
    cin >> N;
    vector<int> a(N+1,0);
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    vector<long long> F(maxval+1,0);
    t=1;
    F[1]=a[1];
    for (int i=1;i<=N;++i) {
        if(a[i]>F[t])
        {
            t++;
            F[t] = a[i];
        }
        else if(a[i]<=F[1]) F[1] = a[i];
        else
        {
            int u = 1,v = t,r;
            while(v-u>1)
            {
                r = (u+v)/2;
                if(a[i]>F[r])
                    u = r;
                else v = r;
            }

        F[v] = a[i];
        }
    }
    cout << t;
    return 0;
}
