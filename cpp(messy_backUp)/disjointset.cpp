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


//set<int>::iterator ii;

int pa[100001], mp[100001];

int fi_pa( int x )
{

    if( pa[x] == x )
        return x;
    else
       {
          pa[x] = fi_pa( pa[x] );
          return pa[x];
       }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b;

    cin >> n >> m;

    for( i=1; i<=n; i++ )
    {
        pa[i] = i;
    }

    for( i=0; i<m; i++ )
    {
        cin >> a >> b;

        x = fi_pa(a);
        y = fi_pa(b);

        if( x == y )
            cout << "they are connected\n";
        else
        {
            mp[b] = a;
            pa[y] = x;
        }
    }


    return 0;

}

