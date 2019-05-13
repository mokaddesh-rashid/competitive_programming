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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int  arr[MAX], prime[MAX], np, pfac[22], tim[22], nf;

void sieve(int n )
{
    int  m = sqrt(n), i, j;
    prime[np] = 2;
    np++;

    for(int i = 3; i <= m; i += 2)
    {
        if(!arr[i])
            for(int j = i*i; j <= n; j += (i+i) ) arr[j]++;
    }

    for(int i=3; i<= n; i += 2)
        if(!arr[i])
            prime[np] = i, np++;

    return;
}



void prime_fac(int  n )
{
    int  m = sqrt(n);
    nf = 0;

    for(int  i = 0; i < np && prime[i] <= m; i++)
    {
        if( n % prime[i] == 0 )
        {
            int  a = 0;

            while(n % prime[i] == 0)
            {
                a++;
                n /= prime[i];

            }

           pfac[nf] = prime[i]; tim[nf] = a;
           nf++;
           m = sqrt(n);
        }
    }

    if(n != 1)
    {
       pfac[nf] = n; tim[nf] = 1;
       nf++;
    }
}

int ara[MAX], prema[MAX], n, m;

int getVal(int v)
{
    int ret = 0;

    prime_fac( v );

    FOR(i,0,nf-1)
    {
        int x = pfac[i];

        int p = lower_bound(prema, prema + m, x) - prema;

        if(prema[p] == x) ret -= tim[i];
        else ret += tim[i];
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    sieve(MAX - 1);

    cin >> n >> m;
    FOR(i,0,n-1) cin >> ara[i];
    FOR(i,0,m-1) cin >> prema[i];

    REV(i,n-1,0)
    {
        int g = 1;

        FOR(j,0,i)
        {
            if(j == 0) g = ara[j];
            else g = __gcd(g, ara[j]);
        }

        int v = getVal( g );

        if(v < 0)
            FOR(j,0,i) ara[j] /= g;
    }

    int prin = 0;
    FOR(i,0,n-1)
        prin += getVal( ara[i] );


    //cout << getVal(5) << endl;
    cout << prin << endl;

    return 0;
}


