#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define sfff(a,b,c)    scanf("%I64d %I64d %I64d", &a, &b, &c)
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
#define sz 500010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL cnt[sz], ar[sz], vis[sz], owk[sz],ans[sz],cln[sz];
map<LL,LL>mp;
map<LL,LL>::iterator it;
vector<LL> tr;

int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,n,m,c=0,a=0,b,d,z=1,k=0,p,l;

    sfff(n,m,p);//cin>>n>>m>>p;
    FOR(i,0,n-1)
    {
        sf(a);///cin>>a;
        if(mp[a]==0) mp[a]=z, z++;
        ar[i]=mp[a];
    }
    FOR(i,0,m-1)
    {
        sf(a);///cin>>a;
        if(mp[a]==0) mp[a]=z, z++;
        a=mp[a];
        cnt[a]++;
        if(cnt[a]==1) cln[k]=a,k++;
    }

    FOR(i,0,n-1)
    {
        a=0;
        if(vis[i]==0 && (i+p*(m-1))<n)
       {
            FOR(j,0,k-1)
            {
                owk[cln[j]]=0;
            }
            FOR(j,0,m-1)
            {
              x=i+(p*j); x=ar[x];

              owk[x]++;
              if(cnt[x]==owk[x]) a++;
            }
            j=i;
            l=i+p*(m-1);

            while(l<n)
            {
               vis[j]=1;
               if(a==k) ans[c]=j,c++;

               x=ar[j];
               if(cnt[x]==owk[x]) a--;
               owk[x]--;
               j+=p;

               if(p+l<n)
               {
                   l+=p; x=ar[l];
                   owk[x]++;
                   if(cnt[x]==owk[x]) a++;
               }
               else {break;}
            }
       }
    }

    ///cout<<c<<NL;
    pf("%I64d\n",c);
    sort(ans,ans+c);
    FOR(i,0,c-1) pf("%I64d ",ans[i]+1);;///cout<<ans[i]+1<<' ';
    return 0;
}


