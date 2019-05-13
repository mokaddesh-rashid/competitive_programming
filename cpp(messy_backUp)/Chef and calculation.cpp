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
typedef pair<int,int> p_i;


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t;

    cin >> t;

    while( t-- )
    {
        int i, j, x, y, n, m = 0, a, b, c, z;
        int cnt[10];
        int ar[10000];

        cin >> n;

        for( i=0; i<n; i++ )
        {
            cin >> m;
            x = 0;
            y = 0;
            memset( cnt, 0, sizeof(cnt) );
            for( j=0; j<m; j++ )
            {
                cin >> a;
                cnt[a]++;
            }
            sort( cnt, cnt+7);
            x = y = z = 0;
            for( j=1; j<=3; j++ )
            {
                z = max( 0, cnt[j]-x );
                x += z;
                if( j == 1 )
                    z *= 4;
                else if( j == 2 )
                    z *= 2;

                m += z;
            }

            ar[i] = m;
        }
        int p;
        b = c = 0;
        for( i=0; i<n; i++ )
        {
            if( i == 0 || b < ar[i]  )
            {
                b = ar[i];
                c = 1;
                p = i;
            }
            else if( b == ar[i]  )
            {
                c++;
            }
        }

        if( c == 1 && p == 0 )
            cout << "chef\n";
        else if( c == 1 )
            cout << p+1 << endl;
        else
            cout << "tie\n";

    }

    return 0;

}


