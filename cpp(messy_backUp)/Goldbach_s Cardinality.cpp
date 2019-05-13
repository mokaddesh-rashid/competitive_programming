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
#define minn          (LL)-1000000000000000000
#define maxx          (LL) 1000000000000000000
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
#define MAX 10000010
#define sz  100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int  arr[MAX+1], prime[MAX+1], np;

void sieve( int n )
{
    int  m = sqrt(n), i, j;

    for( i=3; i<=m; i += 2)
        if( arr[i] == 0 )
            for( j=i*i; j<=n; j += (i+i) )
                arr[j]++;

    for( i=3; i<=n; i += 2)
        if( arr[i] == 0 )
            prime[np] = i,np++;

}

LL query(int v,int va)
{
    LL ret=0,a,b=np-1;
    FOR(i,0,np-1)
    {
        while(i<b&&prime[i]+prime[b]>v)
        {
            b--;
        }
        ///cout<<prime[i]<<' '<<prime[b]<<' '<<v<<NL;
        if(i<b)ret+=(b-i);
        else break;

    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);

    np = 0; /// number of prime initially 0
    sieve(MAX); /// range of sieve

    int n,a,b,c;

    FOR(i,1,2000)
    {
        cin>>a>>b;
        if(a==0&&b==0)break;
        cout<<query(b)-query(a-1)<<NL;
    }


}

