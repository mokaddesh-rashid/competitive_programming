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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[MAX];
multiset<int>sot;
multiset<int>::iterator it;
int n,hi[MAX],d,gi[MAX],cnt[MAX];


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,a,b,c=0,x,y,z;

    cin>>n>>d;
    FOR(i,0,n-1)cin>>hi[i];
    FOR(i,0,n-1)cin>>gi[i];

    FOR(i,0,n-1)
    {
        a=d-hi[i];
        if(a<0) mat[0].PB(gi[i]);
        else if(a<MAX) a=a/gi[i],mat[a+1].PB(gi[i]);
    }

    a=n;
    FOR(i,0,n)
    {
        x=mat[i].size();
       // cout<<a<<' '<<x<<" = ";
        a-=x;a-=cnt[i];
        FOR(j,0,x-1) sot.insert((int)mat[i][j]);
        if(!sot.empty())
        {
            it=sot.begin();
            y=*it;
            y=d/y;
            y=y+i+1;
            if(y<MAX) cnt[y]++;
            sot.erase(it);
            a++;
        }
       /// cout<<a<<NL<<NL;
        c=max(a,c);
    }

    cout<<c<<NL;
    return 0;
}

