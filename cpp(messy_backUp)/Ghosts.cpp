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
#define MAX 26
#define sz 26*26
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n, m, p, mat[sz][sz], job[sz], vis[sz], row, col, st, en, mid;
string str[MAX];


bool bpm(int p)
{
    FOR(i,1,n*n)
        if(mat[p][i]>0&&mat[p][i]<=mid&&vis[i]==0&&job[i]==0)
        {
                job[i]=p;
                return true;
        }

    FOR(i,1,n*n)
    {
        if(mat[p][i]>0&&mat[p][i]<=mid&&vis[i]==0)
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



///******creating graph part
int id[MAX][MAX], lev[MAX][MAX], visa[MAX][MAX], h, r, fr, to;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
pr shit[sz];

void assign_id(char ch)
{
   int c=0;
   FOR(i,0,n-1)
      FOR(j,0,n-1)
            if(str[i][j]==ch)
            {
                c++;
                id[i][j]=c;
                ///cout<<i<<' '<<j<<' '<<c<<NL;
            }
}

void bfs(int f,int s)
{
    mem(lev,0); mem(visa,0);
    h=r=0;
    int x,y;

    lev[f][s]=0;
    shit[r]=MK(f,s); r++;

    while(h!=r)
    {
        f=shit[h].F; s=shit[h].S;
        h++;

        FOR(i,0,3)
        {
            x=f+fx[i]; y=s+fy[i];
            if(valid(x,y)&&str[x][y]!='#'&&visa[x][y]==0)
            {
                lev[x][y]=lev[f][s]+1;
                visa[x][y]=1;

                    shit[r]=MK(x,y);
                    r++;

                if(str[x][y]=='H')
                {
                    to=id[x][y];
                    mat[fr][to]=lev[x][y];
                    ///cout<<fr<<' '<<to<<' '<<lev[x][y]<<NL;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(mat,0);
        int i,j,cnt=0,a,b,c=0;

        cin>>n; row=col=n;
        FOR(i,0,n-1) cin>>str[i];
        assign_id('H');
        assign_id('G');

        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                if(str[i][j]=='G')
                {
                    fr=id[i][j];
                    bfs(i,j);
                }
                if(str[i][j]=='H') c++;
            }
        }

        int x=10000000;
        st=0; en=sz;
        while(st<=en)
        {
            mid=(st+en)/2;
            mem(job,0); cnt=0;
            FOR(i,0,n-1)
            {
                FOR(j,0,n-1)
                {
                    if(str[i][j]=='G')
                    {
                        mem(vis,0);
                        if(bpm(id[i][j])) cnt++;
                    }
                }
            }
            ///cout<<mid<<' '<<cnt<<NL;
            if(cnt==c) en=mid-1, x=min(x,mid*2+2);
            else st=mid+1;
        }
        if(c==0) x=0;

        if(x==10000000) cout<<"Case "<<tt<<": "<<"Vuter Dol Kupokat"<<NL;
        else cout<<"Case "<<tt<<": "<<x<<NL;
    }
    return 0;
}


