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

int org[sz][sz], mat[sz][sz], n, m, maf, c_f, s, t;
int que[sz], vis[sz],h, r, p, pa[sz], med[sz];

int bfs(int s)
{
    mem(vis,0);
    h=r=0;
    que[r]=s; r++;
    med[s]=mod; ///check max value

    while(h!=r)
    {
        p=que[h]; h++; vis[p]=1;
        ///cout<<p<<" = ";
        FOR(i,0,n)
        {
           if(mat[p][i]>0&&vis[i]==0)
           {
               ///cout<<i<<' ';
               med[i]=min(med[p],mat[p][i]);
               pa[i]=p; vis[i]=1; que[r]=i; r++;
           }

        }
        ///cout<<NL;
        ///if(p==t) break;
    }

    if(vis[t]==0) return 0;
    else
    {
        int a,b,c;

        a=pa[t]; b=t; c=med[t];
        while(true)
        {
            mat[a][b]-=c;
            mat[b][a]+=c;
            if(a==s) break;

            a=pa[a]; b=pa[b];
        }

        return c;
    }
}

void solve()
{
    maf=0;
    while(true)
    {
        int c=bfs(s);
        maf+=c;
        if(c==0) break;
    }
    return;
}

int chk(string str)
{
    if(str=="XXL") return 1;
    if(str=="XL") return 2;
    if(str=="L") return 3;
    if(str=="M") return 4;
    if(str=="S") return 5;
    if(str=="XS") return 6;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0); mem(org,0);
        int i,j,a,b,c,d,x,y,z;
        string str, ss;

        cin>>n>>m; x=6+m;
        FOR(i,1,x)
        {
            if(i<=6) mat[i][i+x]=n, mat[0][i]=mod;///, cout<<i<<' '<<i+x<<' '<<n<<NL<<0<<' '<<i<<' '<<mod;
            else mat[i][i+x]=1, mat[i+x][x+x+1]=mod;///, cout<<i<<' '<<i+x<<' '<<n<<NL<<i+x<<' '<<i<<' '<<mod;;


        }
        n=x+x+1;
        FOR(i,7,x)
        {
            cin>>str>>ss;
            a=chk(str); b=chk(ss);
            mat[a+x][i]+=1;
            mat[b+x][i]+=1;
        }

        s=0; t=n;
        solve();

        if(maf==m)cout<<"Case "<<tt<<": YES"<<NL;
        else cout<<"Case "<<tt<<": NO"<<NL;
    }

    return 0;
}

