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


//set<int>::iterator ii;



LL  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
void sieve( LL n )
{
    LL  m = sqrt(n), i, j;
    for( i=2; i<=m; i ++)
    {
        if( arr[i] == 0 )
         {
            for( j=i ; j<=n; j += i )
                arr[j] = i ;
         }
    }

    for( i=3 ; i <= n; i += 2)
    {
        if( arr[i] == 0 )
         {
            arr[i] = i;
         }
    }


}
int main()
{
   // ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0
    sieve(4000005); /// range of the sieve
    int n, m, a=0, i;
    cin>>n;
    FOR(i,1,1000)
    {
        a=n*i+1;
        if(arr[a]!=a)
        {
            cout<<i<<endl;
            break;
        }
    }

}




