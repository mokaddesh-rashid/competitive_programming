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

int ar[MAX],br[MAX];
int main()
{
    ///ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    sf(tc);
    FOR(tt,1,tc)
    {
        int i,j,n,m,a,b,c,d,s,e;

        sf(n);
        FOR(i,0,n-1)sf(ar[i]),br[i]=ar[i];
        sort(ar,ar+n,greater<int>());

        a=(n-1)/2; c=0; s=0; e=n-1;
        if(n%2) b=a-1;
        else b=a+1;

        FOR(i,0,n-3)
        {
            if(i>1&&n%2)
            {
                if(i%2)a++;
                else b--;
            }
            else if(i>1)
            {
                if(i%2)a--;
                else b++;
            }

            if(i%2==0)
            {
               if(br[a]==ar[s])s++;
               else if(e>=0&&br[a]==ar[e])e--;
               else c=1;
            }
            else
            {
               if(br[b]==ar[s])s++;
               else if(e>=0&&br[b]==ar[e])e--;
               else c=1;
            }
        }


        if(c==0)pf("Case #%d: YES\n",tt);
        else pf("Case #%d: NO\n",tt);
    }

    return 0;
}

