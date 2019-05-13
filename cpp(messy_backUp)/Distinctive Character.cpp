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
#define MAX 3000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,k;
string str;
queue<int>moqa;
int vis[MAX],lev[MAX];

int dec(string str)
{
    int c=0, a=1;
    REV(i,k-1,0)
    {
        int x=str[i]-'0';
        c+=(x*a); a*=2;
    }
    return c;
}

string bin(int v)
{
    string ret="";
    char ch;
    int a,b,c;

    FOR(i,0,k-1)
    {
        a=v%2; ch=a+'0';
        ret=ch+ret;
        v/=2;
    }

    return ret;
}

void bfs()
{
    int p,x,y,z;
    string chk;

    while(!moqa.empty())
    {
        p=moqa.front(); moqa.pop();
        str=bin(p);

        FOR(i,0,k-1)
        {
            if(str[i]=='0')
            {
                str[i]='1';
                x=dec(str);
                str[i]='0';
            }
            else
            {
                str[i]='0';
                x=dec(str);
                str[i]='1';
            }
            if(vis[x]==0)
            {
                vis[x]=1;
                lev[x]=lev[p]+1;
                moqa.push(x);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,z=0;

    cin>>n>>k;
    FOR(i,0,n-1)
    {
        cin>>str;
        x=dec(str);
        moqa.push(x);
        lev[x]=1; vis[x]=1;

    }
    bfs();

    FOR(i,1,MAX) if(z<lev[i])x=i,z=lev[i];
    str=bin(x);
    cout<<str;
    return 0;
}


