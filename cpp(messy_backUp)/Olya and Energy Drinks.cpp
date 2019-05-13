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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str[MAX];
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

queue<pr>que;
int vis[MAX][MAX],lev,ko,row,col,go[MAX][MAX][5],uso[MAX][MAX];
pr des;

void bfs(int px,int py)
{
    que.push(MP(px,py));
    vis[px][py]=1;
    pr use;

    while(!que.empty())
    {
        use=que.front(); que.pop();
        if(des==use)return;
        FOR(i,0,3)
        {
            lev=vis[use.F][use.S];
            px=use.F; py=use.S;
            FOR(j,0,ko-1)
            {
                px=px+fx[i]; py=py+fy[i];
                if(valid(px,py)&&str[px][py]=='.'&&vis[px][py]==0)
                {
                    vis[px][py]=lev+1;
                    que.push(MP(px,py));
                }
                else if(go[px][py][i])break;
                else if(uso[px][py]==4)break;
                else if(valid(px,py)&&str[px][py]=='.') continue;
                else break;
                go[px][py][i]=1;
                uso[px][py]++;
            }
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,x,y,a,b;

    cin>>row>>col>>ko;
    FOR(i,0,row-1)cin>>str[i];
    cin>>x>>y>>a>>b;
    x--;y--;a--;b--;
    des.F=a;des.S=b;
    bfs(x,y);
    cout<<vis[a][b]-1<<NL;
    return 0;
}
