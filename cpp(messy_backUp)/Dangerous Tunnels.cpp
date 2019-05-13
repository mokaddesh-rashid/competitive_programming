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

int org[sz][sz], mat[sz][sz], n, m, maf, c_f, s, t, st, en, mid;
int que[sz], vis[sz],h, r, p, pa[sz], med[sz], k;
struct node
{
    int f,s,v;
}con[sz];

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
        FOR(i,1,n)
        {
           //if(p==0&&i==6) cout<<NL<<mat[p][i]<<NL;
           if(mid>=mat[p][i]&&mat[p][i]>0&&vis[i]==0&&med[p]>=mat[p][i])
           {
               ///cout<<i<<' ';
               if(mat[p][i]!=1)med[i]=mat[p][i];
               else med[i]=med[p];
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

        a=pa[t]; b=t; c=1;
        while(true)
        {
            //cout<<a<<' '<<b<<NL;
            mat[a][b]-=c;
            mat[b][a]+=c;
            if(a==s) break;

            a=pa[a]; b=pa[b];
        }
       /// cout<<NL<<NL;
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
        if(c==0||maf>=k) break;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;
    int tt;
    cin>>tt;
    FOR(tc,1,tt)
    {
        int i, j, a, b, c, d, ans;

        cin>>n>>m;

        n++;
        s=0; t=n;
        FOR(i,0,300) FOR(j,0,300) org[i][j]=mod;
        FOR(i,1,n-1) org[i][i+n]=1;/// cout<<i<<'k'<<i+n<<NL;
        ///cout<<NL;
        FOR(i,0,m-1)
        {
            cin>>a>>b>>c;/// for directional graph
            c++;
            if(min(a,b)==0&&max(a,b)==n)
            {
                org[0][n]=1;
                continue;
            }
            if(a==0)org[0][b]=min(c,org[0][b]);///, cout<<0<<'k'<<b<<' '<<c<<NL;
            else if(a!=n&&b!=0)org[a+n][b]=min(c,org[a+n][b]);///, cout<<a+n<<'k'<<b<<' '<<c<<NL;

            if(b==0)org[b][a]=min(c,org[b][a]);/// cout<<0<<'k'<<a<<' '<<c<<NL;
            else if(b!=n&&a!=0)org[b+n][a]=min(c,org[b+n][a]);/// cout<<b+n<<'k'<<a<<' '<<c<<NL;
            ///cout<<NL;
        }
//        FOR(i,0,2*n)
//        {
//            FOR(j,0,2*n)
//              {
//                 if(org[i][j]==mod) org[i][j]=0;
//                 cout<<org[i][j]<<' ';
//
//              }
//              cout<<NL;
//        }
        //cout<<'k'<<org[0][6]<<NL;
        ///cout<<NL<<NL;
        cin>>k;


        st=2; en=100010; ans=mod; n*=2;
        while(st<=en)
        {
            mid=(st+en)/2;
            //mid=13;
            FOR(i,0,n)
            {
                FOR(j,0,n) mat[i][j]=org[i][j];
               /// FOR(j,0,n) cout<<mat[i][j]<<' ';
               /// cout<<NL;
            }
            ///cout<<NL<<mid<<NL;
            solve();
            ///cout<<maf<<NL<<NL;
            if(maf>=k) en=mid-1, ans=min(ans,mid-1);
            else st=mid+1;
        }
        if(ans==mod) cout<<"Case "<<tc<<": no solution"<<NL;
        else  cout<<"Case "<<tc<<": "<<ans<<NL;
    }

    return 0;
}
