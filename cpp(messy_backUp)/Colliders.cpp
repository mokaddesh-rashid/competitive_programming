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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;



long long  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( long long n )
{
    long long  m = sqrt(n), i, j;
    //prime[np] = 2;
   // np++;
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

void prime_fac( long long  n )
{
   // long long  m = sqrt(n);
    while( n > 1 )   //for( long long  i=0; i<np && prime[i] <= m ; i++ )
    {
           if( pfac[nf-1] == arr[n] )
           {
               tim[nf-1]++;
           }
           else
           {
               pfac[nf] = arr[n];
               tim[nf] = 1;
               nf++;
           }
           n /= arr[n];

    }

}

long long k = 100001, sum[100003], cnt[100003], j = 0, con[100003];

int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0
    sieve(100005); /// range of the sieve
    long long n , x, y=0, i, m, t, a, b, c, d;

    char ch;
    cin>>m>>t;

    while(t--)
    {
        cin >> ch;
        cin >> n; /// number jr prime fac krbo and divisor find krbo
        nf = 0; /// number of fac intially zero
        prime_fac(n);
        c = 0;
        FOR(i,0,nf-1)
        {
            if( cnt[pfac[i]] > 0 )
                c = 1,a = con[pfac[i]];
        }

        if(ch=='+')
        {
            if(sum[n]==1) cout<<"Already on\n";
            else if(c==0)
            {
                cout<<"Success\n";
                FOR(i,0,nf-1)
                {
                    cnt[pfac[i]]++;
                    con[pfac[i]] = n;
                }
                sum[n]++;
            }
            else
            {
                cout<<"Conflict with "<<a<<NL;
            }

        }
        else
        {
            if(sum[n]==1)
            {
                cout << "Success\n";
                FOR(i,0,nf-1)
                {
                    cnt[pfac[i]]--;
                    con[pfac[i]] = 0;
                }
                sum[n]--;
            }
            else
            {
                cout<<"Already off\n";
            }
        }
    }
}
