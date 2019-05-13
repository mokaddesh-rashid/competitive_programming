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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str,ans;
int dp[1010][1010][5][5],n,k,ck;

int rec(int x,int y,int z,int t)
{
    //cout<<y<<NL;
    if(x==n&&y==k) return 1;
    if(x==n||y==k) return 0;
    if(dp[x][y][z][t]!=-1) return dp[x][y][z][t];
    int temp=0,a,b,c;
    if(str[x]=='?')
    {
       if(t==0)
       {
          temp=max(temp,rec(x+1,y+1,0,t));
          temp=max(temp,rec(x+1,y,1,t));

          a=t;
          if(y-1<0) a=1;
          temp=max(temp,rec(x+1,abs(y-1),2,a));
       }
       if(t==1)
       {
          temp=max(temp,rec(x+1,y+1,2,t));
          temp=max(temp,rec(x+1,y,1,t));

          a=t;
          if(y-1<0) a=0;
          temp=max(temp,rec(x+1,abs(y-1),0,a));
       }
    }
    else if(str[x]=='W')
    {
        if(t==0)
       {
          temp=max(temp,rec(x+1,y+1,0,t));
       }
       if(t==1)
       {
          a=t;
          if(y-1<0) a=0;
          temp=max(temp,rec(x+1,abs(y-1),0,a));
       }
    }
    else if(str[x]=='D') temp=max(temp,rec(x+1,y,1,t));
    else
    {
        if(t==0)
       {
          a=t;
          if(y-1<0) a=1;
          temp=max(temp,rec(x+1,abs(y-1),2,a));
       }
       if(t==1)
       {
          temp=max(temp,rec(x+1,y+1,2,t));
       }
    }
    return dp[x][y][z][t]=temp;

}

void prin(int x,int y,int z,int t)
{
    //if(x<n&&y>=k) cout<<x<<' '<<y<<' '<<z<<' '<<t;
    if(x==n&&y==k) return;
    int temp=0,a,b,c;
    if(str[x]=='?')
    {
       if(t==0)
       {
          if(rec(x+1,y+1,0,t))
          {
              ans+='W';//cout<<'W';
              prin(x+1,y+1,0,t);
              return;
          }
          if(rec(x+1,y,1,t))
          {
              ans+='D';//cout<<'D';
              prin(x+1,y,1,t);
              return;
          }
          a=t;
          if(y-1<0) a=1;
          if(rec(x+1,abs(y-1),2,a))
          {
              ans+='L';//cout<<'L';
              prin(x+1,abs(y-1),2,a);
              return;
          }
       }
       if(t==1)
       {
          if(rec(x+1,y+1,2,t))
          {
              ans+='L';//cout<<'L';
              prin(x+1,y+1,2,t);
              return;
          }
          if(rec(x+1,y,1,t))
          {
              ans+='D';//cout<<'D';
              prin(x+1,y,1,t);
              return;
          }

          a=t;
          if(y-1<0) a=0;
          if(rec(x+1,abs(y-1),0,a))
          {
              ans+='W';//cout<<'W';
              prin(x+1,abs(y-1),0,a);
              return;
          }
       }
    }
    else if(str[x]=='W')
    {
        ans+='W';//cout<<'W';
        if(t==0)
       {
          prin(x+1,y+1,0,t);
       }
       if(t==1)
       {
          a=t;
          if(y-1<0) a=0;
          prin(x+1,abs(y-1),0,a);
       }
    }
    else if(str[x]=='D')
    {
        ans+='D';//cout<<'D';
        prin(x+1,y,1,t);
    }
    else
    {
        ans+='L';//cout<<'L';
        if(t==0)
       {
          a=t;
          if(y-1<0) a=1;
          prin(x+1,abs(y-1),2,a);
       }
       if(t==1)
       {
          prin(x+1,y+1,2,t);
       }
    }
    return;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    ck=0; ans="";
    mem(dp,-1);
    int i,j,x,y,m,a=0,b=0;
    cin>>n>>k;
    cin>>str;
    x=rec(0,0,0,0);
    if(x==1)
    {
        prin(0,0,0,0);
        FOR(i,0,n-2)
        {
            if(ans[i]=='W') a++;
            else if(ans[i]=='L') a--;
            if(abs(a)>=k) cout<<i<<' ';
        }
        if(b==1) cout<<"FUCK";
        else cout<<ans;
    }
    else cout<<"NO";
    return 0;
}


