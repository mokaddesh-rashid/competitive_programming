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
#define MAX 500010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


int bin[65],val,con[MAX][2], id;

void in(int m)
{
   int t=0;
   int x=m, a;

   while(x>=0)
   {
       a=bin[x];
       if(con[t][a]==-1) con[t][a]=++id,val++;
       t=con[t][a];
       x--;
   }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(con,-1);
    LL i,j,x,y,n,m,c=0;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>x; m=0;
        FOR(j,0,63)
        {
            if(x&((LL)1<<j)) bin[j]=1, m=max(m,(LL)j);
            else bin[j]=0;
            ///cout<<bin[j]<<' ';
        }
        ///cout<<NL<<x<<' '<<m<<NL;
        in(m);
    }
    cout<<val-1<<NL;
    return 0;
}



