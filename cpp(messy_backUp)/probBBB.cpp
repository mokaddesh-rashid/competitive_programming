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

int ar[1000010];
void sieve( LL n )
{
    LL  m = sqrt(n), i, j;
    //prime[np] = 2;
   // np++;
    for( i=2; i<=m; i ++)
    {
        if( ar[i] == 0 )
         {
            for( j=i ; j<=n; j += i )
                ar[j] = i ;
         }
    }

    for( i=3 ; i <= n; i += 2)
    {
        if( ar[i] == 0 )
         {
            ar[i] = i;
         }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m;
    sieve(100010);
    cin>>n;
    if(n+1<=3) cout<<1<<NL;
    else cout<<2<<NL;

    FOR(i,2,n+1)
    {
        if(ar[i]==i) cout<<1<<' ';
        else cout<<2<<' ';
    }

    FOR(i,2,n+1)
    {

    }
    return 0;
}
