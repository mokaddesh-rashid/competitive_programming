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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int  arr[MAX+1], prime[MAX+1], np, pfac[20+1], tim[20+1], nf, divi[MAX], nd, val[MAX];

void sieve( LL n )
{
    LL  m=sqrt(n), i, j;
    for(i=2;i<=m;i++)
        if(arr[i]==0)
            for(j=i;j<=n;j+=i)
                arr[j]=i;

    for(i=3;i<=n;i+=2)
        if(arr[i]==0)
            arr[i]=i;
}
void prime_fac(LL n)
{
    while(n>1)   //for( LL  i=0; i<np && prime[i] <= m ; i++ )
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
    nf = 0; /// number of fac intially zero
    prime_fac(n);

    divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
    nd = 1;

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
                nd++;
            }
        }
    }

}


vector<int> mat[MAX];
int mal[MAX], beu[MAX], lev[MAX];

void dfs(int p,int pa)
{
    int ma=1;
    divisor(mal[p]);
    FOR(i,0,nd-1)
    {
        val[divi[i]]++;
        if(val[divi[i]]>lev[p]) ma=max(ma,divi[i]);
        if(val[divi[i]]>=lev[p]) beu[p]=max(beu[p],divi[i]);
    }

    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            lev[x]=lev[p]+1;
            beu[x]=ma;
            dfs(x,p);
        }
    }

    divisor(mal[p]);
    FOR(i,0,nd-1)  val[divi[i]]--;
}

int main()
{
    ios::sync_with_stdio(false);
    np = 0; /// number of prime initially 0
    sieve(MAX); /// range of the sieve

    int n,m,a,b,c,x,y,z;

    cin>>n;
    FOR(i,1,n) cin>>mal[i];
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    dfs(1,1);
    FOR(i,1,n)cout<<beu[i]<<' ';
}







