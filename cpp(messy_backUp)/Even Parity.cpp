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
#define MAX 16
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int con[MAX][MAX],n,top[MAX][MAX],amr[MAX][MAX],row,col;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

int sum(int x,int y)
{
    int a,b,c=0;
    FOR(i,0,3)
    {
        a=x+fx[i]; b=y+fy[i];
        if(valid(a,b))c+=top[a][b];
    }
    return c%2;
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
        int i,j,a,c=mod;

        cin>>n;row=col=n;
        FOR(i,0,n-1)
        FOR(j,0,n-1)cin>>con[i][j];

        FOR(i,0,(1<<n)-1)
        {
            mem(top,0);
            FOR(j,0,n-1)
            {
                if(i&(1<<j))top[0][j]=1;
                else top[0][j]=0;
            }

            FOR(j,1,n-1)
                FOR(k,0,n-1)
                    {
                        ///if(top[0][0]==0&&top[0][1]==1&&top[0][2]==0)cout<<j<<' '<<k<<' '<<sum(i,j)<<NL;
                        if(sum(j-1,k))top[j][k]=1;
                    }
            a=0;
            FOR(j,0,n-1)
            {
                FOR(k,0,n-1)//cout<<top[j][k]<<' ';
                {
                    if(sum(j,k))a=mod;
                    if(con[j][k]==1&&top[j][k]==0)a=mod;
                    else if(con[j][k]!=top[j][k])a++;
                }
                //cout<<NL;
            }
            c=min(a,c);
            //cout<<NL;

        }

        if(c==mod)c=-1;
        cout<<"Case "<<tt<<": "<<c<<NL;
    }

    return 0;
}

