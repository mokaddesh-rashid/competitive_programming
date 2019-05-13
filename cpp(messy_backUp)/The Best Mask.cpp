#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for( i=j;i<=k;i++)
#define REV(i,j,k) for( i=j;i>=k;i--)
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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz], rwn, mal, n, i;

int chk(int v)
{
    int a,j,b;
    FOR(j,0,n-1)
    {
       b=v&ar[j];
       if(b==0) return 0;
    }
    return 1;
}
int main()
{
    FOR(i,0,30) mal |= (1<<i);

    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,m,a,b,c,z;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,30)
    {
        rwn|=(1<<i);
        if(chk(rwn)) break;
    }
    REV(j,i,0)
    {
        x=mal; y=0; y=(1<<j);
        z=x^y; z=rwn&z;

        if(chk(z)) rwn=z;

    }
    cout<<rwn;
    return 0;
}
