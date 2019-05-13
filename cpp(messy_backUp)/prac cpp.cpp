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

int k,n,ck,l,dis[14][14];
int vis[14],bru[14],baki[14],br,ba;
set<pr> sota;

int fac(int p)
{
    if(p==1)return 1;
    return p*fac(p-1);
}
void chk()
{
    map<pr,int>mopa;
    while(!sota.empty())
    {
        sota.erase(sota.begin());
    }
    //cout<<"OK"<<NL;
    int t=fac(ba);
    LL cnt=1,a,b,d;
    pr use,ruse;

    while(t--)
    {
        LL c=0;
        FOR(i,0,ba-2) c+=dis[baki[i]][baki[i+1]];

        use.F=baki[0]; use.S=baki[ba-1];
        if(mopa[use]==0)mopa[use]=cnt++;
        a=mopa[use];
        sota.insert(MP(a,c));
        ///cout<<use.F<<' '<<use.S<<' '<<' '<<c<<NL;

        next_permutation(baki,baki+ba);
    }
    ///cout<<NL<<NL;
    t=fac(br);
    while(t--)
    {
        LL c=0,d=0,x,y;
        FOR(i,0,br-2) c+=dis[bru[i]][bru[i+1]];


        FOR(i,0,ba-1)
        {
            FOR(j,0,ba-1)
            {
                a=bru[0]; b=bru[br-1];
                if(i!=j)
                {
                    x=baki[i]; y=baki[j];
                    d=l-(c+dis[b][x]+dis[a][y]);
                    use.F=x; use.S=y;
                    ///cout<<a<<' '<<b<<' '<<x<<' '<<y<<' '<<d<<NL;
                    a=mopa[MP(x,y)];
                    if(sota.find(MP(a,d))!=sota.end())ck=1;
                }
            }
        }

        next_permutation(bru,bru+br);
    }
     ///cout<<NL<<NL; cout<<NL<<NL;
}

void rec(int p,int v)
{
    if(v==k)
    {
        br=ba=0;
        FOR(i,1,n)
        {
            if(vis[i])bru[br++]=i;
            else baki[ba++]=i;
        }
        chk();
        return;
    }
    if(p>n)return;

    FOR(i,p,n) vis[i]=1,rec(i+1,v+1),vis[i]=0;

}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;

    cin>>n>>l; k=n/2;
    FOR(i,1,n)
        FOR(j,1,n)cin>>dis[i][j];

    rec(1,0);
    if(ck)cout<<"possible"<<NL;
    else cout<<"impossible"<<NL;
    return 0;
}
