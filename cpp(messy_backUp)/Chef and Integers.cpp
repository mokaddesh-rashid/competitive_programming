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

set<int>shit;
set<int>::iterator it;
int v,ar[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m;
    LL a,b,c=0;

    cin>>n; v=0;
    FOR(i,0,n-1)
    {
        cin>>ar[i];
    }
    cin>>m;

    a=0;
    sort(ar,ar+n,greater<int>());

    FOR(i,0,n-1)
    {
        if(ar[i]<v)
        {
            x=n-i;
            cout<<v<<' '<<ar[i]<<' '<<x<<NL;
            if(x<=m)
            {
                a=v-ar[i];
                a=(a*m);
                c+=a;
                v=ar[i];
            }
            else
            {
                a=v-ar[i];
                c += a;
            }
            cout<<a<<NL;
        }
    }

    cout<<c<<NL;
    return 0;
}


