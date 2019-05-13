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

LL ar[100], in[100010], n;

int cal( int x )
{
    LL a, b, c, t = 0, i, j, y, l, u;
    for( i=0; i<32; i++ )
    {
        c = 0;
        if( ar[i] > in[x] )
        {
            a = ar[i]-in[x];
            l = lower_bound( in, in+n, a ) - in;
            u = upper_bound( in, in+n, a ) - in;
            if( in[l] == a )
            {
                c = u-l;
                if( a == in[x] )
                    c--;
                t += c;
                //cout << in[x] << ' ' << a << ' ' << c << endl;
            }

        }
    }
    return t;
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 2, y, m = 0;

    //cin >> n >> m ;

    for( i=0; i<32; i++ )
    {
        ar[i] = x;
        x *= 2;
    }

    cin >> n;

    for( i=0; i<n; i++ )
        cin >> in[i];

    sort( in, in+n );

    for( i=0; i<n; i++ )
    {
        m += cal(i);
    }

    cout << m/2;

    return 0;

}


