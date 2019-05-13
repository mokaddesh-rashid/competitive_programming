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

map<string,int>mopa;
map<int,string>bopa;
vector<int>mat[MAX];
int vis[MAX],n,root,kase,dude[MAX],pa[MAX],ole,po;
string str,chk;
queue<int>que;

int bfs(int p)
{
    mem(vis,0);
    que.push(p); vis[p]=1;
    kase=10000;

    int x,v=p;
    while(!que.empty())
    {
       p=que.front();  que.pop();
       FOR(i,0,(int)mat[p].size()-1)
       {
           x=mat[p][i];
           if(x==v)kase=min(kase,vis[p]);
           if(x==v&&vis[p]==ole)po=p;
           if(vis[x]==0)
           {
               que.push(x);
               vis[x]=vis[p]+1;
               pa[x]=p;
           }
       }
    }
}

void rec(int po,int p)
{
    if(po==p)
    {
        cout<<bopa[p]<<' ';
        return;
    }
    rec(pa[po],p);
    cout<<bopa[po]<<' ';
}
int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int i,j,m,a,b,c,x,y;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>str;
        mopa[str]=i+1;
        bopa[i+1]=str;
    }
    FOR(l,0,n-1)
    {
        cin>>str;
        x=mopa[str];
        cin>>m;
        cin.ignore();
        FOR(j,0,m-1)
        {
            getline(cin,str);
            c=str.size(); chk="";

            FOR(i,7,c-1)
            {

                chk=chk+str[i];
                if(i==c-1||str[i+1]==',')
                {
                    y=mopa[chk];
                    mat[x].PB(y);
                    chk="";
                    i+=2;
                }
            }
        }
    }

    a=c=-1;

    FOR(i,1,n)
    {
        bfs(i);
        if(c==-1&&kase!=10000)a=i,c=kase;
        else if(c>kase)a=i,c=kase;
    }
    if(a==-1)cout<<"SHIP IT"<<NL;
    else
    {
        ole=c;
        bfs(a);
        rec(po,a);
    }
    return 0;
}


