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
#define M              1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 30010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int IT_MAX = 30010;
const int INF = -1;

int bit[IT_MAX];
void update(int p,int dv) ///change value of position p to v
{
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
LL query(int p)
{
	LL rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

struct node
{
    int l, r, p;
};
int block;

class cmp
{
public:
    bool operator()( node f, node s )
    {
      if( f.l/block != s.l/block ) return f.l/block < s.l/block;
      return f.r < s.r;
    }
};

node qr[MAX];
int val[MAX], cnt[MAX], ase[MAX];
//ordered_set<PR> sota;

void del(int pos)
{
    if(cnt[ val[pos] ]) update(cnt[ val[pos] ], -1);

    cnt[ val[pos] ]--;
    if(cnt[ val[pos] ]) update(cnt[ val[pos] ], 1);

    ase[pos] = 0;
}

void add(int pos)
{
    if(cnt[ val[pos] ]) update(cnt[ val[pos] ], -1);

    cnt[ val[pos] ]++;
    if(cnt[ val[pos] ]) update(cnt[ val[pos] ], 1);

    ase[pos] = 1;
}

void make_same(int to,int from,int l,int r)
{
    while(true)
    {
        if(ase[from] && (from < l || from > r) ) del( from );
        if(!ase[from] && l <= from && from <= r ) add( from );

        if(from == to) return;
        else if(from < to) from++;
        else from--;
    }
}

int show[MAX], ide[MAX];

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int n, q, l, r, p, v;

    cin >> n >> q; block = sqrt( n );
    FOR(i,0,n-1) cin >> val[i], ide[i] = val[i];
    sort(ide, ide + n);
    FOR(i,0,n-1)
        val[i] = lower_bound(ide, ide + n, val[i]) - ide;

    FOR(i,0,q-1)
    {
        cin >> qr[i].l >> qr[i].r; qr[i].p = i;
    }
    sort(qr, qr + q, cmp());

    int x, y;

    x = y = 0;
    FOR(oo,0,q-1)
    {
        l = qr[oo].l; r = qr[oo].r; p = qr[oo].p;
        l--; r--;

        make_same(l, x, l, r); x = l;
        make_same(r, y, l, r); y = r;

        int st = 0, en = 175, prin = 0;
        while(st <= en)
        {
            int mid = (st + en) >> 1;
            PR use = MP(mid, 0);

            v = query( MAX - 1 ) - query(mid - 1);
            if(v >= mid) prin = max(prin, mid), st = mid + 1;
            else en = mid - 1;
        }

        show[p] = prin;
    }

    FOR(i,0,q-1) cout << show[i] << endl;

    return 0;
}

