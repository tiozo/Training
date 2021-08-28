#include<bits/stdc++.h>
using namespace std;

const int MAX_LABEL = 1e5;
const int maxval = 60000;

class BIT {
private:
    int max_label;
    vector<int> T;
public:
    BIT(int size) {
        max_label=size;
        T.resize(size+1,0);
    }
    void update(int label) {
        for (int i=label;i<=max_label;i+=i&-i) {
            ++ T[i];
        }
    }
    int Count(int label) {
        int res = 0;
        for (int i=label;i;i-=i&-i) {
            res += T[i];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    BIT tree(MAX_LABEL);
    int N,result = 0;
    cin >> N;
    for (int i=1,ai;i<=N;++i) {
        cin >> ai;
        ai = maxval - ai + 1;
        result += tree.Count(ai-1);
        tree.update(ai);
    }
    cout << result;
    return 0;
}