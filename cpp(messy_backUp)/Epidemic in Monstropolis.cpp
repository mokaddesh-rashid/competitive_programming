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
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

struct node
{
    int v;
    char ch;
}info[100010];

LL ar[10000] ,sm[10000], cnt[1000];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, a, b, c = 0, d, e, l, r, p, cnt, de = 0, z , f = 0, s;
    cnt = 0;

    cin >> n;
    x = 0;

    for( i=0; i<n; i++ )
    {
       cin >> ar[i];
       f += ar[i];
       x += ar[i];
       sm[i] = x;
    }

    cin >> m;

    s = 0;
    x = 0;

    for( i=0; i<m; i++ )
    {
        //cout << x << endl;
        cin >> a;
        x += a;
        p = lower_bound( sm, sm+n, x ) - sm;
        if( sm[p] != x ) c = 1;
        a = 0;
        if( s == p )
        {
            s = p+1;
            continue;
        }
        for( j=s; j<=p; j++ )
        {
            //cout << a << ' ' << j <<  ' ' << ar[j] << ' ' << ar[j+1] << ' ' << ar[j-1] << endl;
             if( ar[j] > a  && j == s && ar[j+1] < ar[j] )
            {
                a = ar[j];
                e = j;
            }
            else if( ar[j] > a  && j == p && ar[j-1] < ar[j] )
            {
               // cout << j << endl;
                a = ar[j];
                e = j;
            }
            else if( j == p || j == s ) continue;
            else if( ar[j] > a  && ( ar[j-1] < ar[j] || ar[j+1] < ar[j] ) )
            {
                a = ar[j];
                e = j;
            }

        }
        //cout << e << endl;
        if( a == 0 ) c = 1;

        if( c == 0 )
        {
            if( e == p || ar[e] > ar[e-1]  )
            {
                //cout << e << endl;
                for( int l = e-1; l>=s; l-- )
                {
                    info[cnt].v = (l-s)+i+2;
                    info[cnt].ch = 'L';
                    cnt++; de++;
                }

                r = e+1;
                z = de;
                while( r <= p )
                {
                    info[cnt].v = (e+1)-z;
                    info[cnt].ch = 'R';
                    cnt++; de++;r++;
                }
            }
                else
                {
                    r = e+1;
                    z = de;
                    while( r <= p )
                    {
                        info[cnt].v = (e+1)-z;
                        info[cnt].ch = 'R';
                        cnt++; de++;r++;
                    }
                    for( int l = e-1; l>=s; l-- )
                    {
                        //cout << l << ' ' << i << endl;
                        info[cnt].v = (l-s)+i+2;
                        info[cnt].ch = 'L';
                        cnt++; de++;
                    }

                }
            }
        s = p+1;
    }

    if( c == 1 || f != x )
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for( i=0; i<cnt; i++ )
    {
        cout << info[i].v << ' ' << info[i].ch << endl;
    }
    return 0;

}


