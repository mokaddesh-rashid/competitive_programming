#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

LL ar[100010], vis[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL t;

    cin >> t;

    while( t-- )
    {
        memset( vis, 0, sizeof(vis) );
        memset( ar, 0, sizeof(ar) );
        LL i, j, x = 0, y = 1, n, m, z, a, b, c, k, l;

        cin >> n >> m >> k;

       for( i=0; i<k; i++, y++ )
       {
           ar[i] = y;
           x += y;

       }
       l = m;
       if( x > n )
        cout << -1;
       else
       {


           for( i=k-1; i>=0; i-- )
           {
               z = n-x;
               b = l-ar[i];
               //cout << z << ' ' << b << endl;
               if( z > b && x < n )
               {
                   b = l-ar[i];

                    ar[i] = l;
                    x += b;
                   l--;

               }
               else if( z <= b )
               {
                   b = ar[i]+z;
                       x += z;
                       ar[i] = b;

               }
           }

           if( x != n )
            cout << -1;

           else
            for( i=0; i<k; i++ )
                cout << ar[i] << ' ';
       }

       cout << endl;
    }

    return 0;

}


