#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;


LL ar[100010], vis[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y = 0, n, m, c = 0, z, a, b, d, p;

    cin >> n >> m ;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
        y += ar[i];
         if( i > 0 )
        {

            a = ar[i]*ar[i-1];
            //cout << a << ' ' << ar[i] << ' ' << ar[i-1] << endl;
            x += a;
        }

    }
    x += (ar[0]*ar[n-1]);
    //cout << x << endl << endl;

    z = y;
    for( i=0; i<m; i++ )
    {
        cin >> p;
        p--;
        a = 0;
       if( vis[p] == 0 )
       {

        if( p == 0 )
            {
                if( vis[p+1] == 1 )
                    a -= ar[p+1];
                if( vis[n-1] == 1 )
                    a -= ar[n-1];
                a += (ar[p]+ar[p+1]+ar[n-1]);
            }
        else if( p == n-1 )
            {
                if( vis[0] == 1 )
                    a -= ar[0];
                if( vis[p-1] == 1 )
                    a -= ar[p-1];
                //cout << a << endl << endl;
                a += (ar[p]+ar[0]+ar[p-1]);
            }
        else
            {
                if( vis[p+1] == 1 )
                    a -= ar[p+1];
                if( vis[p-1] == 1 )
                    a -= ar[p-1];
                a += (ar[p]+ar[p+1]+ar[p-1]);
            }
        //cout << endl << a << ' ';
        a = y-a;
        //cout << a << endl;
        a = a*ar[p];
        y -= ar[p];
       //cout << a << endl;
        x += a;
        vis[p] = 1;

      }
    }

    cout << x ;

    return 0;

}


