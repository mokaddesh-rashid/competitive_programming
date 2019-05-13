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
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

LL  arr[500000+1], prime[100000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
void sieve( LL n )
{
    LL  m = sqrt(n), i, j;
    for( i=2; i<=m; i++)
    {
        if( arr[i] == 0 )
            for( j=i ; j<=n; j += i )
                arr[j] = i ;
    }
    for( i=3 ; i <= n; i += 2)
        if( arr[i] == 0 ) arr[i] = i;
}
void prime_fac( LL  n )
{
     while( n > 1 )   //for( LL  i=0; i<np && prime[i] <= m ; i++ )
     {
       if( pfac[nf-1] == arr[n] )
           tim[nf-1]++;
       else
       {
           pfac[nf] = arr[n];
           tim[nf] = 1;
           nf++;
       }
       n /= arr[n];
     }
}
int ar[500010],cnt[500010], ase[100010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0
    sieve(500001);
    LL i, j, x, y, n, m, c=0, a=0, z;
    cin >> n >> m ;
    FOR(i,1,n) cin>>ar[i];
    FOR(i,1,m)
    {
       cin>>x;
       //cout<<endl;
       if(ase[x]==0)
       {
           int nob, v, ooh;
           nob=nf=0;
           v=1;
           ooh=c;
           prime_fac(ar[x]);
           z=1<<nf;
           FOR(k,1,z-1)
           {
               nob=0;
               v=1;
               FOR(j,0,nf-1)
               {
                   if(k&(1<<j))
                   {
                      nob++;
                      v*=pfac[j];
                   }
               }
               //cout<<ooh<<' '<<cnt[v]<<' '<<nob<<' '<<c<<' '<<v<<endl;
               if(nob%2)ooh-=cnt[v];
               else ooh+=cnt[v];
               cnt[v]++;
               //cout << v << 'k';
           }
           a+=ooh; ase[x]=1; c++;
       }
       else
       {
           int nob, v, ooh;
           nob=nf=0;
           v=1;
           c--;ooh=c;
           prime_fac(ar[x]);
           z=1<<nf;
           FOR(k,1,z-1)
           {
               nob=0;
               v=1;
               FOR(j,0,nf-1)
               {
                   if(k&(1<<j))
                   {
                      nob++;
                      v*=pfac[j];
                   }
               }
               cnt[v]--;
               //cout<<v<<' '<<cnt[v]<<endl;
               if(nob%2) ooh-=(cnt[v]);
               else ooh+=(cnt[v]);
           }
           //cout<<ooh<<endl;
           a-=ooh; ase[x]=0;
       }
       cout<<a<<endl;
    }
    return 0;
}


