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
typedef pair<int,int> pr;

struct node
{
    LL v, pa, low, lev;
}dfa[100010];

int stk[100010], top, ins[100010], ti, ck, n, m, love;
vector<int> mat[100010];
set<pr>ms;
set<pr>::iterator it;
int dg[100010];
int kat[100010];
class compare
{
  public:
      bool operator()(int x, int y)
      {
          return dg[x]<dg[y];
      }
};


void tarzan( int p )
{
    int i, j, y, sz;
    dfa[p].v = 1;
    dfa[p].low = dfa[p].lev = ++ti;
    ins[p] = 1;
    stk[++top] = p;
    sz=mat[p].size();
    FOR(i,0,sz-1) kat[i]=mat[p][i];
    if(love==0)sort( kat, kat+sz, compare());
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = kat[i], y, c=0;
        if(dfa[x].v == 0 && c==0)
        {
            dfa[x].pa=p;
            ms.insert(MK(p,x));
            tarzan(x);
            dfa[p].low = min( dfa[x].low, dfa[p].low );
            c=1;
            //cout << p << ' ' << x  << ' ' << dfa[x].low << ' ' << dfa[p].low << endl;

        }
        else if(ins[x]==1 && dfa[p].pa!=x)
        {
            int y=dfa[p].low;
            dfa[p].low = min( dfa[x].lev, dfa[p].low );
            if(y!=dfa[p].low)ms.insert(MK(p,x));
        }

    }

    if(dfa[p].low==dfa[p].lev )
    {
        int cnt=0;
        while( top > -1 )
        {
            y = stk[top];
            ins[y] = 0;
            top--;
            cnt++;
            //cout << y << ' ';
            if( y == p ) break;
        }
        if(cnt==n) ck=1;
       // cout<<endl;
    }

}
int ed[200010][3];
int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, a, b;

    ck = ti = 0;
    top = -1;
    cin >> n >> m;
    FOR(i,0,m-1)
    {
        cin >> x >> y;
        dg[x]++; dg[y]++;
        mat[x].push_back( y );
        mat[y].push_back( x );
        ed[i][0]=x; ed[i][1]=y;
    }
    tarzan(1);
    if(n==2&&m==2)ck=1;
    if(ck==0)
    {
        while(!ms.empty())
        {
            ms.erase(ms.begin());
        }
        love=1;
        tarzan(1);
    }
    if(ck==1)
    {
        cout<<"YES\n";
        FOR(i,0,m-1)
        {
            x=ed[i][0]; y=ed[i][1];
            pr lele=MK(x,y);
            it = ms.find(lele);
            lele=*it;
            a=lele.F; b=lele.S;
            if(a==x&&b==y) cout<<x<<' '<<y<<endl;
            //else if(dfa[x].lev<dfa[y].lev) cout<<x<<' '<<y<<endl;
            else cout<<y<<' '<<x<<endl;
        }
    }
    else cout<<"NO\n";
    return 0;

}




