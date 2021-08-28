#include<bits/stdc++.h>
using namespace std;

map<string,string> m;
void drill(string s1,string s2) {
    m[s1]=s2;
}

string query(string s) {
    return m[s];
}