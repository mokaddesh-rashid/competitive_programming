#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int id, cnt[MAX];
vector<int> mat[MAX];

struct Node
{
    int v;
    Node *nex[26];

    Node()
    {
        FOR(i,0,25) nex[i] = NULL;
        v = id++;
    }
};
Node *Root;
string str;

void in(string str)
{
    int n = str.size();
    Node *p = Root;

    FOR(i,0,n-1)
    {
        int go = str[i] - 'a';
        if(p->nex[go] == NULL) p->nex[go] = new Node();
        p = p->nex[go];
    }

    cnt[ p->v ] = 1;

}
/// trie part ends here

void add_edge(int u,int v)
{
    mat[u].PB( v );
    mat[v].PB( u );
}

void rec(Node *p)
{
    FOR(i,0,25)
    {
        if(p->nex[i] == NULL) continue;

        add_edge(p->v, p->nex[i]->v);
        rec(p->nex[i]);
    }
}
/// graph building  part ends here

multiset<PR> tree[4*MAX];

void update(int idx,int b,int e,int p,int v,int t)
{
    if(p > e || p < b) return;

    if(t) tree[idx].insert( MP(v, p) );
    else tree[idx].erase( MP(v, p) );

    if(b == e) return;

    int mid = (b + e)>>1;

    update(lnd, b, mid, p, v, t);
    update(rnd, mid + 1, e, p, v, t);
}

PR query(int idx,int b,int e,int st,int en)
{
    if(st > e || en < b ) return MP(-1, -1);
    if(st <= b && en >= e)
    {
        if(!cnd.size()) return MP(-1, -1);
        return *(cnd.rbegin());
    }

    int mid = (b + e)>>1;
    PR lf = query(lnd, b, mid, st, en);
    PR rg = query(rnd, mid + 1, e, st, en);

    if(lf.F <= rg.F) return rg;
    return lf;
}
///*********** segment tree part ends here

int st[MAX], en[MAX], lev[MAX], ti, rev[MAX], prin;

void dfs(int p,int pa)
{
    st[p] = ++ti; rev[ti] = p;
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        lev[x] = lev[p] + 1;
        dfs(x, p);
    }
    en[p] = ti;

    if(cnt[p])
    {
        update(1, 0, MAX - 1, st[p], lev[p], 1);
        prin += lev[p];
    }
}

void finAns(int p,int pa)
{
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        finAns(x, p);
    }

    if(!cnt[p] && p)
    {
        PR use = query(1, 0, MAX - 1, st[p], en[p]);
        if(use.F != -1)
        {
            update(1, 0, MAX - 1, use.S, use.F, 0);
            prin -= lev[ rev[use.S] ];

            update(1, 0, MAX - 1, st[p], lev[p], 1);
            prin += lev[ p ];
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    //outf;

    Root = new Node();
    int n;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str;
        in(str);
    }
    rec(Root);
    dfs(0, 0);
    finAns(0, 0);
    cout << prin << endl;

//    cout << query(1, 0, MAX-1, st[1], en[1]).S << endl;
//    PR use = query(1, 0, MAX-1, st[1], en[1]);
//    update(1, 0, MAX-1, st[use.S], lev[use.S], 0);
//    cout << query(1, 0, MAX-1, st[1], en[1]).S << endl;

    return 0;
}
