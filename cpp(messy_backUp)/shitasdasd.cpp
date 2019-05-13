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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    int l,r,p;
};

class compare
{
    public:
    bool operator()(node f, node s)
    {
        if(f.l==s.l) return f.r<s.r;
        else return f.l<s.l;
    }
};

node ar[MAX];
int sfx[MAX][20];
string str;
void up()
{
    int n=str.size(),x=1,m;

    FOR(i,0,n-1) sfx[0][i]=str[i];

    FOR(j,1,19)
    {
        FOR(i,0,n-1)
        {
           ar[i].l=sfx[j-1][i];
           ar[i].r=-1;
           if(i+x<n) ar[i].r=sfx[j-1][i+x];
           ar[i].p=i;
        }
        sort(ar,ar+n,compare());
        m=0;
        FOR(i,0,n-1)
        {
            if(i>0)
            {
                if(!(ar[i].l==ar[i-1].l&&ar[i].r==ar[i-1].r)) m++;
            }
            sfx[j][ar[i].p]=m;
        }
        x*=2;
    }

}

int lcp(int f,int s,int t)
{
    int n=str.size(), x=1<<t;

    if(t==-1) return 0;

    if(max(f+x,s+x)<=n&&sfx[t][f]==sfx[t][s])
        return (1<<t)+lcp(f+(1<<t), s+(1<<t), t);
    else return lcp(f,s,t-1);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,x,a,b;

    cin>>str; n=str.size();
    up();
    FOR(i,0,n-1) cout<<ar[i].p<<NL;


    return 0;
}

