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

int ar[30011], ex[30000], org[300001], s[30000], e[30000];

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c = 0, p, t=0, q, v;

    //cin >> n;
    sf(n);

    m = sqrt(n);
    p = a = 0;

    for( i=0; i<n; i++ )
    {
        sf(ex[a]);
        //cin >> ex[a];
        org[i] = ex[a];
        a++;

        if( a == m || i == n-1 )
        {
            sort( ex, ex+a );
            s[t] = p;
            for( j=0; j<a; j++,p++ )
            {
                //cout << ar[p] << ''
                ar[p] = ex[j];
            }
            e[t] = p-1;
            t++;
            a = 0;
        }
    }
    s[t] = n;
    e[t] = n;
    t++;
    sf(q);
    //cin >> q;
    int d;
    for( i=0; i<q; i++ )
    {
        sff(x,y);
        sf(v);
        //cin >> x >> y >> v;
        x--;
        y--;
        c = 0;
        p = lower_bound( s, s+t, x ) - s;
        a = p;
        if( s[p] > y )
            p = y+1;
        else
            p = s[p];
       // cout << p+1 << endl;
        while( e[a] <= y && a < t)
        {
            b = upper_bound( ar+s[a], ar+e[a]+1, v ) - ar;
            d = e[a]-b+1;
            c += d;
            //cout << b  << ' ' << c << endl;
            a++;
        }

        if( a == t )
            a = n;
        else
            a = s[a];
        //cout << a+1 << endl;
        while( a <= y )
        {
            if( org[a] > v )
                c++;
            a++;
        }
        //a = s[p]-1;
        //cout << a << endl;
        while( p > x )
        {
            if( org[x] > v )
                c++;
            x++;
        }

        pf("%d\n",c);
        //cout << c << endl;

    }

    //x = lower_bound( ar+3, ar+5, 3 ) - ar;
    //cout << x << endl;
    //for( i=0; i<t; i++ )
      //  cout << s[i] << ' ' << e[i] << endl;




    return 0;

}


