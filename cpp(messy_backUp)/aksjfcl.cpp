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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

vector<LL> mat[MAX], chi[MAX];
LL lev[MAX], val[MAX], ans[MAX], st[MAX], en[MAX];
LL tree[4*MAX], ti;

void update(int idx,int b,int e,int p,LL v)
{
    if(p > e || p < b || b > e) return;
    if(b == e)
    {
        ///cout << e << ' ' << b << ' ' << v << endl;
        cnd = v;
        return;
    }

    int mid = (b + e)>>1;
    update(lnd, b, mid, p, v);
    update(rnd, mid + 1, e, p, v);

    cnd = max(tree[lnd], tree[rnd]);
}

LL query(int idx,int b,int e,int st,int en)
{
    if(st > e || en < b || b > e) return 0;
    if(st <= b && en >= e) return cnd;

    int mid = (b + e)>>1;
    return max(query(lnd, b, mid, st, en), query(rnd, mid + 1, e, st, en));
}

void dfs(int p,int pa)
{
    st[p] = ++ti;

    for(auto x : mat[p])
    {
        if(x == pa) continue;

        dfs(x, p);
        lev[p] = max(lev[p], lev[x]);
        chi[p].PB( lev[p] );
    }

    sort(chi[p].begin(), chi[p].end());
    reverse(chi[p].begin(), chi[p].end());

    lev[p] += val[p];
    en[p] = ti;
    return;
}

LL prin = 0, raju;
void dfs(int p,int pa,LL up,LL dw = 0)
{
    LL m1, m2, m3;
    m1 = m2 = m3 = 0;

    if(chi[p].size() > 0 ) m1 = chi[p][0];
    if(chi[p].size() > 1 ) m2 = chi[p][1];
    if(chi[p].size() > 2 ) m3 = chi[p][2];

    for(auto x : mat[p])
    {
        if(x == pa) continue;
        if(m1 == lev[x]) dfs(x, p, max(up, m2) + val[p], max(dw, val[p] + m2 + m3));
        else
        {
            if(m2 == lev[x] ) dfs(x, p, max(up, m1) + val[p], max(dw, val[p] + m1 + m3));
            else dfs(x, p, max(up, m1) + val[p], max(dw, val[p] + m1 + m2));
        }
    }

//    cout << 1 << ' ' << st[p] - 1 << ' ' << query(1, 1, MAX, 1, st[p] - 1) << endl;
//    cout << en[p] + 1 << ' ' << MAX << ' ' << query(1, 1, MAX, en[p] + 1, MAX) << endl;
//    cout << query(1, 1, MAX, st[p], en[p]) << endl << endl;
    prin = max(prin, query(1, 1, MAX, 1, st[p] - 1) * query(1, 1, MAX, st[p], en[p]));
    prin = max(prin, query(1, 1, MAX, en[p] + 1, MAX) * query(1, 1, MAX, st[p], en[p]) );
    prin = max(prin, (m1 + val[p] + m2) * up);
    prin = max(prin, (m1 + val[p] + m2) * dw);
    update(1, 1, MAX, st[p], m1 + val[p] + m2);
    ///cout << st[p] << ' ' << m1 + val[p] + m2 << endl;
}



int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int n, x, y;

    cin >> n;
    FOR(i,1,n) val[i] = 1;
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }

    dfs(1, 1);
    dfs(1, 1, 0);

    cout << prin << endl;

    return 0;
}

