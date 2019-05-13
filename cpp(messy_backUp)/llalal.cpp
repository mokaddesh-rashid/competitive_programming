#include <stdio.h>
#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)

using namespace std;

/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

namespace mcmf{
    const int MAX = 10005;
    const int INF = 1<<28;

    long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
    int n, m, s, t, Q[10000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX], id[MAX];

    void init(int nodes, int source, int sink){
        cout << nodes << ' ' << source <<  ' ' << sink << endl;
        m = 0, n = nodes, s = source, t = sink;
        for (int i = 0; i <= n; i++) last[i] = -1;
    }

    void addEdge(int u, int v, long long c, long long w,int i = -1){
        cout << u << ' ' << v << ' ' << c << ' ' << w << endl;
        id[m] = i, adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        id[m] = -1, adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
    }

    bool spfa(){
        int i, j, x, f = 0, l = 0;
        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;

        dis[s] = 0, Q[l++] = s;
        while (f < l){
            i = Q[f++];
            for (j = last[i]; j != -1; j = link[j]){
                if (flow[j] < cap[j]){
                    x = adj[j];
                    if (dis[x] > dis[i] + cost[j]){
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if (!visited[x]){
                            visited[x] = 1;
                            if (f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t] != INF);
    }

    vector <int> solve(){
        int i, j;
        long long mincost = 0, maxflow = 0;

        while (spfa()){
            long long aug = INF;
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                aug = min(aug, cap[j] - flow[j]);
            }
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                flow[j] += aug, flow[j ^ 1] -= aug;
            }
            maxflow += aug, mincost += aug * dis[t];
        }
        vector <int> edge_state(m,0) ;
        for (int i = 0 ; i < m ; i++) edge_state[i] = flow[i] ;
        return edge_state ;
    }
}

const int MAX = 5010;
int s[MAX], t[MAX], c[MAX], e[MAX], prin[MAX];
vector<int> inii;

void make_unique(vector<int> &inii)
{
    sort(inii.begin(), inii.end());
    inii.resize(distance(inii.begin(), unique(inii.begin(), inii.end())));
}


int main()
{
    ios::sync_with_stdio(false);
    inf;
    int n, k;

    cin >> n >> k;
    FOR(i,0,n-1)
    {
        cin >> s[i] >> t[i] >> c[i];
        inii.push_back( s[i] );
        inii.push_back( s[i] + t[i] );
    }

    make_unique(inii);
    FOR(i,0,n-1)
    {
        e[i] = lower_bound(inii.begin(), inii.end(), s[i] + t[i]) - inii.begin(); e[i]++;
        s[i] = lower_bound(inii.begin(), inii.end(), s[i]) - inii.begin(); s[i]++;
    }

    int src = 0, des = inii.size() + 1;
    mcmf::init(des + 1, src, des);

    FOR(i,0,(int)inii.size() - 2)mcmf::addEdge(i, i + 1, k, 0);
    mcmf::addEdge(src, 0, k, 0);mcmf::addEdge((int)inii.size() - 1, (int)des, k, 0);
    FOR(i,0,n-1)mcmf::addEdge(s[i], e[i], 1, -c[i], i);
    mcmf::solve();

    for(int i = 0; i <mcmf::m; i++)
        if(mcmf::id[i] != -1 && mcmf::cap[i] == 0) prin[ mcmf::id[i] ] = 1;

    FOR(i,0,n-1) cout << prin[i] << ' ';

    return 0;
}

