#include<bits/stdc++.h>
using namespace std;

int main() {
    // first = nights, second = cost;
    int D,costT; pair<int,int> clean1,clean2;
    cin >> D >> clean1.first >> clean2.first >> clean1.second >> clean2.second >> costT;
    vector<pair<int,int>> toys(D);
    for (auto &a:toys) {
        cin >> a.first;
        a.second = a.first*costT;
    } 
    int toys_in_bucket = 0;
    
    return 0;
}

/*
input: 4 1 2 2 1 3
       8
       2
       1
       6
trans: Days : 4
       N1: 1, C1: 2
       N2: 2, C2: 1
       toys need for days 1: 8
                     days 2: 2
                     days 3: 1
                     days 4: 6
output: 35

explain: 8 - 24
        1 -> 9
         2 - 3 
        2 -> 2
         10 33
        2 -> 12
         10
cost 35        
*/