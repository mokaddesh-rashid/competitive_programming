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
        cout<<p<<" = ";
        FOR(i,1,n)
        {
           if(mat[p][i]>0&&vis[i]==0)
           {
               cout<<i<<' ';
               med[i]=min(med[p],mat[p][i]);
               pa[i]=p; vis[i]=1; que[r]=i; r++;
           }

        }
        cout<<NL;
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

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(mat,0); mem(org,0);
    int i, j, a, b, c, d;

    cin>>n>>m;
    FOR(i,0,m-1)
    {
        cin>>a>>b>>c;/// for directional graph
        mat[a][b]+=c;
        org[a][b]+=c;
    }
    cin>>s>>t;
    solve();

    cout<<maf<<NL;

    return 0;
}
