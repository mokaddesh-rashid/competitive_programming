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
#define mod          100000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int mat[211][211], vis[211], pa[211], wor[211], ole[200];

int n,s,t;
void dfs(int p, int c)
{
    //cout<<p<<' '<<c<<NL;
    int x;
    vis[p]=1; wor[p]=c;
    FOR(i,1,t)
    {
        if(vis[i]==0&&mat[p][i]>0&&ole[p]>0&&ole[i]>0)
        {
            pa[i]=p;
            if(p==s) c=mat[p][i];
            else c=min(c,mat[p][i]);
            c=min(c,ole[p]); c=min(c,ole[i]);
            dfs(i,c);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    sf(tc);
    FOR(tt,1,tc)
    {
        mem(mat,0);
        int i, j, x, y,m,a,b,c,d=0,z,k;
        sf(n);///num of node
        FOR(i,1,n)
        {
            sf(ole[i]);
        }

        s=0;t=n+1;
        sf(m); ///s source , t destination, m connection
        FOR(i,1,m)
        {
            sfff(a,b,c);///cin>>a>>b>>c;
            mat[a][b]+=c;
           // cout<<a+n<<' '<<b<<NL;
        }
        sff(x,y); z=x+y;
        FOR(i,1,z)
        {
            sf(a);//cin>>a;
            if(i<=x) mat[s][a]=mod;//, cout<<0<<' '<<a<<NL;
            else mat[a][t]=mod;//, cout<<a+n<<' '<<t<<NL;;

        }
        ole[0]=mod; ole[t]=mod;
        while(true)
        {
            mem(vis,0);
            dfs(s,0);
            //cout<<vis[t]<<' '<<NL;
            if(vis[t]==0) break;
            x=t;
            while(true)
            {
                if(x==s) break;
                ole[x]-=wor[t];
                y=pa[x];
                mat[y][x]-=wor[t];
                mat[x][y]+=wor[t];
                x=y;
            }
            d+=wor[t];
        }
        pf("Case %d: %d\n",tt,d);
        //cout<<d<<NL;
    }
    return 0;
}



