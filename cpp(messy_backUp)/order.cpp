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
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int ara[MAX], n, snap[MAX];
vector<PR> tree[MAX*4];
vector<PR> usa, savon;

void upd(int idx,int st,int en)
{

    if(st < en)
    {
        int mid = (st + en)>>1;

        upd(lnd, st, mid);
        upd(rnd, mid + 1, en);
    }


    int v = 0;

    FOR(i,st,en)
        snap[v++] = ara[i];

    sort(snap, snap + v);
    usa.clear();

    int x = snap[0], y = 1;

    FOR(i,1,v)
    {
        if(snap[i] != x || i == v)
        {
            usa.PB( MP(y, x) );
            x = snap[i]; y = 1;
        }
        else y++;
    }

    sort(usa.begin(), usa.end());
    reverse(usa.begin(), usa.end());

    FOR(i,0,min(5, (int)usa.size() - 1))
        tree[idx].PB( usa[i] );

}


void query(int idx,int b,int e,int st,int en)
{
    if(st > e || en < b ) return;

    if(st <= b && en >= e)
    {
        for(auto x : tree[idx])
        {
            int ok = 1;

            for(PR &y : savon)
            {
                if(x.S == y.S)
                {
                    y.F += x.F;
                    ok = 0;
                }
            }
            if(ok) savon.PB( x );
        }
        return;
    }

    int mid = (b + e)>>1;

    query(lnd, b, mid, st, en);
    query(rnd, mid + 1, e, st, en);

    return;
}

int main()
{
    ///ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int q;
    int l, r, k, v;

    sff(n, q);
    FOR(i,0,n-1) sf(ara[i]);
    upd(1, 0, n-1);

    for(int ole = 0;ole < q; ole++)
    {
        sfff(l, r, k);
        v = (r - l + 1) / k;

        l--; r--;
        savon.clear();
        query(1, 0, n-1, l, r);

        int ok = -1;
        FOR(i,0,(int)savon.size()-1)
        {
          if(savon[i].F > v)
                ok = (ok == -1) ? savon[i].S : min(ok, savon[i].S);
        }

        pf("%d\n", ok);
    }

    return 0;
}
