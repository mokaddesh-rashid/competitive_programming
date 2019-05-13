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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int  arr[1000000+1], prime[1000000+1], np, pfac[20+1], tim[20+1], nf, val[sz], nd, ar[sz];

void sieve( int n )
{
    int  m = sqrt(n), i, j;
    prime[np] = 2;
    np++;
    for( i=3; i<=m; i += 2)
    {
        if( arr[i] == 0 )
         {
            for( j=i*i; j<=n; j += (i+i) )
                arr[j]++;
         }
    }
    for( i=3; i<=n; i += 2)
    {
        if( arr[i] == 0 )
         {
            prime[np] = i;
            np++;
         }
    }


}

void prime_fac( int  n )
{
    int  m = sqrt(n);

    for( int  i=0; i<np && prime[i] <= m ; i++ )
    {
        if( n % prime[i] == 0 )
        {
            int  a = 0;

            while( n % prime[i] == 0 )
            {
                a++;
                n /= prime[i];

            }
           pfac[nf] = prime[i];
           tim[nf] = a;
           nf++;
           m = sqrt(n);
        }
    }

    if( n != 1 )
    {
           pfac[nf] = n;
           tim[nf] = 1;
           nf++;
    }
}

struct node
{
    int l, r, p, x, y;
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

node boo[sz];

struct info
{
   LL sum;

}tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    //cout<<b<<'c'<<v<<NL;
    cnd.sum=v;
}
LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)>>1, st, en);
    LL rgt = query(rnd, ((b+e)>>1)+1, e, st, en);
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

    update(lnd, b, (b+e)>>1, st, en, v);
    update(rnd, ((b+e)>>1)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int ase[sz], ans[sz];

void up(int x,int a,int b)
{
   int c,d;
   if(ase[x]==1&&(x<a||x>b))
   {
       nf = 0; prime_fac(ar[x]);
       FOR(i,0,nf-1)
       {
           c=pfac[i]; d=tim[i];
           val[c]-=d;
           ///cout<<c<<' '<<val[c]<<NL;
           update(1,1,1000000,c,c,val[c]);
       }
       ase[x]=0;
   }
   if(ase[x]==0&&a<=x&&x<=b)
   {
       nf = 0; prime_fac(ar[x]);
       FOR(i,0,nf-1)
       {
           c=pfac[i]; d=tim[i];
           val[c]+=d;
           ///cout<<c<<' '<<val[c]<<NL;
           update(1,1,1000000,c,c,val[c]);
       }
       ase[x]=1;
   }
}
int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0
    sieve(1000001); /// range of sieve
         ///
    int ll,i,j,a,b,c,x,y,z,n,m;

    sf(n);///cin>>n;
    block=sqrt(n);
    FOR(i,1,n) sf(ar[i]);///cin>>ar[i];
    sf(m);///cin>>m;
    FOR(i,0,m-1) sff(boo[i].l,boo[i].r), sff(boo[i].x,boo[i].y), boo[i].p=i;
    sort(boo,boo+m,compare());

    x=y=0;
    FOR(i,0,m-1)
    {
       a=boo[i].l; b=boo[i].r;
       while(true)
       {
           up(x,a,b);
           if(x==a) break;
           else if(x<a)x++;
           else x--;

       }
       while(true)
       {
           up(y,a,b);
           if(y==b) break;
           else if(y<b)y++;
           else y--;

       }
       c=query(1,1,1000000,boo[i].x,boo[i].y);
       //cout<<c<<' '<<boo[i].x<<' '<<boo[i].y<<NL;
       ans[boo[i].p]=c;
    }
    FOR(i,0,m-1) pf("%d\n",ans[i]);
}
