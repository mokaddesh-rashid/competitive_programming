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
#define hm           100000000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[300010],n,k;
string str,ss;
int dp[300010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(dp,0);
        LL i,j,x,y,a,b,c,m,z;
        cin>>str>>ss;
        n=0; k=ss.size(); m=str.size();

        c=0; b=1;
        REV(i,k-1,0)
        {
            x=ss[i]-'a'; x++;
            a=x*b; c+=a;
            b=b*29;
            c%=hm; b%=hm;
        }

        z=0;  b=1;
        REV(i,k-1,0)
        {
            x=str[i]-'a'; x++;
            a=x*b; z+=a;
            if(i!=0)b=b*29;
            z%=hm; b%=hm;
        }

        FOR(i,0,m-k)
        {
            //cout<<z<<' '<<c<<NL;
           if(z==c) ar[n]=i,n++;

           x=str[i]-'a'; x++; a=x*b; a%=hm;
           z=z+hm; z=z-a; z=z*29;
           x=str[i+k]-'a'; x++; z+=x; z%=hm;
        }


        REV(i,n-1,0)
        {
            b=lower_bound(ar,ar+n,ar[i]+k)-ar;
            dp[i]=(1+dp[i+1]+dp[b])%mod;
            //cout<<i<<' '<<dp[i]<<NL;
        }
        cout<<dp[0]<<NL;
    }
    return 0;
}

