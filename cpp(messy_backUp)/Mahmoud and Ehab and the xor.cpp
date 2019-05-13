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
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int cnt[MAX];
int dp[300][300][10],n,m;

int rec(int x,int y,int z)
{
    if(z==0&&y==m)return 1;
    if(x==100||z==0)return 0;
    if(dp[x][y][z]!=-1) return dp[x][y][z];

    return dp[x][y][z]=max(rec(x+1,y,z),rec(x+1,y^x,z-1));

}

void prin(int x,int y,int z)
{
    if(z==0&&y==m)return;
    if(x==100||z==0)return;

    if(rec(x,y,z)==rec(x+1,y^x,z-1))
    {
        cout<<x<<' ';
        prin(x+1,y^x,z-1);
    }
    else prin(x+1,y,z);
    return;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x=0;
    FOR(i,1,MAX-1)
        {
            x=x^i;
            if(x==0)cnt[i+1]=1;
        }
    int a,b,c;

    cin>>n>>m;

    if(m>0)
    {
        cout<<"YES"<<NL;
        a=n%4;
        if(n%4==0)a=4;
        if(m<=10)
        {
            mem(dp,-1);
            if(rec(1,0,a));
            prin(1,0,a);
            n-=a;
        }
        else if(a==1)cout<<m<<' ',n--;
        else if(a==2)
        {
            m=m^(1<<0);
            cout<<1<<' '<<m<<' ';
            n-=2;
        }
        else if(a==3)
        {
            m=m^(1<<0); m=m^(1<<1);
            cout<<1<<' '<<2<<' '<<m<<' ';
            n-=3;
        }
        else if(a==4)
        {
            m=m^(1<<0); m=m^(1<<1); m=m^(1<<2);
            cout<<1<<' '<<2<<' '<<4<<' '<<m<<' ';
            n-=4;
        }
    }
    else
    {
        a=n%4;
        if(a==0)cout<<"YES"<<NL;
        if(a==1)
        {
            cout<<"YES"<<NL<<"0 ";
            n--;
        }
        else if(n==2)
        {
            cout<<"NO";
            return 0;
        }
        else if(a==2)
        {
            cout<<"YES"<<NL;
            cout<<"1 2 3 4 8 12 ";
            n-=6;
        }
        else if(a==3)
        {
            cout<<"YES"<<NL<<"1 2 3 ";
            n-=3;
        }
    }
    a=0;
    FOR(i,100010,MAX-1)
    {
        if(n<=0)break;
        a=max(a,cnt[i]);
        if(a==1)cout<<i<<' ', n--;
    }
    return 0;
}


