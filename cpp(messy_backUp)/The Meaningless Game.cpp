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
#define maxx          (long long) 10000000000000000000
#define mod          10000000007
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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL  arr[sz], pfac[20+1], tim[20+1], nf;
map<pr,int> mp;

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

int main()
{
    ///ios::sync_with_stdio(false);
    ///inf;
    //outf;
    sieve(sz-1);
    int tc;
    sf(tc);//cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,n,m,a,b,c,x,y,z,k=0,ko,ka;

        sff(a,b);///cin>>a>>b;
        ko=a; ka=b; x=mp[MK(a,b)];
        if(x!=0)
        {
           if(x==1) pf("Yes\n");
           else pf("No\n");
           continue;
        }

        c=__gcd(a,b);
        FOR(i,2,1000)
        {
            if(c<1000000) break;
            if(a%i==0&&b%i==0)
            {
                x=0;
                while(a%i==0)
                {
                    x++;
                    a/=i;
                }

                y=0;
                while(b%i==0)
                {
                    y++;
                    b/=i;
                }
                //cout<<pfac[i]<<' '<<x<<' '<<y<<NL;
                while(x>0&&y>0)
                {
                    if(x>y) x-=2, y--;
                    else y-=2, x--;
                }

                if(x!=0||y!=0) k=1;
                c=__gcd(a,b);
            }
        }

        c=__gcd(a,b);
        if(c==1)
        {
            k=1;
            if(a<b&&a*a==b) k=0;
            else if(a==b*b) k=0;
        }
        else if(c>=1000000) k=1;
        else
        {
            nf=0; prime_fac(c);
            FOR(i,0,nf-1)
            {
                x=0;
                while(a%pfac[i]==0)
                {
                    x++;
                    a/=pfac[i];
                }

                y=0;
                while(b%pfac[i]==0)
                {
                    y++;
                    b/=pfac[i];
                }
                //cout<<pfac[i]<<' '<<x<<' '<<y<<NL;
                while(x>0&&y>0)
                {
                    if(x>y) x-=2, y--;
                    else y-=2, x--;
                }

                if(x!=0||y!=0) k=1;
            }
        }
        if(a!=1||b!=1) k=1;
        if(k==0) mp[MK(ko,ka)]=1;
        if(k==1) mp[MK(ko,ka)]=-1;
        if(k==0) pf("Yes\n");///cout<<"Yes"<<NL;
        else pf("No\n");///cout<<"No"<<NL;
    }
    return 0;
}


