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

struct node
{
    LL s,e,p,c;
};
struct ret
{
    LL co,ch;
    ret()
    {
        co=ch=0;
    }
};

class Compare
{
public:
    bool operator()(node x, node y)
    {
        return x.s<y.s;
    }
};

LL l, n, m, d, col[100], st[1010], mc;
node ar[1010];
ret dp[1010][55][5],blnk;

ret rec(LL x, LL y, LL z)
{
    //cout<<x<<' '<<y<<endl;
    LL i,j,a,b,c,q,r,t,ll;
    ret temp, chk;
    if(ar[x].s==l+1||x>n) return blnk;
    if(dp[x][y][z].co!=-1&&dp[x][y][z].ch!=-1) return dp[x][y][z];
    if(x==0)
    {
        FOR(j,1,m)
        {
            chk=rec(1,j,0);
            r=ar[1].s-1; r*=col[j];
            chk.co += r;

            if(temp.co==0) temp=chk;
            else if(temp.co>chk.co) temp=chk;
            else if(temp.co==chk.co&&temp.ch>chk.ch) temp=chk;
        }
    }
    else
    {
        FOR(i,x,n+1)
        {
            if(ar[x].s!=ar[i].s)
            {
                FOR(j,1,m)
                {
                    chk=rec(i,j,0);
                    r=ar[i].s-ar[x].s; r*=col[j];
                    chk.co += r;
                    if(y!=j&&y!=0) chk.ch+=1;
                    if(temp.co==0) temp=chk, ll=j;
                    else if(temp.co>chk.co) temp=chk, ll=j;
                    else if(temp.co==chk.co&&temp.ch>chk.ch) temp=chk, ll=j;
                }
                break;
            }
            if(i==n+1) a=n+1;
            else a=upper_bound(st+1,st+n+2,ar[i].e)-st;
            b=ar[a].s;
            c=b-ar[i].e-1;
            //cout<<b<<' '<<ar[i].e<<' '<<c<<endl;
            if(c==0)
            {
                if(y==ar[i].c)
                {
                    chk=rec(a,ar[i].c,min((LL)2,z+1));
                    if(z==2) chk.co += max(ar[i].p-d,(LL)0);
                    else chk.co += ar[i].p;
                }
                else
                {
                    chk=rec(a,ar[i].c,1);
                    chk.co += ar[i].p;
                    if(y!=0)chk.ch += 1;
                }
                //cout<<x<<'k'<<y<<' '<<ar[i].c<<' '<<chk.co<<' '<<chk.ch<<endl;
                if(temp.co==0) temp=chk;
                else if(temp.co>chk.co) temp=chk;
                else if(temp.co==chk.co&&temp.ch>chk.ch) temp=chk;
            }
            FOR(j,1,m)
            {
                chk=rec(a,j,0);
                q=c*col[j];
                if(z==2&&y==ar[i].c) q+=max(ar[i].p-d,(LL)0);
                else q+=ar[i].p;
                r=ar[a].s-ar[i].s; r*=col[j];
                //cout<<q<<' '<<r<<endl;
                if((q<r&&y!=ar[i].c&&ar[i].c!=j)&&y!=0) chk.ch+=2;
                else if((q<r&&y!=ar[i].c)&&y!=0) chk.ch+=1;
                else if(q<r&&y==0&&ar[i].c!=j) chk.ch+=1;
                else if((r<=q&&y!=j)&&y!=0) chk.ch+=1;
                else if((y!=j)&&y!=0) chk.ch+=1;

                q=min(q,r);
                chk.co += q;
                //cout<<x<<' '<<y<<' '<<chk.co<<' '<<chk.ch<<endl;
                if(temp.co==0) temp=chk;
                else if(temp.co>chk.co) temp=chk;
                else if(temp.co==chk.co&&temp.ch>chk.ch) temp=chk;
            }
        }
    }
    //cout<<x<<' '<<y<<' '<<temp.co<<' '<<temp.ch<<' '<<ll<<endl;
    return dp[x][y][z]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        mem(dp,-1); //mem(ar,0);
        ret ans;
        LL i, j, x, y;
        cin>>l>>n>>m>>d;
        FOR(i,1,m) cin>>col[i];
        FOR(i,1,n) cin>>ar[i].s>>ar[i].e>>ar[i].c>>ar[i].p;
        sort(ar+1,ar+n+1, Compare());
        ar[n+1].s=l+1; ar[n+1].e=l+1;

        FOR(i,0,n+1) st[i]=ar[i].s;
        if(ar[1].s==1) ans=rec(1,0,0);
        else ans=rec(0,0,0);
        cout<<"Case "<<t<<": "<<ans.co<<' '<<ans.ch<<NL;
    }
    return 0;
}


