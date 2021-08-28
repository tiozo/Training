// N số 1 liên tiếp
// tìm đoạn có K thằng 
// tính chất là thằng có độ dài lớn hơn bao hàm cả thằng con.
// ví dụ 111 bao hàm 2 thằng là 110 và 011
// ở test ví dụ ta có dẫn chứng trên;
// vậy rút ra công thức tính toán nhanh 
// 11111 và k = 2;
// ans = 8 = 2^(N-k+1)


#include<bits/stdc++.h>
using namespace std;

const int mod = 1000007;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main() {
    int n,k; cin >> n >> k;
    if (k>n) cout << "0\n";
    else {
        cout << modpow(2,n-k+1,mod) << '\n';
    }
    return 0;
}