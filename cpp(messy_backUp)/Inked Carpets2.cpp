#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

LL l,n,m,d;
int col[55], nx[1010];
pr dp[1010][55][5];
struct node
{
    int s, e, p, c;
    node()
    {
        s=e=0;
    }
}ar[1010];

class Compare
{
public:
    bool operator()(node x, node y)
    {
        return x.s<y.s;
    }
};

pr em;
pr rec(int x, int y, int z)
{
    pr temp, ret;
    temp.F=maxx; temp.S=maxx;

    if(ar[x].s==l+1||x>n) return em;
    if(dp[x][y][z].F!=-1&&dp[x][y][z].S!=-1) return dp[x][y][z];
    LL e,i,j,a,b,c,r;
    if(x==0)e=ar[x+1].s-ar[x].s-1;
    else e=ar[x+1].s-ar[x].s;
    FOR(i,1,m)
    {
       ret=rec(x+1,i,0);
       if(i!=y) ret.S+=1;
       ret.F += (e*col[i]);
       temp=min(temp,ret);

    }

    if(x!=0)
    {
        FOR(i,x,n)
        {
           if(ar[x].s!=ar[i].s) break;
           a=upper_bound(nx+1,nx+n+2,ar[i].e)-nx;
           b=ar[a].s; c=ar[a].s-ar[i].e-1;
           if(c==0)
           {
               if(ar[i].c==y) ret=rec(a,ar[i].c,min(2,z+1));
               else ret=rec(a,ar[i].c,1);

               if(ar[i].c==y&&z==2) ret.F+=max((LL)0,ar[i].p-d);
               else ret.F+=ar[i].p;
               if(ar[i].c!=y) ret.S+=1;
               temp=min(temp,ret);
           }
           else
           {
               FOR(j,1,m)
               {
                   ret=rec(a,j,0);
                   if(ar[i].c==y&&z==2) ret.F+=max((LL)0,ar[i].p-d);
                   else ret.F+=ar[i].p;
                   if(ar[i].c!=y) ret.S+=1;
                   r=c*col[j]; ret.F+=r;
                   if(ar[i].c!=j) ret.S+=1;
                   //cout<<x<<' '<<ret.F<<endl;
                   temp=min(temp,ret);
                   //cout<<temp.F<<' '<<temp.S<<NL;
               }
           }
        }
    }
    return dp[x][y][z]=temp;
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
        mem(dp,-1);
        LL i, j, x, y;
        cin>>l>>n>>m>>d;
        FOR(i,1,m) cin>>col[i];
        FOR(i,1,n) cin>>ar[i].s>>ar[i].e>>ar[i].c>>ar[i].p;
        sort(ar+1,ar+n+1, Compare());
        ar[n+1].s=l+1; ar[n+1].e=l+1;
        FOR(i,1,n+1) nx[i]=ar[i].s;
        pr ret;
        ret=rec(0,0,0);
        cout<<"Case "<<tt<<": "<<ret.F<<' '<<ret.S-1<<NL;
    }
    return 0;
}


