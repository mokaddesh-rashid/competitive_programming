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
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[8][8][8][8][5][8][5][8][8][2];

int rec(int f,int s,int t,int w,int Fcol,int Fcnt,int Ccol,int Ccnt,int Lcnt,int v)
{
    ///cout<<Lcnt<<' '<<Fcol<<' '<<Fcnt<<' '<<v<<NL;
    if(Ccnt>3||f<0||s<0||t<0||w<0)return 0;

    if(f==0&&s==0&&t==0&&w==0&&Fcol!=Ccol&&Fcnt!=Ccnt&&Ccnt!=Lcnt)return v;
    if(f==0&&s==0&&t==0&&w==0)return 0;

    if(dp[f][s][t][w][Fcol][Fcnt][Ccol][Ccnt][Lcnt][v]!=-1) return dp[f][s][t][w][Fcol][Fcnt][Ccol][Ccnt][Lcnt][v];

    int temp=0,a,b,c,d,e;
    FOR(i,0,3)
    {
        a=f;b=s;c=t;d=w;
        if(i==0)a-=1; if(i==1)b-=1;
        if(i==2)c-=1; if(i==3)d-=1;

        if(Lcnt==0)
        {
            if(Fcol==i) temp+=rec(a,b,c,d,Fcol,Fcnt+1,Ccol,Ccnt+1,Lcnt,v);
            else temp+=rec(a,b,c,d,Fcol,Fcnt,i,1,Ccnt,v);
        }
        else
        {
            if(Ccol==i) temp+=rec(a,b,c,d,Fcol,Fcnt,Ccol,Ccnt+1,Lcnt,v);
            else
            {
                 e=v;
                 if(Ccnt==Lcnt)e=0;
                 temp+=rec(a,b,c,d,Fcol,Fcnt,i,1,Ccnt,e);
            }
        }
    }
    return dp[f][s][t][w][Fcol][Fcnt][Ccol][Ccnt][Lcnt][v]=temp;

}

int ar[5];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,n,m,a,b,cnt=0,x,z=0;

        cin>>n;
        FOR(i,0,3)
        {
           if(i<n)cin>>ar[i];
           else ar[i]=0;
        }
        sort(ar,ar+4,greater<int>());
        n=0;
        while(n<4)
        {
            if(ar[n]!=0)n++;
            else break;
        }

        z+=rec(ar[0]-1,ar[1],ar[2],ar[3],0,1,0,1,0,1);
        z+=rec(ar[0],ar[1]-1,ar[2],ar[3],1,1,1,1,0,1);
        z+=rec(ar[0],ar[1],ar[2]-1,ar[3],2,1,2,1,0,1);
        z+=rec(ar[0],ar[1],ar[2],ar[3]-1,3,1,3,1,0,1);

        if((n==1&&ar[0]<=3)||n==0)z=1;
        cout<<z<<NL;
    }

    return 0;
}



