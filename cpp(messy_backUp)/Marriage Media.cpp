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
#define sz 1010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL n,m,p,mat[sz][sz], job[sz], vis[sz];

bool bpm(LL p)
{
    FOR(i,1,m)
        if(mat[p][i]!=0&&vis[i]==0&&job[i]==0)
        {
                job[i]=p;
                return true;
        }

    FOR(i,1,m)
    {
        if(mat[p][i]!=0&&vis[i]==0)
        {
            vis[i]=1;
            if(bpm(job[i]))
            {
                job[i]=p;
                return true;
            }
        }
    }

    return false;
}

struct info
{
    int ag, he, di;
}ar[sz], br[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    ///outf;
    LL tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0); mem(job,0);
        LL i,j,cnt=0,a,b;

        cin>>n>>m;
        FOR(i,1,n) cin>>ar[i].he>>ar[i].ag>>ar[i].di;
        FOR(i,1,m) cin>>br[i].he>>br[i].ag>>br[i].di;

        FOR(i,1,n)
            FOR(j,1,m)
            {
               if(abs(ar[i].he-br[j].he)<=12 && abs(ar[i].ag-br[j].ag)<=5 && ar[i].di==br[j].di)
               {
                   mat[i][j]=1;
                   ///cout<<i<<' '<<j<<NL;
               }
            }


        FOR(i,1,n)
        {
            mem(vis,0);
            if(bpm(i)) cnt++;
        }

        cout<<"Case "<<tt<<": "<<cnt<<NL;
    }
    ///FOR(i,1,m) cout<<i<<' '<<' '<<job[i]<<NL;
    return 0;
}




