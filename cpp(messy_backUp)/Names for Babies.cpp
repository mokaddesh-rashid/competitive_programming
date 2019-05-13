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


struct info
{
    int p, x, y;
}sfx[100010];


bool compare(info f, info s)
{
    if( f.x != s.x ) return f.x<s.x;
    else return f.y<s.y;
}


string str;
int sfx_t[22][100001], n, m, r, l;


void call_sort()
{
    for(int i = 0; i<n; i++ )
    {
        sfx[i].x = sfx_t[r-1][i];
        sfx[i].y = -1;
        if( i+l < n )
            sfx[i].y = sfx_t[r-1][i+l];
        sfx[i].p = i;
    }
    sort( sfx, sfx+n, compare );
    int v = 0;
    for(int i=0; i<n; i++ )
    {
        if( i > 0 && (sfx[i].x != sfx[i-1].x || sfx[i].y != sfx[i-1].y ) )
            v++;
        sfx_t[r][sfx[i].p] = v;
    }

}

int lcp( int x , int y )
{
    int l = 0, p = 0;

    while( sfx_t[p][x] == sfx_t[p][y] )
    {
        if( l == 0 )  l = 1;
        else   l *= 2;
        p++;
    }

    if( l > 0 && y+l < n && x+l < n )
           return l + lcp( x+l, y+l );

    return l;


}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        int i, j, p, q, x, y, z, a, b, c, k, ex = 0;

        string str;

        cin >> str;
        cin >> p >> q;

        n = str.size();

        for( i=0; i<n; i++ )
            sfx_t[0][i] = str[i]-97;

        m = log(n)/log(2);
        m++;
        r = 1;
        l = 1;
        while( r <= m )
        {
            call_sort();
            l *= 2;
            r++;
        }
        p--;

        for( i=0; i<n-1; i++ )
        {
            int x = sfx[i].p, y = sfx[i+1].p;
            z = lcp( x, y );
            z = max( z, p );
            cout << z << ' ' << sfx[i].p << endl;
            k = min( n, q+sfx[i].p ) - (sfx[i].p+z);
            ex += max(k,0);


        }
       // cout << q << ' ' << sfx[i].p+p << endl;
        ex += max( 0, min( n, q+sfx[i].p ) - (sfx[i].p+p ));
        cout << "Case " << ca++ << ": " << ex << endl;

    }

    return 0;

}




