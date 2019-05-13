

const int INF = 1000000000;

int src, des, m, c, d, show[MAX][MAX], can[MAX];
vector<int> adjl[110];
vector<int> rc[110];///residual capacity
vector<int> rev_idx[110];///reverse_index


void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);///one directional
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

int lev[110];
int vis[110];
bool dinic_bfs()  { //this finds level of all nodes from source
    mem(vis, 0);
    mem(lev, 0);
    lev[src] = 0;
    vis[src] = 1;
    queue<int> myq;
    myq.push(src);
    while(!myq.empty()) {
        int u = myq.front();
        myq.pop();
        int sz = adjl[u].size();
        FOR(i, 0, sz - 1)   {
            int v = adjl[u][i];
            if(rc[u][i] == 0)   {
                continue;
            }
            if(vis[v] == 0) {
                vis[v] = 1;
                lev[v] = lev[u] + 1;
                myq.push(v);
            }
        }
    }
    if(vis[des])    {
        return 1;
    }
    return 0;
}

int shuru[110];
int dinic_dfs(int u, int flow) {
    //cout << u << " " << flow << "\n";
    if(u == des)    {
        return flow;
    }
    FOR(i, shuru[u], (int)adjl[u].size() - 1)   {
        shuru[u] = i;
        int v = adjl[u][i];
        if((lev[v] == lev[u] + 1) && (rc[u][i]))    {
            int ff = dinic_dfs(v, min(flow, rc[u][i]));
            if(ff) {
                rc[u][i] -= ff;
                rc[v][ rev_idx[u][i] ] += ff;

                return ff;
            }
        }
    }
    shuru[u] = adjl[u].size();
    return 0;
}

int dinic() {

    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, INF);
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}

void rev_edge(int u,int tar,int ff)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] += ff;
            rc[v][ rev_idx[u][i] ] -= ff;
        }
    }
    return;
}

void off_edge(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] = 0;
            rc[v][ rev_idx[u][i] ] = 0;
        }
    }
    return;
}

void on_edge(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] = 0;
            rc[v][ rev_idx[u][i] ] = 1;
        }
    }
    return;
}

void khulo(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            rc[u][i] = 1;
            rc[v][ rev_idx[u][i] ] = 0;
        }
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        cout << "Case #" << tt << ":" << endl;
        int k, v, m, n, node;

        cin >> n >> m;

        src = 0; des = n + m + 1; node = des + 1;
        FOR(i, 0, node)
        {
            adjl[i].clear();
            rc[i].clear();
            rev_idx[i].clear();
        }

        FOR(i,1,n) add_edge(src, i, 1);
        FOR(i,1,m)
        {
            cin >> v;
            add_edge(i + n, des, v);
        }
        FOR(i,1,n)
        {
            cin >> k;
            FOR(ko, 1, k)
            {
                cin >> v;
                add_edge(i, v + n, 1);
            }
        }

        memset(show, 0, sizeof(show));
        memset(can, 0, sizeof(can));
        int prin = dinic();

        cout << prin << " applicant(s) can be hired." << endl;

        FOR(u,1,n)
        {
            REV(p, (int)adjl[u].size()-1, 0)
            {
                int v = adjl[u][p];

                if(!rc[u][p] && rc[v][ rev_idx[u][p] ] && v != src)
                {
                    rev_edge(src, u, 1);
                    rev_edge(v, des, 1);
                    off_edge(u, v);

                    if(dinic());
                    else
                    {
                        show[u][v - n] = 1; can[u] = v - n;

                        rev_edge(src, u, -1);
                        rev_edge(v, des, -1);
                        on_edge(u, v);

                        break;
                    }
                }
                else if(v != src) off_edge(u, v);
            }
        }

        FOR(u,1,n)
        {
            if(!can[u])
            FOR(p, 0, (int)adjl[u].size()-1)
            {
                int v = adjl[u][p] - n, ok = 0;
                FOR(i,u + 1, n)
                {
                    if(v == can[i])
                    {
                        swap(can[i], can[u]);
                        ok = 1;
                        break;
                    }
                }
                if(ok) break;
            }
            if(can[u]) cout << u << ' ' << can[u] << endl;
        }
    }


    return 0;
}

