/***
    Heavy Light Decomposition (HLD)
***/
int n;
vector<int> adjl[MX];
int hsz[MX], mxsz[MX];
int par_of[MX];
int get_size(int u, int par)  {
    int mx = 0, mxnode = 0;
    int ans = 0;
    FOR(i, 0, (int)adjl[u].size() - 1)  {
        int v = adjl[u][i];if(v == par)continue;
        ans += get_size(v, u);
        if(hsz[v] > mx) {
            mx = hsz[v];
            mxnode = v;
        }
    }
    mxsz[u] = mxnode;
    par_of[u] = par;
    return hsz[u] = 1 + ans;
}
int chainno[MX], posof[MX];///of a node
int hc;///chain count
int headof[MX], lenof[MX];///of a chain
void hdfs(int u, int par, int pos)  {
    chainno[u] = hc;
    posof[u] = pos;
    lenof[hc] = pos;
    if(mxsz[u] != 0)hdfs(mxsz[u], u, pos + 1);
    FOR(i, 0, (int)adjl[u].size() - 1)  {
        int v = adjl[u][i];if(v == par)continue;
        if(v == mxsz[u])continue;
        hc++;
        headof[hc] = v;
        hdfs(v, u, 1);
    }
}
bool col_chk[MX];int col_node[MX];
int lca(int a, int b)   {
    int u;
    u = a;
    while(u) {
        col_chk[ chainno[u] ] = 1;///root porjonto shob chain 1 kore deo
        col_node[ chainno[u] ] = u;///prottek chain e kon node age paisi oita save koro
        u = headof[ chainno[u] ];u = par_of[u];
    }
    int ans;
    u = b;
    while(u) {
        if(col_chk[ chainno[u] ])   {
            ///same chain e aschi
            ///same chain er duita node er jar pos/lev choto sheita lca
            if(posof[u] < posof[ col_node[ chainno[u] ] ])  {
                ans = u;
            }
            else    {
                ans = col_node[ chainno[u] ];
            }
            break;
        }
        u = headof[ chainno[u] ];u = par_of[u];
    }
    u = a;
    while(u) {
        col_chk[ chainno[u] ] = 0;///root porjonto shob chain 0 kore deo
        u = headof[ chainno[u] ];u = par_of[u];
    }
    return ans;
}
void print_hld();
int chlen[MX];
void hld()   {///1 based
    get_size(1, 0);
    hc = 1; headof[hc] = 1; hdfs(1, 0, 1);
    FOR(i, 1, hc)   {
        chlen[i] = chlen[i - 1] + lenof[i];
    }
}
int pos_in_seg(int u) {
    return chlen[ chainno[u] - 1 ] + posof[u];
}
void print_hld() {
    cout << "sz : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << hsz[i] << "\n";
    }
    cout << "\n\n";
    cout << "mx : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << mxsz[i] << "\n";
    }
    cout << "\n\n";
    cout << "chainno : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << chainno[i] << "\n";
    }
    cout << "\n\n";
    cout << "headof : \n";
    FOR(i, 1, hc)   {
        cout << i << " : " << headof[i] << "\n";
    }
    cout << "\n\n";
    cout << "posof : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << posof[i] << "\n";
    }
    cout << "\n\n";
    cout << "lenof : \n";
    FOR(i, 1, hc)   {
        cout << i << " : " << lenof[i] << "\n";
    }
    cout << "\n\n";
    cout << "parof : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << par_of[i] << "\n";
    }
    cout << "\n\n";
    cout << "cumulative sum of chain size : \n";
    FOR(i, 1, hc)   {
        cout << i << " : " << chlen[i] << "\n";
    }
    cout << "\n\n";
    cout << "pos in segment tree : \n";
    FOR(i, 1, n)   {
        cout << i << " : " << pos_in_seg(i) << "\n";
    }
    cout << "\n\n";
}
int ar[MAX], tree[MAX*3];
int query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];
    int mid = (b+e)/2;
    int m1 = query(node*2, b, mid, i, j);
    int m2 = query(node*2+1, mid+1, e, i, j);
    return (m1+m2);
}
void update(int node, int b, int e, int idx, int x)
{
    if(b > idx || e < idx) return ;
    if(b == e)
    {
        tree[node] = x;
        return ;
    }
   int mid = (b+e)/2;
    update(node*2, b, mid, idx, x);
    update(node*2+1, mid+1, e, idx, x);
    tree[node] = tree[node*2]+tree[node*2+1];
}
int query_ind(int a, int lc) {
    int u;
    u = a;
    int ans = 0;
    while(u) {
        if(chainno[lc] == chainno[u]) {
            int le = pos_in_seg(lc);
            int ri = pos_in_seg(u);
            ans += query(1,1,n,le,ri);
            break;
        }
        int le = pos_in_seg(headof[ chainno[u] ]);
        int ri = pos_in_seg(u);
        ans += query(1,1,n,le,ri);
        u = headof[ chainno[u] ];u = par_of[u];
    }
    return ans;
}
int query_it(int a, int b)  {
    int lc = lca(a, b);
    int ans = 0;
    ans += query_ind(a, lc);
    ans += query_ind(b, lc);
    ans -= query_ind(lc, lc);
    return ans;
}
int val[MAX];
int main()  {
    int tc;
    si(tc);
    FOR(tt, 1, tc)   {
        si(n);
        FOR(i,1,n) si(val[i]);///cin>> val[i];
        FOR(i, 1, n)   {
            adjl[i].clear();
        }
        FOR(i, 1, n - 1)    {
            int u, v;
            si(u);si(v);
            u++; v++;
            adjl[u].pb(v);
            adjl[v].pb(u);
        }
        hld();
        FOR(i,1,n)
           update(1,1,n,pos_in_seg(i),val[i]);
        printf("Case %d:\n", tt);
        int q;
        int a,b,c;
        si(q);
        FOR(i, 1, q)
        {
            si(a);
            if(a==0)
            {
                si(b);si(c);
                b++; c++;
                printf("%d\n", query_it(b,c));
            }
            else
            {
                si(b);si(c);
                b++;
                update(1,1,n,pos_in_seg(b),c);
            }
        }
    }
    return 0;
}
}
