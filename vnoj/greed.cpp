#include<bits/stdc++.h>
using namespace std;

int main() {

    for t in range(int(input())):
	a, b, c = map(int, input().split())
	print("1" + "0" * (a - 1), "1" * (b - c + 1) + "0" * (c - 1))
    return 0;
}
