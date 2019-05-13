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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 30005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;

struct Node
{
    int sum;
};


Node tree[4*MAX];

void update_node(int idx, int b, int e, int v)
{
    cnd.sum = 1;
}


int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    int lft = query(lnd, b, (b+e)/2, st, en);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en);
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

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int st[200005], en[200005], v[200005], ans[200005];
p_i jo[100001], lo[200005];

int main()
{
    //ios::sync_with_stdio(false);
    memset( tree, 0, sizeof(tree) );
   int i, j, n, m, a, b, c, x, y, z;

   sf(n);

   for( i=0; i<n; i++ )
   {
       sf(jo[i].first);
       jo[i].second = i+1;
   }

   sort( jo, jo+n, greater<p_i>() );

    sf(m);

   for( i=0; i<m; i++ )
   {
       sfff(st[i],en[i],c);
       lo[i].first = c;
       lo[i].second = i;
   }

   sort( lo, lo+m, greater<p_i>() );
   //cout << endl;
   j = 0;
   for( i=0; i<m; i++ )
   {
       while( j<n && lo[i].first < jo[j].first )
       {
           //cout << jo[j].first << endl;
           update( 1, 1, n, jo[j].second, jo[j].second, 1 );
           j++;
       }

       x = query( 1, 1, n, st[lo[i].second], en[lo[i].second] );
       ans[lo[i].second] = x;
       //cout << st[lo[i].second] << ' ' << en[lo[i].second]  << ' ' << lo[i].first << endl;

   }
   //cout << endl;
   for( i=0; i<m; i++ )
    pf("%d\n", ans[i]);
   // cout << ans[i] << endl;

}
