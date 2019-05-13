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
#define sz 5000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


LL  arr[sz+1], prime[sz+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( LL n )
{
    LL  m=sqrt(n), i, j;
    for(i=2;i<=m;i++)
    {
        if(arr[i]==0)
         {
            for(j=i;j<=n;j+=i)
                arr[j]=i;
         }
    }
    for(i=3;i<=n;i+=2)
    {
        if(arr[i]==0)
         {
            arr[i]=i;
         }
    }
}
void prime_fac(LL n)
{
    while(n>1)   //for( LL  i=0; i<np && prime[i] <= m ; i++ )
    {
       if(pfac[nf-1]==arr[n])
       {
           tim[nf-1]++;
       }
       else
       {
           pfac[nf]=arr[n];
           tim[nf]=1;
           nf++;
       }
       n /= arr[n];
    }
}


vector<int>mat[sz];
void divisor(int p)
{
    LL i, j, k, x;
    for(i=0;i<nf;i++)
    {
        LL temp=nd;
        x=1;
        for(j=0;j<tim[i];j++)
        {
            x=x*pfac[i];
            for(k=0;k<temp;k++)
            {
                divi[nd]=divi[k]*x;
                mat[p].PB(divi[nd]);
                ///cout << divi[nd] << ' ';
                nd++;
            }
        }
    }
}

LL dp[sz];
LL rec(int n)
{
    //cout<<n<<NL;
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 3;
    if(dp[n]!=-1) return dp[n];

    LL a,b,c;
    dp[n]=( ((n)*(n-1))/2 )%mod;
    FOR(i,0,(int)mat[n].size()-1)
    {
        a=n/mat[n][i];
        b=mat[n][i];
        b=b*(b-1)/2;
        if(mat[n][i]!=1) dp[n]=min(dp[n],(a*rec(mat[n][i])+b)%mod);
    }
    return dp[n];
}

LL ans[sz];

int main()
{
   // ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0
    sieve(sz); /// range of the sieve


    LL n , x, y=0, i, m, l, r, c=0, a;
    cin>>x>>l>>r;

    FOR(i,l,r)
    {
        n = i; /// number jr prime fac krbo and divisor find krbo
        nf = 0; /// number of fac intially zero
        prime_fac(n);
        divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
        nd = 1;
        divisor(i);
    }

    mem(dp,-1);
    FOR(i,l,r)
    {
        ans[i]=rec(i);
        //cout<<i<<' '<<rec(i)<<NL;
    }


    y=1;
    FOR(i,l,r)
    {
      a=(ans[i]*y)%mod;
      c += a;

      y=y*x;
      y%=mod;
      c%=mod;
    }

    cout<<c<<NL;

    return 0;
}




