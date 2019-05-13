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

string str;
int dp[sz][sz][2], ase[sz];

void up()
{
    ase['A']=1; ase['H']=1; ase['I']=1;
    ase['M']=1; ase['O']=1; ase['T']=1;
    ase['U']=1; ase['V']=1; ase['W']=1;
    ase['X']=1; ase['Y']=1;
}

int rec(int x,int y,int z)
{
    if(x>y) return 0;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    int temp=mod*-1;

    if(z==1)
    {
        int a=2;
        if(x==y) a=1;
        if(ase[str[x]]==1&&str[x]==str[y]) temp=a+rec(x+1,y-1,1);
        else temp=mod*-1;
    }
    else
    {
        int a=2;
        if(x==y) a=1;
        if(ase[str[x]]==1&&str[x]==str[y])
        {
            temp=a+rec(x+1,y-1,1);
        }
        temp=max(rec(x+1,y,0),temp);
        temp=max(rec(x,y-1,0),temp);
    }

    return dp[x][y][z]=temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    up();
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(dp,-1);
        int i,j,n,m;

        cin>>str;
        n=str.size();
        cout<<rec(0,n-1,0)<<NL;
    }

    return 0;
}


