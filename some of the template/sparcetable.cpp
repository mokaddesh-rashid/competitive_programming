void make_sparceT()
{
    FOR(i,1,16)
        FOR(j,1,n)
        {
            int x = sparceT[i - 1][j];
            if(x == -1) continue;
            sparceT[i][j] = sparceT[i - 1][x];
        }
}

int make_same(int u,int v,int jump)
{
    int to = sparceT[jump][u];

    if(lev[u] == lev[v]) return u;
    else if(to == -1 || lev[to] < lev[v]) return make_same(u, v, jump - 1);
    else return make_same(to, v, jump);

}

int fin_Lca(int u,int v,int jump)
{
    int t1 = sparceT[jump][u], t2 = sparceT[jump][v];

    if(u == v) return u;
    if(jump == 0 && t1 == t2) return t1;
    else if(t1 == t2) return fin_Lca(u, v, jump - 1);
    else return fin_Lca(t1, t2, jump);
}

int lca(int u,int v)
{
    if(lev[u] < lev[v]) swap(u, v);
    u = make_same(u, v, 16);
    return fin_Lca(u, v, 16);
}
