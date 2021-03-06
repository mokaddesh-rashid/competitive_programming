#include <bits/stdtr1c++.h>

#define MAX 2010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
using namespace std;

/// Hopcroft karp in O(m * sqrt(n))
namespace hc{ /// hash = 393558
    bool visited[MAX];
    vector <int> adj[MAX];
    int n, L[MAX], R[MAX], Q[MAX], len[MAX], dis[MAX], parent[MAX];

    inline void init(int nodes){ /// Number of vertices in the left set, or max(left_set, right_set)
        n = nodes, clr(len);
        for (int i = 0; i < MAX; i++) adj[i].clear();
    }

    inline void add_edge(int u, int v){ /// 0 based index
        len[u]++;
        adj[u].push_back(v);
    }

    bool dfs(int i){
        for (int j = 0; j < len[i]; j++){
            int x = adj[i][j];
            if (L[x] == -1 || (parent[L[x]] == i)){
                if (L[x] == -1 || dfs(L[x])){
                    L[x] = i, R[i] = x;
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(){
        clr(visited);
        int i, j, x, d, f = 0, l = 0;

        for (i = 0; i < n; i++){
            if (R[i] == -1){
                visited[i] = true;
                Q[l++] = i, dis[i] = 0;
            }
        }

        while (f < l){
            i = Q[f++];
            for (j = 0; j < len[i]; j++){
                x = adj[i][j], d = L[x];
                if (d == -1) return true;

                else if (!visited[d]){
                    Q[l++] = d;
                    parent[d] = i, visited[d] = true, dis[d] = dis[i] + 1;
                }
            }
        }
        return false;
    }

    int hopcroft_karp(){
        int res = 0;
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));

        while (bfs()){
            for (int i = 0; i < n; i++){
                if (R[i] == -1 && dfs(i)) res++;
            }
        }
        return res;
    }
}


vector<int> adjl[MAX];
int first_set[MAX], second_set[MAX];

void get_path(int i)
{
    if(first_set[i]) return;
    first_set[i] = true;
    for(int x : adjl[i])
    {
        if (!second_set[x] && hc::L[x] != -1)
        {
            second_set[x] = true;
            get_path(hc::L[x]);
        }
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int v;

    cin >> n;
    hc::init(n);

    FOR(i,0,n-1)
        for(int x : adjl[i]) hc::add_edge(i, x);

    cout << n - hc::hopcroft_karp() << endl;

    for(int i = 0; i < n; i++)
            if (hc::R[i] == -1) get_path(i);

    for(int i = 0; i < n; i++){
        if (!first_set[i] || second_set[i]) cout << i + 1 << ' ';
    }

    return 0;
}
