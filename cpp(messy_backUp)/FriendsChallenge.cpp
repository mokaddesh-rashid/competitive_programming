#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;


//set<int>::iterator ii;

LL ar[10000010];

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t;

    //cin >> t;
    sf(t);

    while(t--)
    {
        LL i, j, x, y, n, m, s, a, b, c = 0;

        s = 0;

        //cin >> n;
        sf(n);
        for( i=0; i<n; i++ )
        {
            sf(ar[i]);
            //cin >> ar[i];
            s += ar[i];
            if( s > maxx ) c = 1;
        }

        sf(m);
        //cin >> m;

        i = 0;
        j = n-1;

        if( m > s && c == 1 ) pf("BING\n");

        else
        {
            x = s = 0;
            while( s < m && i <= j )
            {
                //cout << i << ' ' << j << endl;
                if( x%2 == 0 )
                    s += ar[i], i++;
                else s += ar[j], j--;
                x++;
            }
            //cout << s << endl;
            if( s != m ) pf("BING\n");
            else
            {
                 x = i =  s = 0;
                 j = n-1;
                while( s < m )
                {
                    if( x%2 == 0 )
                        s += ar[i], pf("%lld ",i+1), i++;
                    else s += ar[j],pf("%lld ",j+1), j--;
                    x++;
                }
                pf("\n");
            }
        }

    }
    return 0;

}
