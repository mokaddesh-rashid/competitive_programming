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
#define sz 101*101
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
int org[sz][20], mat[sz][20], go[sz][20], n, m, maf, c_f, s, t, id[110][110], ase[sz], nh, nr,ct;
int que[sz], vis[sz],h, r, p, pa[sz], med[sz], row, col;

int bfs(int s)
{
    ///check max value
    int x, y, z;

    while(h!=r)
    {
        p=que[h]; h++; vis[p]=1;
        ///cout<<p<<" = ";
        FOR(i,1,mat[p][0])
        {
           x=go[p][i];
           ///cout<<x<<' ';
           if(mat[p][i]>0&&vis[x]==0)
           {
               med[x]=min(med[p],mat[p][i]);
               pa[x]=p; vis[x]=1; que[r]=x; r++;
           }

        }
        ///cout<<NL;
        if(p==t) break;
    }

    if(vis[t]==0) return 0;
    else
    {
        int a,b,c,l=100;

        a=pa[t]; b=t; c=1;
        ///cout<<'k'<<c<<NL;
        while(true)
        {
            ///cout<<a<<' '<<b<<NL<<ct<<NL;
            FOR(i,1,mat[a][0])
            {
                x=go[a][i];
                if(x==b) mat[a][i]-=c;
            }
            FOR(i,1,mat[b][0])
            {
                x=go[b][i]; ///handle * shit
                if(x==a) mat[b][i]+=c;
            }
            //mat[a][b]-=c;
            //mat[b][a]+=c;
            if(ase[a]==1) break;

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
        mem(vis,0);
        FOR(i,0,sz) med[i]=mod;
        ct++;
        h=nh; r=nr;
        int c=bfs(s);
        maf+=c;
        if(c==0) break;
    }
    return;
}

string str[sz];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0); mem(org,0);
        int i, j, a, b, c=1, d, x, y, z, cnt=0;

        cin>>n>>m; d=n*m; d++;
        row=n; col=m;
        FOR(i,0,n-1) cin>>str[i];

        FOR(i,0,n-1)
        FOR(j,0,m-1) id[i][j]=c, c++;

        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                a=id[i][j]; b=a+d;
                ///cout<<a<<" k "<<b<<NL;
                c=mat[a][0]=mat[a][0]+1;
                mat[a][c]=1;
                go[a][c]=b;

//                b=id[i][j]; a=a+d;
////               cout<<a<<" k "<<b<<NL;
//                c=mat[a][0]=mat[a][0]+1;
//                mat[a][c]=0;
//                go[a][c]=b;
            }
        }


        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                FOR(k,0,3)
                {
                    x=i+fx[k]; y=j+fy[k];
                    if(valid(x,y)&&str[x][y]!='*')
                    {
                        a=id[i][j]+d; b=id[x][y];
                        ///cout<<a<<" l "<<b<<NL;
                        c=mat[a][0]=mat[a][0]+1;
                        mat[a][c]=1;
                        go[a][c]=b;

////                        b=id[i][j]+d; a=id[x][y];
////                        /cout<<a<<" l "<<b<<NL;
////                        c=mat[a][0]=mat[a][0]+1;
////                        mat[a][c]=0;
////                        go[a][c]=b;
                    }
                }
            }
        }

        mem(vis,0);
        h=r=0;

        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(str[i][j]=='.')
                    {
                        a=id[i][j]+d; b=d;
                        ///cout<<a<<'l'<<b<<NL;
                        c=mat[a][0]=mat[a][0]+1;
                        mat[a][c]=1;
                        go[a][c]=b;
                    }
                }
                else if(str[i][j]=='*')
                {
                    ///cout<<'k'<<i<<' '<<j<<NL;
                    cnt++;
                    a=id[i][j]; ase[a]=1;
                    que[r]=a; r++;
                    med[a]=mod;
                }
            }
        }

        nh=h; nr=r;
        t=d;
        ///cout<<d<<NL;
        cout<<"Case "<<tt<<": ";
        solve();
        if(maf>=cnt) cout<<"yes"<<NL;
        else cout<<"no"<<NL;
        ///cout<<maf<<' '<<cnt<<NL;
    }

    return 0;
}

