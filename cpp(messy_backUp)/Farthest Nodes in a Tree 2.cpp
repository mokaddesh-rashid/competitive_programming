#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define FF first
#define SS second
typedef pair<int,int> pr;

struct node
{
    int v, pa, l, mx_1, mx_2, d, vv, mx_1v, mx_2v;
}dfa[100010];
vector<int> mat[100010],cost[100010];

void dfs( int p )
{
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        int y = cost[p][i];
        if( dfa[x].v == 0 )
        {
            dfa[x].pa = p;
            dfs(x);
            dfa[p].l = max( dfa[p].l, dfa[x].l+y);

            int c = dfa[p].mx_1;
            int d = dfa[p].mx_2;
            if( dfa[x].l+y > dfa[c].l+dfa[p].mx_1v )
            {
                dfa[p].mx_2 = c;
                dfa[p].mx_2v = dfa[p].mx_1v;
                dfa[p].mx_1 = x;
                dfa[p].mx_1v = y;
            }
            else if( dfa[x].l+y > dfa[d].l+dfa[p].mx_2v )
            {
                dfa[p].mx_2 = x;
                dfa[p].mx_2v = y;
            }
        }
    }
}

void far( int p, int lev )
{
    //cout << p << ' ' << lev << endl;
    dfa[p].vv = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        int y = cost[p][i];
        if( dfa[x].vv == 0 )
        {
            int levv = lev;
            //cout << lev << endl;
            int c = dfa[p].mx_1;
            int d = dfa[p].mx_2;
            if( c != x && levv < dfa[c].l+dfa[p].mx_1v && c != 0 ) levv = dfa[c].l+dfa[p].mx_1v;
            if( d != x && levv < dfa[d].l+dfa[p].mx_2v && d != 0 ) levv = dfa[d].l+dfa[p].mx_2v;
            //cout << c << ' ' << d << ' ' << ' ' << p << ' ' << x << ' ' << levv << endl;
            dfa[x].vv = 1;
            dfa[x].d = levv+y;
            far( x, levv+y );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tt, ca = 1;
    //cin >> tt;
    sf(tt);
    while(tt--)
    {
        mem(dfa,0);
        int i, j, x, y, n, m, z;
        sf(n);//cin >> n;
        FOR(i,1,n)
        {
            mat[i].clear();cost[i].clear();
        }
        FOR(i,1,n-1)
        {
            sff(x,y);
            sf(z);
            //cin >> x >> y >> z;
            x++; y++;
            mat[x].PB(y); mat[y].PB(x);
            cost[x].PB(z); cost[y].PB(z);
        }
        dfs(1);
        far(1,0);
        pf("Case %d:\n",ca++);
        //FOR(i,1,n)cout <<dfa[i].mx_1 << ' ' << dfa[i].mx_2 << endl;
        FOR(i,1,n)pf("%d\n",max(dfa[i].l ,dfa[i].d));//cout << max(dfa[i].l ,dfa[i].d) << endl;
    }
    return 0;

}



