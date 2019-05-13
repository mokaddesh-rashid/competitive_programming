#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
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
#define sz 110
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL dp[sz][sz][2], sm[sz], ar[sz];

LL rec(int l,int r,int k)
{
   if(l>r) return 0;
   ///if(dp[l][r][k]!=-1) return dp[l][r][k];
   LL temp,a;
   if(k==0)
   {

     a=0;temp=minn;
     FOR(i,l,r)
     {
         a+=ar[i];
         temp=max(temp,a+rec(i+1,r,1));
     }

     a=0;
     REV(i,r,l)
     {
        a+=ar[i];
        temp=max(temp,a+rec(l,i-1,1));
     }
   }
   else
   {

     a=0;temp=maxx;;
     FOR(i,l,r)
     {
         a+=ar[i];
         temp=min(temp,(a*-1)+rec(i+1,r,0));
     }

     a=0;
     REV(i,r,l)
     {
        a+=ar[i];
        temp=min(temp,(a*-1)+rec(l,i-1,0));
     }
   }

   return dp[l][r][k]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    while(true)
    {
        mem(dp,-1);
        LL i,j,x,y,n,m;

        sf(n);///cin>>n;
        if(n==0) break;
        FOR(i,0,n-1) sf(ar[i]);///cin>>ar[i];
        pf("%lld\n",rec(0,n-1,0));
        //cout<<<<NL;
    }
    return 0;
}


