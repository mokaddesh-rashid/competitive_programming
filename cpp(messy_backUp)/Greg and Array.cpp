#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
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
typedef pair<int,int> p_i;

struct Node{
    LL lazy, sum;
    Node()
    {
        lazy = sum = 0;
    }
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    update_node(lnd, b, (b+e)/2, cnd.lazy);
    update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    cnd.lazy = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    lazy_update(idx, b, e);
    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int ar[100010], mat[100010][5], cnt[100010];

int main()
{

   int n, m, i, j, a, b, c, x, y, k;

   cin >> n >> m >> k;

   for( i=0; i<n; i++ ) cin >> ar[i];

   for( i=0; i<m; i++ )
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
   for( i=0; i<k; i++ )
   {
       cin >> a >> b;
       update( 1, 1, n, a, b, 1 );
   }

   for( i=0; i<m; i++ )
   {
       a = query( 1, 1, n, i+1, i+1 );
       mat[i][2] = mat[i][2]*a;
   }

   for( i=0; i<m; i++ )
   {
       a = mat[i][0], b = mat[i][1], c = mat[i][2];
       a--;
       cnt[a] += c;
       cnt[b] -= c;
   }
   x = 0;
   for( i=0; i<n; i++ )
   {
       x += cnt[i];
       cout << ar[i]+x << ' ';
   }


}


