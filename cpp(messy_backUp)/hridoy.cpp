#include<bits/stdc++.h>

using namespace std;

const int MAX = 1010;

int edge[MAX][MAX], n, m;
int que[MAX], frontt, backk, lev[MAX], visited[MAX], pa[MAX];

void bfs(int src)
{
    for(int i = 1; i <= n; i++) visited[i] = 0, pa[i] = lev[i] = -1;
    frontt = backk = 0;

    que[backk++] = src;
    visited[src] = 1;
    lev[src] = 0;

    while(frontt < backk)
    {
        int p = que[frontt++];

        for(int i = 1; i <= n; i++)
        {
            if(visited[i] || !edge[p][i]) continue;
            lev[i] = lev[p] + 1; pa[i] = p;
            que[backk++] = i;
            visited[i] = 1;
        }
    }


    cout << "source:" << src << " distance of ";
    for(int i = 1; i <= n; i++)
    {
        cout << i << "(" << lev[i] << ")";
        if(i != n) cout << ", ";
    }
    cout << endl;
}

void showPath(int p)
{
    if(p == -1) return;
    else showPath( pa[p] );
    cout << p << " ";
}

int main()
{
    ios::sync_with_stdio(false);

    int u, v, src, des;

    cin >> n >> m;/// n denotes number of nodes and m denotes number of edges
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;///theres is a edge between u and v
        edge[u][v] = edge[v][u] = 1;
    }
    cin >> src >> des; ///input source and destination of the path
    bfs(src);
    showPath(des);
    cout << endl;
    return 0;
}
