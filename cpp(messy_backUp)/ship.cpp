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
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int  arr[MAX+1], prime[MAX+1], np, pfac[20+1], tim[20+1], nf, divi[MAX], nd, val[MAX];

void sieve( LL n )
{
    LL  m=sqrt(n), i, j;
    for(i=2;i<=m;i++)
        if(arr[i]==0)
            for(j=i;j<=n;j+=i) arr[j]=i;

    for(i=3;i<=n;i+=2)
        if(arr[i]==0) arr[i]=i;
}
void prime_fac(LL n)
{
    while(n>1)
    {
       if(pfac[nf-1]==arr[n]) tim[nf-1]++;
       else
       {
           pfac[nf]=arr[n];
           tim[nf]=1;
           nf++;
       }
       n /= arr[n];
    }
}

void divisor(int n)
{
    nf = 0;
    prime_fac(n);

    divi[0] = 1;
    nd = 1;

    int i, j, k, x;
    for(i=0;i<nf;i++)
    {
        int temp=nd;
        x=1;
        for(j=0;j<tim[i];j++)
        {
            x=x*pfac[i];
            for(k=0;k<temp;k++)
            {
                divi[nd]=divi[k]*x;
                nd++;
            }
        }
    }

}


const int N = 2e4 + 5;

vector<int> g[N];
int mt[N];
int used[N];
int T = 1;

bool try_kuhn(int v)
{
    if (used[v] == T)
        return false;
    used[v] = T;

    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }

    for (auto to : g[v]) {
        if (try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }

    return false;
}

int lf[MAX], rg[MAX], ara[MAX];
char ch[MAX];

void add_edge(int u,int v)
{
    g[u].PB( v );
}

void solve()
{
    int n;
    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];
    FOR(i,0,n-1) cin >> ch[i];

    FOR(i,0,n-1)
    {
        divisor( ara[i] );
        FOR(k,1,nd-1)
        {
            if(ch[i] == 'F') lf[ divi[k] ] = i + 1;
            else rg[ divi[k] ] = i + 1;
        }
    }

    FOR(i,0,n-1)
    {
        if(ch[i] != 'F') continue;

        divisor( ara[i] );

        FOR(k,1,nd-1)
            if(rg[ divi[k] ]) add_edge(lf[ ara[i] ], rg[ divi[k] ]);
    }

    memset(mt, -1, sizeof(mt));
    int match = 0;
    for (int i = 0; i <= n; ++i) {
        if (try_kuhn(i))
        {
            ++T;
            ++match;
        }
    }

    cout << n - match << endl;

    FOR(i,0,n-1)
    {
        divisor( ara[i] );
        FOR(k,1,nd-1)
        {
            if(ch[i] == 'F') lf[ divi[k] ] = 0;
            else rg[ divi[k] ] = 0;
        }
    }
    FOR(i,0,n+2) g[i].clear();
}


int main()
{
    ios::sync_with_stdio(false);
    sieve(MAX);

    int tc;

    cin >> tc;
    FOR(tt,1,tc) solve();
}
