/* monke tiozo
*/
#include <bits/stdc++.h>
using namespace std;

class graph {
private:
    class _uv {
    public:
        int thutu = 0;
        int thap = 0;
        int dau = -1;
        vector<int> ke;
    };
    typedef vector<_uv> _graph;
     _graph dsk;
    int index = 0;
    int count_cut = 0;
    int count_brigde = 0;
public:
    graph (int size) {
        dsk.resize(size+1);
    }
    void add(int u,int v) {
        dsk[u].ke.emplace_back(v);
        dsk[v].ke.emplace_back(u);
    }
    bool check_index(int i) {
        return (dsk[i].thutu == 0) ? true : false;
    }
    void dfs(int u) {
        index += 1;
        dsk[u].thap = dsk[u].thutu = index;
        bool maybe_cut_vertex = false;
        int count_child = 0;

        for (int v: dsk[u].ke) {
            if (!dsk[v].thutu) {
                count_child +=1;
                dsk[v].dau = u;
                dfs(v);
                if (dsk[v].thap > dsk[u].thutu) 
                    count_brigde += 1;
                if (dsk[v].thap >= dsk[u].thutu) 
                    maybe_cut_vertex = true;
                dsk[u].thap = min (dsk[u].thap,dsk[v].thap);
            } else if (v!=dsk[u].dau) {
                dsk[u].thap = min (dsk[u].thap,dsk[v].thutu);
            }
        }

        if (dsk[u].dau == -1) {
            if (count_child > 1) count_cut +=1;
        } else if (maybe_cut_vertex) {
            count_cut += 1;
        }
    }
    void print() {
        cout << count_cut <<  ' ' << count_brigde;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    graph g(N);
    for (int i=1;i<=M;++i) {
        int u,v;
        cin >> u >> v;
        g.add(u,v);
    }
    for (int i=0;i<N;++i) {
        if (g.check_index(i)) {
            g.dfs(i);
        }
    }
    g.print();
    return 0;
}