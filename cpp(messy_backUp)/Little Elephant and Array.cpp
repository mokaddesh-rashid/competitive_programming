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
#define PB push_back
#define FF first
#define SS second
typedef pair<int,int> pr;


struct node
{
    int l, r, p;
};
int block;

class compare
{
public:
    bool operator()( node f, node s )
    {
      if( f.l/block != s.l/block ) return f.l/block < s.l/block;
      return f.r < s.r;
    }
};

node boo[100010];
int ar[100010], ans[100010], cnt[100010], in[100010];

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    mem( in, 0 );
    mem( cnt, 0 );
    int i, j, x, y, n, m, c = 0;

    ///cin >> n >> m ;
    sff( n, m );

    block = sqrt(n);

    FOR(i,1,n) sf(ar[i]); ///cin >> ar[i];
    FOR(i,0,m-1)
    {
        sff(boo[i].l,boo[i].r);
        boo[i].p = i;
    }

    sort( boo, boo+m, compare() );

    x = y = boo[0].l;
    FOR(i,0,m-1)
    {
       while( true )
       {
           if( ar[x] <= 100000 && x >= boo[i].l && x <= boo[i].r && in[x] == 0 )
           {
              in[x]++;
              cout << cnt[ar[x]] << ' ' << ar[x] << endl;
              if( cnt[ar[x]]+1 == ar[x] ) c++;
              if( cnt[ar[x]] == ar[x] ) c--;
              cnt[ar[x]]++;

           }
           else if( ar[x] <= 100000 && ( x < boo[i].l || x > boo[i].r ) && in[x] == 1 )
           {
              cout << cnt[ar[x]] << 'k' << ar[x] << endl;
              in[x]--;
              if( cnt[ar[x]]-1 == ar[x] ) c++;
              if( cnt[ar[x]] == ar[x] ) c--;
              cnt[ar[x]]--;
           }
           cout << x << ' ' << y << ' ' << c << endl << endl;
           if( x == boo[i].l ) break;
           else if( x < boo[i].l ) x++;
           else x--;

        }

        while( true )
       {
           if( ar[y] <= 100000 && y >= boo[i].l && y <= boo[i].r && in[y] == 0 )
           {
              cout << cnt[ar[y]] << ' ' << ar[y] << endl;
              in[y]++;
              if( cnt[ar[y]]+1 == ar[y] ) c++;
              if( cnt[ar[y]] == ar[y] ) c--;
              cnt[ar[y]]++;
           }
           else if( ar[y] <= 100000 && ( y < boo[i].l || y > boo[i].r ) && in[y] == 1 )
           {
              cout << cnt[ar[y]] << 'k' << ar[y] << endl;
              in[y]--;
              if( cnt[ar[y]]-1 == ar[y] ) c++;
              if( cnt[ar[y]] == ar[y] ) c--;
              cnt[ar[y]]--;
           }
           cout << x << ' ' << y << ' ' << c << endl << endl;
           if( y == boo[i].r ) break;
           else if( y < boo[i].r ) y++;
           else y--;

        }
        //cout << endl << endl << endl;
        ans[boo[i].p] = c;

    }

    FOR(i,0,m-1)
        pf("%d\n",ans[i]);
        //cout << ans[i] << endl;
    return 0;

}



