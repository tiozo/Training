#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<double long,double long>,double long> a,pair<pair<double long,double long>,double long> b) {
    if (a.second==b.second) {
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

int main() {
    int N; cin >> N;
    vector<pair<pair<double long,double long>,double long>> a(N);
    for (auto &a:a) {
        cin >> a.first.first;
    }
    for (auto &a:a) {
        cin >> a.first.second;
        a.second = (double long)a.first.first/a.first.second;
    }
    sort(a.begin(),a.end(),cmp);
    for (auto &a:a) {
        cout << (long long)a.first.first << ' ';
    } 
    cout << '\n';
    for (auto &a:a) {
        cout << (long long)a.first.second << ' ';
    } 
    return 0;
}