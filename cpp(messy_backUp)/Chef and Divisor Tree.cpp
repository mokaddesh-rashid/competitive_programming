#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

map<LL,LL> mp;
map<LL,LL>::iterator it;
LL arr[1000010],prime[1000010],np;
vector<LL>mat[1000010];

class Compare
{
public:
    bool operator()(LL x,LL y)
    {
        return x>y;
    }
};
void sieve(LL n)
{
    LL m=sqrt(n),i,j;
    prime[np]=2;
    np++;
    for(i=3;i<=m;i+=2)
    {
        if(arr[i]==0)
         {
            for(j=i*i;j<=n;j+=(i+i))
                arr[j]++;
         }
    }
    for(i=3;i<=n;i+=2)
    {
        if(arr[i]==0)
         {
            prime[np]=i;
            np++;
         }
    }
}
int main()
{
   // ios::sync_with_stdio(false);
    sieve(1000000);
    //sort(prime,prime+np);
    //cout<<prime[np-1]<<NL;
    LL i,j,a,b,c,x,y,z,n,m,d;
    cin>>n>>m;
    x=0;
    FOR(i,n,m)
    {
      mp[i]=x; x++;
    }
    FOR(i,0,np-1)
    {
        x=n%prime[i]; if(n%prime[i])x=prime[i]-x;
        FORR(j,n+x,m,prime[i])
        {
            a=mp[j]; mat[a].PB(prime[i]);
        }
    }
    LL ans=0;
    FOR(k,n,m)
    {
        d=1; z=0;
        b=c=a=0;
        x=mp[k]; a=k;
        multiset<LL,Compare>ms;
        multiset<LL,Compare>::iterator ii;
        FOR(j,0,(LL)mat[x].size()-1)
        {
            c=1;
            b=mat[x][j];
            while(a%b==0)
            {
                c++;
                a/=b;
            }
            d=c*d;
            ms.insert(c);
        }
        //cout<<d<<NL;
        if(a>1)
        {
            d=d*2;
            ms.insert(2);
        }
        z+=d;
        while(!ms.empty())
        {
            ii=ms.begin(); ms.erase(ms.begin());
            a=*ii; d=d/a; a--;
            d=d*a;
            z+=d;
            if(a>1) ms.insert(a);
        }
        ans--;
        ans+=z;
    }
    cout<<ans;
    return 0;
}
