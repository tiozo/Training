#include<bits/stdc++.h>
using namespace std;

int main() {
    int hour,minute,gmt1,gmt2; 
    cin >> hour >> minute >> gmt1 >> gmt2;
    cout << (hour-gmt1+gmt2+24)%24 << ' ' << minute;
    return 0;
}