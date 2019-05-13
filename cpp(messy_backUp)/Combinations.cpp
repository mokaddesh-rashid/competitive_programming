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
#define sz 110
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    while(true)
    {
        mem(ar,0);
        LL i,j,x,y,n,m,p;
        cin>>n>>m;
        if(n==m&&n==0) break;
        FOR(i,2,n)
        {
            p=i;
            FOR(j,2,i)
            {
                while(p>0&&p%j==0)
                {
                    ar[j]++;
                    p/=j;
                }
            }
        }

        FOR(i,2,m)
        {
            p=i;
            FOR(j,2,i)
            {
                while(p>0&&p%j==0)
                {
                    ar[j]--;
                    p/=j;
                }
            }
        }

        x=n-m;
        FOR(i,2,x)
        {
            p=i;
            FOR(j,2,i)
            {
                while(p>0&&p%j==0)
                {
                    ar[j]--;
                    p/=j;
                }
            }
        }

        x=1;
        FOR(i,2,100)
        {
            FOR(j,0,ar[i]-1)
            {
                x*=i;
            }
        }
        cout<<n<<" things taken "<<m<<" at a time is "<<x<<" exactly.\n";
    }
    return 0;
}


