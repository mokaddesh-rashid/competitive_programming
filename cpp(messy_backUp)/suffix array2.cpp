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
    int p, x, y, s;
}sfx[100010];


bool compare(info f, info s)
{
    if( f.x != s.x ) return f.x<s.x;
    else return f.y<s.y;
}


string str;
int sfx_t[22][100001], n, m, r, l, pos[100010], cnt[100010];


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
        if( l == 0 ) l = 1;
        else l *= 2;
        p++;
    }

    if( l > 0 && y+l < n )  return l + lcp( x+l, y+l );

    return l;


}

void mergee()
{
    int i , j;
    string ss;
    i = j = n = 0;
    str = "";
    while( j < 3 )
    {
        cin >> ss;
        str += (ss+" ");
        n += ss.size();

        for( i; i<n; i++ )
            sfx_t[0][i] = str[i]-97, pos[i] = j;

        sfx_t[0][i] = -1*(j+1);
        i++, n++, j++;
    }
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
        memset( cnt, 0, sizeof(cnt) );
        LL i, j, a, b, c = 0, x , y, z;

        mergee();

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

        a = i =  j = 0;

        while( i < n || j < n )
        {
            if( a == 3 || j == n )
                {
                  x = pos[sfx[i].p];
                  if( cnt[x] == 1 ) a--;
                  cnt[x]--, i++;
                }
            else
                {
                   x = pos[sfx[j].p];
                   if( cnt[x] == 0 ) a++;
                   cnt[x]++, j++;
                }
            if( a == 3 )
                {
                    b = lcp( sfx[i].p , sfx[j-1].p ), c = max( c, b );
                    //cout << sfx[i].p << ' ' << sfx[j-1].p << ' ' << b << endl;
                }
        }
        cout << "Case " << ca++ << ": " << c << endl;
    }
    return 0;

}




