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


LL pos[12],neg[12];

int main()
{
    LL i,x=0,a,b,c=0,n;

    cin>>n;

    FOR(i,0,n-1)
    {
        cin>>a;
        if(a>0) pos[a]++;
        else if(a<0) neg[a*-1]++;
        else c++;
    }

    FOR(i,1,10)
    {
        if(pos[i]>0&&neg[i]>0)
        {
            a=pos[i]*neg[i];
            x+=a;
        }
    }

    if(c>1) x+=(c*(c-1))>>1;
    cout<<x<<NL;

}
