#include<bits/stdc++.h>
using namespace std;
#define base 1000000000
class bignum {
public:
    int val;
    long long a[400];
};

int N,K;
bignum t;

bignum multi2(bignum A) {
    bignum C;
    int du = 0;
    C.val = A.val;
    for(int i = 1;i<=A.val;i++){
        C.a[i] = (A.a[i]*2+du);
        if(C.a[i]>=base){
                C.a[i]-=base;
                du = 1;
        }
        else du = 0; 
    }
    if(du>0) {C.val++; C.a[C.val] = du;}
    return C; 
}

bignum mnus(bignum A,bignum B){
    bignum C; C.val = A.val;
    int du = 0;
    for(int i = 1;i<=A.val;i++){
        if(i>B.val) B.a[i] = 0;
        if(i>t.val) t.a[i] = 0;
        C.a[i] = A.a[i]-B.a[i]+t.a[i]-du;
        if(C.a[i]<0){
            C.a[i]+=base;
            du = 1;
        }
        else if(C.a[i]>=base){
            C.a[i]-=base;
            du = -1;
        }
        else du = 0;  
    }
    if(du == -1) C.a[++C.val] = 1;
    while(C.a[C.val]==0) C.val--;
    if(C.val==0) C.val = 1; 
    return C;
}

void print(bignum A)
{
    printf("%lld",A.a[A.val--]);
    for(int i = A.val;i>=1;i--)
        printf("%09lld",A.a[i]);
}

int main() {
    cin >> N >> K;
    vector<bignum> F(N+1);
    t.val = 1; t.a[1] = 1;
    for (int i=0;i<=N;++i) {
        if (i<K) {
            F[i].val = 1;
            F[i].a[1] = 0;
        } else if (i==K) {
            F[i].val = 1;
            F[i].a[1] = 1;
        } else {
            F[i] = mnus(multi2(F[i-1]),F[i-K-1]);
            t = multi2(t);
        }
    }
    print(F[N]);
    return 0;
}