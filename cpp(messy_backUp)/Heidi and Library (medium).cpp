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
#define MAX 100010
#define sz 400010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

class compare
{
public:
    bool operator()(pr x,pr y)
    {
        if(x.F==y.F) return x.S<y.S;
        return x.F>y.F;
    }
};
set<pr,compare> ms, use;
set<pr>::iterator it;
int val[sz], ase[sz], ar[sz], nex[sz], pre[sz];
pr ck;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(val,-1);
    int i,j,x,y,n,m,k,a,b,c=0,co=0;

    cin>>n>>k;
    FOR(i,0,n-1) cin>>ar[i];

    REV(i,n-1,0)
    {
        x=ar[i];
        if(val[x]==-1) nex[i]=mod;
        else nex[i]=val[x];
        val[x]=i;
    }

    FOR(i,0,n-1)
    {
       ///cout<<i<<' '<<ase[ar[i]]<<NL;
       x=ar[i]; y=nex[i];
       if(ase[x]==0)
       {
           if(c==k)
           {
               it=ms.begin(); ck=*it;
               ms.erase(ck);
               ase[ck.S]=0; c--;
           }
           ase[x]=1; c++; co++;
           ms.insert(MK(y,x));
       }
       else
       {
          ms.insert(MK(y,x));
       }
       ///cout<<NL;
    }

    cout<<co<<NL;
    return 0;
}


