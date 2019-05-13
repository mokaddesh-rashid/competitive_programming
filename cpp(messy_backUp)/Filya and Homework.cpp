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
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL ar[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, mn = maxx, mx = minn, md, a, b, c, z;

    cin >> n;

    for( i=0; i<n; i++ )
        cin >> ar[i], mn = min( mn, ar[i] ), mx = max( mx, ar[i] );
    md = (mn+mx) / 2;
    md--;
    md = max( md, (LL)0 );
    a = md;

    while( md < a+3 )
    {
        c = 0;
        for( i=0; i<n; i++ )
        {
            if( i == 0 )
                    y = max( md-ar[i], ar[i]-md );
            z = max( md-ar[i], ar[i]-md );
            if( z != y && ar[i] != md )
                c = 1;
        }
        if( c == 0 )
            x = 1;
        //cout << md << ' ' << c << endl;
        md++;
    }
    c = 0;
    for( i=0; i<n; i++ )
    {
        if(!( ar[i] == mx || ar[i] == mn ))
            c = 1;
    }
    if( c == 0 )
        x = 1;

    if( x == 1 )
        cout << "YES";
    else
        cout << "NO";

    return 0;

}

