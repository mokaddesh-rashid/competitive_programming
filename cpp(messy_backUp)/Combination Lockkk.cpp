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

    int i, j,  ar[11], br[11], x = 0, y, n, m, a, b, c, d,z;

    for( i=0; i<5; i++ )
        cin >> ar[i];
    for( i=0; i<5; i++ )
        cin >> br[i];

    for( i=0; i<5; i++ )
    {
        a = ar[i];
        b = br[i];

        y = a;
        d = c = 0;
        while( y != b )
        {
            c++;
            y++;
            if( y == 10 )
                y = 0;
        }
        y = a;
        while( y != b )
        {
            d++;
            y--;
            if( y == -1 )
                y = 9;
        }

        x += min( c, d );


    }

    cout << x;





    return 0;

}


