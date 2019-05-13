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
#define sz 1010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,m,p,mat[sz][sz], job[sz], vis[sz], nex[sz];

bool bpm(int p)
{
    FOR(i,1,n)
        if(mat[p][i]!=0&&vis[i]==0&&job[i]==0)
        {
                job[i]=p;
                nex[p]=i;
                return true;
        }

    FOR(i,1,n)
    {
        if(mat[p][i]!=0&&vis[i]==0)
        {
            vis[i]=1;
            if(bpm(job[i]))
            {
                job[i]=p;
                nex[p]=i;
                return true;
            }
        }
    }

    return false;
}

int ar[sz];
pr ans[sz];

int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    ///outf;
    int tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0); mem(job,0); mem(nex,0);
        mem(ans,0);
        int i,j,cnt=0,a,b,x,c;

        sf(n);///cin>>n>>p;

        map<int,int>mp;
        FOR(i,1,n)
        {
            sf(a);
            if(mp[a]==0) ar[++cnt]=a;
            mp[a]=i;
        }
        n=cnt;

        FOR(i,1,n)
            FOR(j,1,n)
                if(i!=j&&ar[j]%ar[i]==0) mat[i][j]=1;

        FOR(i,1,n)
        {
            mem(vis,0);
            if(bpm(i));
        }

        mem(vis,0); cnt=0;
        FOR(i,1,n)
        {
            ///cout<<ar[i]<<' '<<ar[nex[i]]<<' '<<"do\n";
            if(job[i]==0) ans[++cnt].F=ar[i], ans[cnt].S=i;

        }
        c=1;
        while(c==1)
        {
            c=0;
            sort(ans+1,ans+cnt+1);
            FOR(i,1,cnt)
            {
                FOR(j,i+1,cnt)
                {
                    if(ans[i].F==0)
                    {
                        ///cout<<NL<<i<<NL;
                        break;
                    }
                    if(ans[j].F%ans[i].F==0)
                    {
                       /// cout<<"OK";
                        a=ans[i].S;
                        b=nex[a];
                        ////cout<<ans[i].F<<' '<<ar[b]<<NL;
                        ans[i].F=ar[b]; ans[i].S=b;
                        c=1;
                    }
                }
            }
        }
        sort(ans+1,ans+cnt+1);
        ///cout<<cnt<<NL;

        pf("Case %d: ",tt);
        FOR(i,1,cnt)
        {
            pf("%d",ans[i].F);
            if(i!=cnt) pf(" ");
        }
        pf("\n");
        //cout<<"Case "<<tt<<": "<<cnt<<NL;
    }

    return 0;
}
/*
1
79
46 69 63 67 73 46 37 1 90 60 4 10 82 39 83 37 77 43 71 89 65 36 18 11 45 47 51 46 6 12 75 19 88 21 22 64 68 39 46 96 52 100 85 78 55 85 81 5 39 24 97 17 41 93 73 74 72 37 66 57 41 51 11 81 81 87 8 76 75 54 21 70 55 91 33 97 63 3 19
*/



