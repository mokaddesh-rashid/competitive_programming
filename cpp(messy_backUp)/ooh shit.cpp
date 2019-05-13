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
typedef pair<LL,LL> pr;

int n,m,p,mat[sz][sz], job[sz], vis[sz], ar[sz], br[sz];
int row,col;

bool bpm(int p)
{
    FOR(i,1,n*m)
        if(mat[p][i]!=0&&vis[i]==0&&job[i]==0)
        {
                job[i]=p; job[p]=i;
                return true;
        }

    FOR(i,1,n*m)
    {
        if(mat[p][i]!=0&&vis[i]==0)
        {
            vis[i]=1; vis[p]=1;
            if(bpm(job[i]))
            {
                job[i]=p; job[p]=i;
                return true;
            }
        }
    }

    return false;
}

string str[sz];
int id[sz][sz];
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    ///outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0); mem(job,0);
        int i,j,cnt=0,a,b,c=1,d, gol=0;

        cin>>n>>m; row=n; col=m;
        FOR(i,0,n-1) cin>>str[i];

        FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
            id[i][j]=c;
            c++;
            if(str[i][j]=='*') gol++;
        }

        FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
            if(str[i][j]=='*')
            {
                FOR(k,0,3)
                {
                    a=i+fx[k]; b=j+fy[k];
                    if(valid(a,b)&&str[a][b]=='*')
                    {
                       c=id[i][j]; d=id[a][b];
                       mat[c][d]=1;
                    }
                }
            }
        }

        FOR(i,0,n-1)
            FOR(j,0,m-1)
        {
            mem(vis,0);
            a=id[i][j];
            ///cout<<i<<' '<<j<<' '<<a<<' '<<job[a]<<NL;
            if(job[a]==0)
            {
                ///cout<<a<<NL;
                if(bpm(a)) cnt++;
                ///if(a==3) cout<<job[3]<<NL;
            }
        }
        ///FOR(i,1,n*m) cout<<i<<' '<<job[i]<<NL;
        cout<<"Case "<<tt<<": "<<gol-cnt<<NL;
    }
    ///FOR(i,1,m) cout<<i<<' '<<' '<<job[i]<<NL;
    return 0;
}
/*
2
5 8
oo**oooo
*oo*ooo*
******oo
*o*oo*oo
******oo
3 4
**oo
**oo
*oo*
*/



