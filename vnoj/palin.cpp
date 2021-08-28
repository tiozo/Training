///Đề Olympic Chuyên KHTN 2014
#include<bits/stdc++.h>
using namespace std;

int main() {
    string N;
    cin >> N;
    if (N[0]!=48+9 || N[N.size()-1]!=48+9) {
        N[0]+=1;
        N[N.size()-1]=N[0];
        for (int i=1;i<(N.size()-1);++i) {
            N[i]=48;
        }
    } else {
        int maxval=max(N[0],N[N.size()-1]);
        N[0]=maxval;
        N[N.size()-1]=maxval;
        for (int i=1;i<(N.size()+1/2);++i) {
            if (N[i]!=48+9) {
                N[i]+=1;
                N[N.size()-1-i]=N[i];
                break;
            }
        }
        for (int i=1;i<(N.size())/2;++i) {
            if (N[i]==48+9 && N[i-1]==48+9) {
                N[N.size()-i-1]=N[i];
            }
        }
    }
    cout << N;
    return 0;
}
