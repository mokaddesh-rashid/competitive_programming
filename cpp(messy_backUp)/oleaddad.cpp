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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


LL ar[100010];
struct info
{
   LL sum;

}tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += v;
    cnd.sum %= (LL)1000000007;
}

LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt)%(LL)1000000007;
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

pr in[MAX];
int main()
{
    memset(tree, 0, sizeof( tree ) );
    LL n, m, i, x, y, c = 0, a = 1, b;
    int cr[100010], bs[100010];

    sf(n);
    FOR(i,0,n-1)sff(in[i].F,in[i].S);

    sort(in,in+n);
    FOR(i,0,n-1) ar[i]=in[n-i-1].S, cr[i] = ar[i];
    sort( cr, cr+n );
    FOR(i,0,n-1)
    {
        if( i > 0 && cr[i] != cr[i-1] ) a++;
        bs[i] = a;
        //cout << cr[i] << ' ' << a << endl;
    }
    FOR(i,0,n-1)
    {
        b = ar[i];
        b = lower_bound( cr, cr+n, b ) - cr;
        a = bs[b];
        ///cout << ar[i] << ' ';
        ar[i] = a;
        ///cout << a << ' ';
    }
    //cout << endl;
    REV(i,n-1,0)
    {
        a = ar[i];
        x = query(1,1,100001,a+1,100001);
        c += (x+1);
        c %= (LL)1000000007;
        update(1,1,100001,ar[i],ar[i],x+1);
    }

    pf("%lld\n",c );
    return 0;
}
