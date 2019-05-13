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

int mat[100010][10];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b, c, l , r;

    x = y = a = b = 0;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> mat[i][0] >> mat[i][1];
        x += mat[i][0]; y += mat[i][1];
    }

    a = max( x-y, y-x );
    c = 0;

    for( i=0; i<n; i++ )
    {
        l = x; r = y;
        l -= mat[i][0]; r -= mat[i][1];
        l += mat[i][1]; r += mat[i][0];
        b = max( l-r, r-l );

        if( b > a )
        {
            a = b;
            c = i+1;
        }
    }

    cout << c << endl;

    return 0;

}


