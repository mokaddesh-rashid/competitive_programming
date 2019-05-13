#include <bits/stdc++.h>

using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
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

LL ar[100010], vis[100010], br[100010], n, m, cnt[100010];

int chk( int v )
{
    //cout << endl << v << endl;
    MEM( cnt, 0 );
    MEM( vis, 0 );
    int t, c, x, a, b, i;

    FOR( i, 0, v-1 )
    {
        if( ar[i] != 0 ) vis[ar[i]] = i;
    }
    t = c = 0;
    FOR( i, 0, v-1 )
    {
        if( vis[ar[i]] != i || cnt[ar[i]] == 1 || ar[i] == 0 ) c++;//, cout << i << ' ' << c << endl;
        else
        {
            x = br[ar[i]-1];
           // cout << i << ' ' << c << ' ' << x << endl;
            if( x <= c )
            {
                cnt[ar[i]] = 1;
                c -= x;
                t++;
            }
            else return 0;
        }
    }
    //cout << t << endl << endl;
    if( t == m ) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, st, en, mid, a = maxx, b;

    cin >> n >> m ;

    FOR( i, 0, n-1 ) cin >> ar[i];

    FOR( i, 0, m-1 ) cin >> br[i];

    st = 0; en = n;

    while( st <= en )
    {
        mid = ( st+en ) / 2;

        x = chk( mid );
        if( x == 1 ) a = min( a, mid ), en = mid-1;
        else st = mid+1;
    }

    if( a == maxx )  cout << -1 << endl;
    else cout << a << endl;

    return 0;

}


