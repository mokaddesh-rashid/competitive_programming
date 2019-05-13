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
#define MAX sz*sz
#define sz 505
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
    string name;
}ar[sz];

int m_s(int x,int y)
{
    int a,b,c,d;

    a=x; b=y; c=0;
    while(a!=b)
    {
        if(a==9) a=0;
        else a++;
        c++;
    }
    d=c;

    a=x; b=y; d=0;
    while(a!=b)
    {
        if(a==0) a=9;
        else a--;
        d++;
    }
     return min(c,d);
}
int val(string s,string t)
{
    int a,b,c=0;
    FOR(i,0,3)
    {
        int x=s[i]-'0', y=t[i]-'0';
        ///cout<<x<<' '<<y<<' '<<m_s(x,y)<<NL;
        c+=m_s(x,y);
    }
    return c;
}

struct node
{
    int f, x, y;
};
int pa[MAX];
vector<int>mat[MAX],cost[MAX];
class compare
{
public:
    bool operator()(node x, node y)
    {
        if( x.f > y.f )
            return true;
        else
            return false;
    }
};

priority_queue<node,vector<node>, compare> p_q;

int f_pa( int x )
{
    if( pa[x] == x ) return x;
    else
    {
        pa[x] = f_pa(pa[x]);
        return pa[x];
    }
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
        int i,j,n,m,a,b,c,x,y,z,t,k=mod;

        cin>>n;
        ar[1].name="0000"; n++;
        FOR(i,2,n) cin>>ar[i].name;
        node nd;
        FOR(i,2,n) k=min(k,val(ar[1].name,ar[i].name));
        FOR(i,2,n)
        {
            FOR(j,2,n)
            {
                if(i!=j)
                {
                    ///cout<<i<<' '<<j<<' '<<val(ar[i].name,ar[j].name)<<NL;
                    nd.x=i; nd.y=j; nd.f=val(ar[i].name,ar[j].name);
                    p_q.push(nd);
                }
            }
        }
        FOR(i,0,n+5) pa[i]=i;
        t=0;
        while(!p_q.empty())
        {
            a = p_q.top().x;
            b = p_q.top().y;
            c = p_q.top().f;

            x = f_pa(a);
            y = f_pa(b);

            if( x != y )
            {
                pa[y] = x;
                t += c;
            }

            p_q.pop();
        }

        cout<<t+k<<NL;
    }


    return 0;
}


