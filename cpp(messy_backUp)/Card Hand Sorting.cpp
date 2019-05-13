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
#define MAX 100010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[4],val[60],ty[5],mo;
char type[]={'s','h','d','c'};
string in[70];

int ret_val(string str)
{
    int a,b,c,x;
    if(str[0]=='T')a=10;
    else if(str[0]=='J')a=11;
    else if(str[0]=='K')a=12;
    else if(str[0]=='Q')a=13;
    else if(str[0]=='A')a=14;
    else a=str[0]-'0';

    FOR(i,0,3)if(type[i]==str[1])b=ar[i],x=i;
    if(ty[x])a=15-a;

    c=b*14+a;
    mo=max(mo,c);

    return c;
}

int dp[60][100],n;
int rec(int p,int v)
{
    if(p==n)return 0;
    if(dp[p][v]!=-1)return dp[p][v];

    if(val[p]>v)return dp[p][v]=max(1+rec(p+1,val[p]),rec(p+1,v));
    else return dp[p][v]=rec(p+1,v);

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m=0,t=25;

    cin>>n;
    FOR(i,0,n-1)cin>>in[i];

    FOR(i,0,3)ar[i]=i;

    while(t--)
    {
        FOR(l,0,31)
        {
            FOR(i,0,3)ty[i]=l&(1<<i);
            FOR(i,0,n-1)
            {
               val[i]=ret_val(in[i]);
            }

            mem(dp,-1);
            m=max(m,rec(0,0));
        }

       next_permutation(ar,ar+4);
    }
    cout<<max(0,n-m)<<NL;

    return 0;
}


