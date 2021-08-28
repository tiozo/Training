#include<bits/stdc++.h>
using namespace std;

void task1(string a,string b) {
    string c1 = "";
    if ((a[0]<b[0] && a.length()==b.length()) || a<b) swap(a,b);
    cout << b << ' ';
    int i2 = 0;
    for (int i=0;i<b.length();++i) {
        if (i==0) {
            c1+=b[0];
            continue;
        }
        while (a[i2]<=b[i] && i2<a.length()) {
            c1+=a[i2++];
        }  
        //cout << i2 << ' ';
        if ((a[i2]>=b[i] && i2<a.length()) || i2==a.length()){
            c1+=b[i];
        }
    }
    cout << "Gia tri nho nhat cua so C:";
    cout << c1 << '\n';
}

void task2(string a,string b) {
    string c1 = "";
    if ((a[0]>b[0] && a.length()==b.length()) || a>b) swap(a,b);
    //cout << b[0];
    int i2 = 0;
    for (int i=0;i<b.length();++i) {
        if (i==0) {
            c1+=b[0];
            continue;
        }
        while (a[i2]>=b[i] && i2<a.length()) {
            c1+=a[i2++];
        }  
        //cout << i2 << ' ';
        if ((a[i2]<=b[i] && i2<a.length()) || i2==a.length()){
            c1+=b[i];
        }
    }
    cout << "Gia tri lon nhat cua so C:";
    cout << c1 << '\n';
}

int main() {
    string a,b; cin >> a >> b;
    cout << "So A = " << a << " va so B = " << b << '\n';
    task1(a,b);
    task2(a,b);
    return 0;
}